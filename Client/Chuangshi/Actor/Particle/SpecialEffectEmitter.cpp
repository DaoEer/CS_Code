// Fill out your copyright notice in the Description page of Project Settings.

#include "SpecialEffectEmitter.h"
// UE4
#include "Components/SplineComponent.h"
#include "GameFramework/Character.h"
// ��������
#include "Util/CS3Debug.h"
#include "GameData/EffectEmitterData.h"
// CS3����
#include "GameDevelop/CS3GameInstance.h"

#define DefaultHeight 130.f


CONTROL_COMPILE_OPTIMIZE_START
ASpecialEffectEmitter::ASpecialEffectEmitter()
{
	FirstStageSpline = CreateDefaultSubobject<USplineComponent>(TEXT("FirstStageSpline"));
	FirstStageSpline->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	FirstStageSpline->SetAbsolute(true, true, true);

	ThirdStageSplineOne = CreateDefaultSubobject<USplineComponent>(TEXT("ThirdStageSplineOne"));
	ThirdStageSplineOne->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	ThirdStageSplineOne->SetAbsolute(true, true, true);

	ThirdStageSplineTwo = CreateDefaultSubobject<USplineComponent>(TEXT("ThirdStageSplineTwo"));
	ThirdStageSplineTwo->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	ThirdStageSplineTwo->SetAbsolute(true, true, true);
}

void ASpecialEffectEmitter::InitEmitterTransform()
{
	Super::InitEmitterTransform();

	// ������Ŀ��һ����λ�ã�����ֻ�����ֵ�����´�λ�÷���Tickһ��
	FirstTargetTransform = FirstTarget->GetActorTransform();
	SecondTargetTransform = SecondTarget->GetActorTransform();

	// ��ʼ����һ������
	SetFirstStageSpline();
}

void ASpecialEffectEmitter::SetFirstStageSpline()
{
	FVector Location1 = FirstTargetTransform.GetLocation();
	FVector Location2 = SecondTargetTransform.GetLocation();

	// ��ǰ�ľ���
	ForwardDistance = (Location1 - Location2).Size2D() * PercentOfRisingDistance;
	if (ForwardDistance >= 200.f)
	{
		ForwardDistance = 200.f;
	}

	// ���÷���
	FRotator Rotation = FRotator(0, FRotationMatrix::MakeFromX(Location2 - Location1).Rotator().Yaw, 0);
	SetActorRotation(Rotation);
	FirstStageSpline->SetWorldRotation(Rotation);

	// ��������ӵ�
	TArray<FVector> SplinePoints;
	// ��һ����
	SplinePoints.Add(GetActorLocation());
	
	// �ڶ�����
	// ���Ŀ����Character,���Ϲ�����ͽ��������ĵ�ƫ�ƣ�������ֻ����SourceHeight
	FVector2D SecondPoints = FVector2D(Rotation.Quaternion().GetAxisX());
	ACharacter* Character = Cast<ACharacter>(FirstTarget);
	float Z = Character ? EffectData->SpecialData.SourceHeight + DefaultHeight + FirstTargetTransform.GetLocation().Z - Character->GetMesh()->GetSocketLocation(FName(*FirstTransform->BindSocket)).Z : EffectData->SpecialData.SourceHeight + DefaultHeight + 100;
	Z *= FirstTargetTransform.GetScale3D().Z;
	SplinePoints.Add(GetActorLocation() + FVector(SecondPoints * ForwardDistance, Z));

	// ��������
	FirstStageSpline->SetSplinePoints(SplinePoints, ESplineCoordinateSpace::World, true);

	// ���õ������
	FVector Zero = FVector(0, 0, (EffectData->SpecialData.SourceHeight + DefaultHeight) * 2);
	FirstStageSpline->SetTangentsAtSplinePoint(0, Zero, Zero, ESplineCoordinateSpace::Local, true);
	FVector One = FVector(ForwardDistance * 2, 0, 0);
	FirstStageSpline->SetTangentsAtSplinePoint(1, One, One, ESplineCoordinateSpace::Local, true);
}


void ASpecialEffectEmitter::FirstStageMove(float DeltaTime)
{
	Distance += FlySpeed * DeltaTime;
	if (Distance <= FirstStageSpline->GetSplineLength())
	{
		SetActorLocation(FirstStageSpline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World));
		SetActorRotation(FirstStageSpline->GetRotationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World));
	}
	else
	{
		EnterNextMove();
	}
}

const FVector ASpecialEffectEmitter::GetThirdStageSplineLocation()
{
	// ��Ч��ͷ��1�׼�1.3�׵ĵط���ά������
	FVector Offset(0.f);
	Offset.Z = (100 + EffectData->SpecialData.TargetHeight + DefaultHeight) * SecondTargetTransform.GetScale3D().Z;

	return SecondTargetTransform.GetLocation() + Offset;
}

void ASpecialEffectEmitter::SetThirdStageSplineRotation()
{
	FVector Position = SecondTargetTransform.InverseTransformPosition(FirstTargetTransform.GetLocation());
	FRotator Rotation = GetActorRotation();
	Rotation.Yaw += 180.f;

	//�����������޼���ȡ���Ǹ�����
	if (Position.Y >= 0)
	{
		if (Position.X >= 0)
		{
			//��һ����
			CurrentThirdStageSpline = ThirdStageSplineOne;
		}
		else
		{
			//�ڶ�����
			CurrentThirdStageSpline = ThirdStageSplineTwo;
		}
	}
	else
	{
		if (Position.X >= 0)
		{
			//��������
			CurrentThirdStageSpline = ThirdStageSplineTwo;
		}
		else
		{
			//��������
			CurrentThirdStageSpline = ThirdStageSplineOne;
		}
	}

	CurrentThirdStageSpline->SetWorldRotation(Rotation);
	CurrentThirdStageSpline->SetWorldScale3D(SecondTargetTransform.GetScale3D());
}

void ASpecialEffectEmitter::SetThirdStageSpline()
{
	SetThirdStageSplineRotation(); 
	CurrentThirdStageSpline->SetWorldLocation(GetThirdStageSplineLocation());
}

void ASpecialEffectEmitter::SecondStageMove(float DeltaTime)
{
	// ���ݷ����жϷ�����һ��
	SetThirdStageSpline();

	FVector MovePosition = CurrentThirdStageSpline->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::World);

	// ����ط�����ʹ�÷��й�Ч�ķ������ȴ��Ż�
	FVector Direction = MovePosition - GetActorLocation();
	if (Direction.Size() >= FlySpeed * DeltaTime)
	{
		Direction.Normalize();
		AddActorWorldOffset(Direction * FlySpeed * DeltaTime);
	}
	else
	{
		EnterNextMove();
	}
}

void ASpecialEffectEmitter::ThirdStageMove(float DeltaTime)
{
	if (!CurrentThirdStageSpline)
	{
		CS3_Warning(TEXT("-->Null Pointer error:ASpecialEffectEmitter::ThirdStageMove : CurrentThirdStageSpline!"));
		return;
	}

	Distance += FlySpeed * DeltaTime;
	if (Distance <= CurrentThirdStageSpline->GetSplineLength())
	{
		// ���µ��������ߵ�λ�ã���Ϊ�����ǲ��󶨵�
		CurrentThirdStageSpline->SetWorldLocation(GetThirdStageSplineLocation());
		SetActorLocation(CurrentThirdStageSpline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World));
		SetActorRotation(CurrentThirdStageSpline->GetRotationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World));
	}
	else
	{
		EnterNextMove();
	}
}

void ASpecialEffectEmitter::Tick(float DeltaTime)
{
	if (bPlaying)
	{
		if (IsValid(FirstTarget))
		{
			FirstTargetTransform = FirstTarget->GetActorTransform();
		}

		if (IsValid(SecondTarget))
		{
			SecondTargetTransform = SecondTarget->GetActorTransform();
		}


		switch (FlyType)
		{
			case FLY_TYPE::NORMAL:
				FirstStageMove(DeltaTime);
				break;
			case FLY_TYPE::SECOND:
				SecondStageMove(DeltaTime);
				break;
			case FLY_TYPE::THIRD:
				ThirdStageMove(DeltaTime);
				break;
			default:
				break;
		}
	}
	
	AEffectEmitter::Tick(DeltaTime);
}

void ASpecialEffectEmitter::EnterNextMove()
{
	switch (FlyType)
	{
		case FLY_TYPE::NORMAL:
		{
			// ����ڶ��׶�
			FlyType = FLY_TYPE::SECOND;
			Distance = 0.f;
		}
			break;
		case FLY_TYPE::SECOND:
		{
			// ��������׶�
			FlyType = FLY_TYPE::THIRD;
		}
			break;
		case FLY_TYPE::THIRD:
		{
			OnEffectArrived.Broadcast();
			Stop();
		}
			break;
		default:
			break;
	}
}
CONTROL_COMPILE_OPTIMIZE_END

#undef DefaultHeight