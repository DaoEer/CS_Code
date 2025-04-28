// Fill out your copyright notice in the Description page of Project Settings.

#include "SpiralEffectEmitter.h"
// UE4
#include "Particles/ParticleSystemComponent.h"
// ��������
#include "GameData/EffectEmitterData.h"
#include "Util/CS3Debug.h"

DECLARE_CYCLE_STAT(TEXT("PrepareTheData"), STAT_PrepareTheData, STATGROUP_ASpiralEffectEmitter);
DECLARE_CYCLE_STAT(TEXT("Calculation"), STAT_Calculation, STATGROUP_ASpiralEffectEmitter);

CONTROL_COMPILE_OPTIMIZE_START

void ASpiralEffectEmitter::InitEmitterTransform()
{
	Super::InitEmitterTransform();
	
	//���û�ж�Ŀ������п�����Ϊ��BeginPlay()��ʱ��Ŀ��ʼ������Ч��
	//��ʼ��λ��������һЩ��Ч�Ķ�������
	if (FirstTarget == SecondTarget)
	{
		this->Stop();
	}
	else
	{
		GetParticleSystemComponent()->AddLocalRotation(FRotator(0, -90, 0));

		//��ʱ��ɣ�����Ŀ���ڳ�ʼ��֮��
		if (bIsFlyByTime)
		{
			FlySpeed = (GetFlyTargetPos() - GetActorLocation()).Size() / (EffectData->FlyData.FlyTime*2);
			CompletedTime = EffectData->FlyData.FlyTime*2;
		}
	}
}

void ASpiralEffectEmitter::PrepareTheData(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(STAT_PrepareTheData);

	UpdateRelInfo();
	UpdateTime(DeltaTime);
}

void ASpiralEffectEmitter::UpdateTime(float DeltaTime)
{
	CurrentTime += DeltaTime;
	if (bIsFlyByTime)
	{
		if (CompletedTime <= 0)
		{
			CompletedTime = EffectData->FlyData.FlyTime*2;
		}
		FlySpeed = (GetFlyTargetPos() - GetActorLocation()).Size() / (CompletedTime - CurrentTime);
	}
	else
	{
		CompletedTime = Distance / (FlySpeed/2);
	}

	Rate = CurrentTime / CompletedTime;

	if (Rate > 1)
	{
		Rate = 1.f;
	}
}

void ASpiralEffectEmitter::UpdateRelInfo()
{
	FVector Pos = GetFlyTargetPos() - SourcePos;

	RelPosX = Pos.X;
	RelPosY = Pos.Y;
	RelPosZ = Pos.Z;

	Distance = Pos.Size();

	RelRotZ	 = (180.f) / PI * FMath::Atan2(-RelPosX, RelPosY);
	RelRotXY = (180.f) / PI * FMath::Atan2(RelPosZ, sqrtf(RelPosX * RelPosX + RelPosY * RelPosY));
}

void ASpiralEffectEmitter::Calculation()
{
	SCOPE_CYCLE_COUNTER(STAT_Calculation);
	//�����´η��е�λ�ã����Ŀ�걻�����ˣ�����ô�����Ŀ������ǰ��λ��
	CalculationAngle();
	CalculationRadius();
	FVector Location = CalculationPosition();
	FRotator Rotation = CalculationRotation();

	//����λ��
	SetActorLocationAndRotation(Location, Rotation);
}

void ASpiralEffectEmitter::CalculationAngle()
{
	SpeedZ		 = -EffectData->SpiralData.DeltaAngleZ / CompletedTime;
	CurAngleZ	 = EffectData->SpiralData.DeltaAngleZ + RelRotZ - EffectData->SpiralData.DeltaAngleZ * Rate;
	BeginAngleXY = RelRotXY + EffectData->SpiralData.DeltaAngleXY;
	EndAngleXY	 = RelRotXY;
	SpeedXY		 = (EndAngleXY - BeginAngleXY) / CompletedTime;
	CurAngleXY	 = BeginAngleXY - (BeginAngleXY - EndAngleXY) * Rate;
}

void ASpiralEffectEmitter::CalculationRadius()
{
	EndRadius		 = Distance;
	RadiusSpeed		 = (EndRadius - BeginRadius) / CompletedTime;
	CurrentRadius	 = BeginRadius - (BeginRadius - EndRadius) * Rate;
}

FVector ASpiralEffectEmitter::CalculationPosition()
{
	RelOffset.X = FMath::Sin(PI / 180.f * CurAngleZ) * FMath::Cos(PI / 180.f * CurAngleXY) * -CurrentRadius;
	RelOffset.Y = FMath::Cos(PI / 180.f * CurAngleZ) * FMath::Cos(PI / 180.f * CurAngleXY) * CurrentRadius;
	RelOffset.Z = FMath::Sin(PI / 180.f * CurAngleXY) * CurrentRadius;

	return SourcePos + RelOffset;
}

FRotator ASpiralEffectEmitter::CalculationRotation()
{
	FVector Direction;

	float DAD = CurAngleZ * PI / 180.f;
	float DAC = SpeedZ * PI / 180.f;
	float DAH = CurAngleXY * PI / 180.f;
	float DAG = SpeedXY * PI / 180.f;

	Direction.X = -FMath::Cos(DAD) * DAC * FMath::Cos(DAH) * CurrentRadius +
		-FMath::Sin(DAD)* -FMath::Sin(DAH) * DAG * CurrentRadius +
		-FMath::Sin(DAD)*  FMath::Cos(DAH) * RadiusSpeed;

	Direction.Y = -FMath::Sin(DAD) * DAC * FMath::Cos(DAH) * CurrentRadius +
		FMath::Cos(DAD)* -FMath::Sin(DAH) * DAG * CurrentRadius +
		FMath::Cos(DAD)*  FMath::Cos(DAH) * RadiusSpeed;

	Direction.Z = FMath::Cos(DAH) * DAG * CurrentRadius + FMath::Sin(DAH) * RadiusSpeed;

	return FRotationMatrix::MakeFromX(Direction).Rotator();
}

void ASpiralEffectEmitter::Tick(float DeltaTime)
{
	if (bPlaying)
	{
		if (DeltaTime > 0.0167f)
		{
			int32 Count = FMath::TruncToInt(DeltaTime / 0.0167f);
			for (int32 i = 0; i < Count; i++)
			{
				PrepareTheData(0.0167f);
				Calculation();
			}

			PrepareTheData(DeltaTime - Count * 0.0167f);
			Calculation();
		}
		else
		{
			PrepareTheData(DeltaTime);
			Calculation();
		}

		if (FMath::IsNearlyEqual(Rate, 1.f))
		{
			OnEffectArrived.Broadcast();
			this->Stop();
			return;
		}
	}

	AEffectEmitter::Tick(DeltaTime);
}

CONTROL_COMPILE_OPTIMIZE_END
