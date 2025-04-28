// Fill out your copyright notice in the Description page of Project Settings.

#include "BeamEffectEmitter.h"
// UE4
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
// ��������
#include "Util/CS3Debug.h"
#include "GameData/EffectEmitterData.h"
// CS3����
#include "Actor/GameCharacter.h"
#include "Actor/GameCharacter.h"
#include "Component/PerformanceComponent.h"

DECLARE_CYCLE_STAT(TEXT("UpdateBeamCollisionList"), STAT_UpdateBeamCollisionList, STATGROUP_ABeamEffectEmitter);
DECLARE_CYCLE_STAT(TEXT("Move"), STAT_Move, STATGROUP_ABeamEffectEmitter);
DECLARE_CYCLE_STAT(TEXT("SetTargetTangent"), STAT_SetTargetTangent, STATGROUP_ABeamEffectEmitter);
DECLARE_CYCLE_STAT(TEXT("SetComponentTransform"), STAT_SetComponentTransform, STATGROUP_ABeamEffectEmitter);

CONTROL_COMPILE_OPTIMIZE_START

ABeamEffectEmitter::ABeamEffectEmitter()
{

}

void ABeamEffectEmitter::InitEmitterTransform()
{
	//��ʼ��һ�������յ�
	GetFlySourcePos(true);
	GetFlyTargetPos(true);

	///������ʼ��
	SetSourcePoint();
	//�����յ�
	SetTargetPoint();
	//�����������������
	SetBeamAttribute();
	//����������Ŀ���Ǳߵ�����
	SetTargetTangent();

	//����λ��
	FVector Scale3D = FirstTransform->bIsBind ? FirstTransform->Transform.GetScale3D() * FirstTarget->GetActorScale3D() : FirstTransform->Transform.GetScale3D();
	SetActorTransform(FTransform(FRotator(0.f), SourcePos, Scale3D));

	//�����������Ӵ˹�Ч
	if (Cast<AGameCharacter>(FirstTarget) && EffectData->BaseEffectData.bIsBindingVisibility)
	{
		Cast<AGameCharacter>(FirstTarget)->GetPerformanceComponent()->AddEffect(UID);
	}
}

void ABeamEffectEmitter::SetBeamAttribute()
{
	GetParticleSystemComponent()->SetVectorParameter("ParticleSize", FVector(EffectData->BeamData.ParticleSize, 1.f, 1.f));
	GetParticleSystemComponent()->SetFloatParameter("ParticleRange", EffectData->BeamData.ParticleRange);

	//��������ģʽ��ʱ��������ײʱ��׼ȷ�ģ�����ֱ������������
	if (!STComponent)
	{
		return;
	}

	if (EffectData->BeamData.IsBendFromTarget)
	{
		STComponent->SetStaticMesh(nullptr);
	}
	else
	{
		//��Ҫ��̬������λ�ã�������Actor�ƶ�����������������ײ
		FTransform CurrentComponentTransform = STComponent->GetComponentTransform();
		STComponent->SetAbsolute(true, true, true);
		STComponent->SetWorldTransform(CurrentComponentTransform);
		STComponent->SetWorldScale3D(FVector(EffectData->BeamData.ParticleSize *  EffectData->BeamData.ParticleRange / 100.f));
	}
}

FVector ABeamEffectEmitter::GetFlySourcePos(bool bInit /* = false */)
{
	// ����Ŀ������ص㣬�ж�SecondTransform��������������
	if ((FirstTransform->bIsLocationOnWorld || !FirstTransform->bIsBind) && !bInit)
	{
		return SourcePos;
	}

	if (IsValid(FirstTarget))
	{
		ACharacter* Character = Cast<ACharacter>(FirstTarget);
		//ˢ��Ŀ��㣬�Լ���λ�ü������ƫ��
		FTransform Transform;
		Transform = Character && FirstTransform->BindSocket != "" ? Character->GetMesh()->GetSocketTransform(FName(*FirstTransform->BindSocket)) : FirstTarget->GetActorTransform();
		SourcePos = Transform.TransformPosition(FirstTransform->Transform.GetLocation());
	}

	if (!FirstTransform->bIsBind && FirstTransform->bIsLocationOnWorld)
	{
		return SourcePos = FirstTransform->Transform.GetLocation();
	}

	return SourcePos;
}

void ABeamEffectEmitter::SetSourcePoint()
{
	///ʵʱ����λ��
	if (IsValid(FirstTarget))
	{
		GetFlySourcePos();

		for (int32 i = 0; i < GetParticleSystemComponent()->Template->Emitters.Num(); i++)
		{
			GetParticleSystemComponent()->SetBeamSourcePoint(i, SourcePos, 0);
		}
	}
}

void ABeamEffectEmitter::SetTargetTangent()
{
	SCOPE_CYCLE_COUNTER(STAT_SetTargetTangent);

	if (IsValid(FirstTarget) && EffectData->BeamData.IsBendFromTarget)
	{
		for (int32 i = 0; i < GetParticleSystemComponent()->Template->Emitters.Num(); i++)
		{
			//GetParticleSystemComponent()->SetBeamSourceTangent(i, FirstTarget->GetActorForwardVector() * OtherEffectData->Beam_BendStrength, 0);

			// ��㵽�յ��Rotation��yaw
			float temp = (SecondTarget->GetActorLocation() - FirstTarget->GetActorLocation()).Rotation().Yaw;
			// ��ɫ��������ϵ���ڵķ�λ ���C��ɫ�������Ă������泯Ŀ�˕r����ֱ�Q
			float Fst2Snd = 90.f - temp;
			// �Ƕ���FirstTarget�泯SecondTarget��0��ƫ��
			float offset = (temp - FirstTarget->GetActorRotation().Yaw);
			// tangentֵ������泯�յ�Ϊ0����׼��FirstTarget����ƫ��������
			FVector tangent( FMath::Sin(FMath::DegreesToRadians(Fst2Snd + offset)), FMath::Cos(FMath::DegreesToRadians(Fst2Snd + offset)), 0);				
			GetParticleSystemComponent()->SetBeamSourceTangent(i, tangent, 0);
			
			// Tangent��ǿ������㵽�յ�ľ��룬�������ǿ��������
			float strength = (SecondTarget->GetActorLocation() - FirstTarget->GetActorLocation()).Size2D() * EffectData->BeamData.BendStrength;
			GetParticleSystemComponent()->SetBeamSourceStrength(i, strength, 0);
		}
	}
}

void ABeamEffectEmitter::SetTargetPoint()
{
	if (IsValid(SecondTarget))
	{
		GetFlyTargetPos();

		for (int32 i = 0; i < GetParticleSystemComponent()->Template->Emitters.Num(); i++)
		{
			GetParticleSystemComponent()->SetBeamTargetPoint(i, TargetPos, 0);
		}
	}
}

void ABeamEffectEmitter::Move()
{
	SCOPE_CYCLE_COUNTER(STAT_Move);

	//����Ч�ƶ���ʱ�򣬹�Ч��λ�����ƶ��ĵ�
	FVector Direction = TargetPos - SourcePos;
	if (CurrentDistance < Direction.Size())
	{
		Direction.Normalize();
		for (int32 i = 0; i < GetParticleSystemComponent()->Template->Emitters.Num(); i++)
		{
			GetParticleSystemComponent()->SetBeamTargetPoint(i,
				SourcePos + Direction * CurrentDistance, 0);
		}
		SetActorLocationAndRotation(SourcePos + Direction * CurrentDistance, FRotationMatrix::MakeFromX(Direction).Rotator());
	}
	else
	{
		CurrentDistance = 0.f;
		FlySpeed = 0.f;
		OnEffectArrived.Broadcast();
		//�����ˣ�����λ�õ�TargetPos
		SetActorLocationAndRotation(TargetPos, FRotationMatrix::MakeFromX(Direction).Rotator());
	}
}

void ABeamEffectEmitter::SetComponentTransform()
{
	SCOPE_CYCLE_COUNTER(STAT_SetComponentTransform);

	FVector TargetPoint;
	GetParticleSystemComponent()->GetBeamTargetPoint(0, 0, TargetPoint);

	FVector SourcePoint;
	GetParticleSystemComponent()->GetBeamSourcePoint(0, 0, SourcePoint);

	STComponent->SetWorldLocation((TargetPoint + SourcePoint) / 2);
	STComponent->SetWorldRotation(FRotationMatrix::MakeFromX(TargetPoint - SourcePoint).Rotator());
	FVector Scale = STComponent->GetComponentScale();
	STComponent->SetWorldScale3D(FVector((TargetPoint - SourcePoint).Size() / 100.f, Scale.Y, Scale.Z));
}


void ABeamEffectEmitter::OnEmitterCollisionBegin(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (BeamCollisionList.Contains(Other))
	{
		if (!BeamCollisionList[Other].bOverlap)
		{
			Super::OnEmitterCollisionBegin(OverlappedComp, Other, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
			BeamCollisionList[Other].bOverlap = true;
			CS3_Display(CS3DebugType::CL_Undefined, TEXT("Beam Collision : Actor named %s"), *Other->GetName());
		}
	}
	else
	{
		BeamCollisionList.Add(Other, Data(true, 0.0f));
		Super::OnEmitterCollisionBegin(OverlappedComp, Other, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
		CS3_Display(CS3DebugType::CL_Undefined, TEXT("Beam Collision : Actor named %s"), *Other->GetName());
	}
}

void ABeamEffectEmitter::UpdateBeamCollisionList(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(STAT_UpdateBeamCollisionList);

	for (auto it = BeamCollisionList.CreateIterator(); it; ++it)
	{
		if (IsValid(it.Key()))
		{
			if (it.Value().bOverlap)
			{
				it.Value().Time += DeltaTime;

				if (it.Value().Time >= 1.0f)
				{
					it.Value().Time = 0.0f;
					it.Value().bOverlap = false;
					it.RemoveCurrent();
				}
			}
		}
		else
		{
			it.RemoveCurrent();
		}
	}
}

void ABeamEffectEmitter::Tick(float DeltaTime)
{
	AEffectEmitter::Tick(DeltaTime);

	if (bPlaying)
	{
		//������ײ�б�
		if (STComponent && STComponent->GetStaticMesh())
		{
			UpdateBeamCollisionList(DeltaTime);
		}

		//�������
		SetSourcePoint();
		//�����յ�
		SetTargetPoint();
		//����Ŀ��������
		SetTargetTangent();
	
		if (FlySpeed > 0.f)
		{
			///����Ҫ�ƶ��ĳ���
			CurrentDistance += DeltaTime * FlySpeed;
			//�ƶ�
			Move();
		}

		if (STComponent && STComponent->GetStaticMesh() && !EffectData->BeamData.IsBendFromTarget)
		{
			SetComponentTransform();
		}
	}
}

CONTROL_COMPILE_OPTIMIZE_END

