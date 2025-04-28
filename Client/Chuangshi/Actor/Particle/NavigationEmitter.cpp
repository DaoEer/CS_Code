// Fill out your copyright notice in the Description page of Project Settings.

#include "NavigationEmitter.h"
// UE4
#include "GameFramework/CharacterMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SplineComponent.h"
#include "Components/CapsuleComponent.h"
// CS3����
#include "Actor/Player/PlayerCharacter.h"
#include "Manager/ParticleManager.h"
#include "Util/CS3Debug.h"
#include "Util/GolbalBPFunctionLibrary.h"

CONTROL_COMPILE_OPTIMIZE_START

ANavigationEmitter::ANavigationEmitter()
{
	NavigationTrace = CreateDefaultSubobject<USplineComponent>(TEXT("NavigationTrace"));
	NavigationTrace->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	NavigationTrace->SetAbsolute(true, true, true);

	SpiralTrace = CreateDefaultSubobject<USplineComponent>(TEXT("SpiralTrace"));
	SpiralTrace->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	RisingTrace = CreateDefaultSubobject<USplineComponent>(TEXT("RisingTrace"));
	RisingTrace->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	RisingTrace->SetAbsolute(true, true, true);
}

void ANavigationEmitter::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;

	Super::BeginPlay();

	InitNavigationTrace();

	CalculateScale();
}

void ANavigationEmitter::InitNavigationTrace()
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(UGolbalBPFunctionLibrary::GetCS3PlayerCharacter());

	if (Player)
	{
		// ��ȡ������
		NavLocationList = Player->GetNavigateGuidePathList();

		NavigationTrace->SetSplinePoints(NavLocationList, ESplineCoordinateSpace::World, true);

		TArray<FVector> NewPointList;
		for (int32 i = 0; i < NavigationTrace->GetNumberOfSplinePoints(); i++)
		{
			FRotator Rotation = NavigationTrace->GetRotationAtSplinePoint(i, ESplineCoordinateSpace::World);
			// �µĹ켣�㣬λ����ҵ����Ϸ�
			NewPointList.Add(NavLocationList[i] + FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y) * 0.f + FVector(0, 0, 150));
		}

		NavigationTrace->SetSplinePoints(NewPointList, ESplineCoordinateSpace::World, true);

		MoveSpeed = Player->GetCharacterMovement()->GetMaxSpeed() * 2;
	}
}

void ANavigationEmitter::CalculateScale()
{
	if (NavLocationList.Num() < 2)
	{
		UUECS3GameInstance::Instance->ParticleManager->StopEffectByUID(UID);
		return;
	}
	
	float NavLength = 0.0f;
	for (int32 i = 1; i < NavLocationList.Num(); i++)
	{
		NavLength += (NavLocationList[i] - NavLocationList[i - 1]).Size();
	}

	Scale = NavigationTrace->GetSplineLength() / NavLength;
}

void ANavigationEmitter::UpdateMoveSpeed(float DeltaSeconds)
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(UGolbalBPFunctionLibrary::GetCS3PlayerCharacter());
	
	if (Player)
	{
		// �ж��Ƿ��������ٶ�
		if (bNormalSpeed)
		{
			// ����λ�ö�̬��������
			float CurrentScale = Scale;
			FVector Location = GetActorLocation();
			FVector PlayerLocation = Player->GetActorLocation();
			if ((Location - PlayerLocation).Size() < ForwardDiatance / 2.f || bSpeedUp)
			{
				
				if (AdjustScale < 0.5f)
				{
					// ����
					AdjustScale += 0.5f * DeltaSeconds;
					bSpeedUp = true;
				}
				else
				{
					// ���ٵ������
					bSpeedUp = false;
				}
				
				CurrentScale += AdjustScale;
			}
			else if ((Location - PlayerLocation).Size() > ForwardDiatance * 1.5f)
			{
				// �����������룬��ʼ����
				AdjustScale -= DeltaSeconds;
				CurrentScale += AdjustScale;
			}
			else
			{
				// ���ذڶ�
				if(AdjustScale < 0)
				{
					AdjustScale += 0.02f;
					CurrentScale += AdjustScale;
				}
				else
				{
					AdjustScale -= 0.02f;
					CurrentScale += AdjustScale;
				}
			}

			// ��������ʱ�򲻼���Z������ٶ�
			if (Player->GetCharacterMovement()->IsFalling())
			{
				MoveSpeed = Player->GetCapsuleComponent()->ComponentVelocity.Size2D() * CurrentScale;
			}
			else
			{
				MoveSpeed = Player->GetCapsuleComponent()->ComponentVelocity.Size() * CurrentScale;
			}
			return;
		}

		MoveSpeed -= DeltaSeconds * Player->GetCharacterMovement()->GetMaxSpeed();

		if (MoveSpeed < Player->GetCharacterMovement()->GetMaxSpeed() * Scale)
		{
			bNormalSpeed = true;
			// ���������ǰ���ľ���
			ForwardDiatance = (GetActorLocation() - Player->GetActorLocation()).Size();
			MoveSpeed = Player->GetCharacterMovement()->Velocity.Size() * Scale;
		}
	}
}

void ANavigationEmitter::Tick(float DeltaSeconds)
{
	if (bPlaying)
	{
		CurrentTime += DeltaSeconds;

		// ��Ч����ɢ
		UpdateTransparency(DeltaSeconds);

		if (!bSpiralRising)
		{
			UpdateMoveSpeed(DeltaSeconds);
			Distance += MoveSpeed * DeltaSeconds;
		}
	
		//��ǰҪ�����λ��
		FVector Location;
		FRotator Rotation;

		//�жϿ�ʼ����
		if (!bSpiralRising && Distance > NavigationTrace->GetSplineLength())
		{
			bSpiralRising = true;
			MoveSpeed = 1200.f;

			//�����������ߵ�λ�úͷ���
			Location = NavigationTrace->GetLocationAtSplinePoint(NavigationTrace->GetNumberOfSplinePoints() - 1, ESplineCoordinateSpace::World);
			Rotation = NavigationTrace->GetRotationAtSplinePoint(NavigationTrace->GetNumberOfSplinePoints() - 1, ESplineCoordinateSpace::World);
			Rotation.Yaw += 90.f;
			RisingTrace->SetWorldLocationAndRotation(Location, Rotation);

			OtherDistance = 0.0f;
		}

		if (bSpiralRising)
		{
			MoveSpeed += 800.f * DeltaSeconds;
			OtherDistance += DeltaSeconds * MoveSpeed;
				
			if (OtherDistance < RisingTrace->GetSplineLength())
			{
				Location = RisingTrace->GetLocationAtDistanceAlongSpline(OtherDistance, ESplineCoordinateSpace::World);
				Rotation = RisingTrace->GetRotationAtDistanceAlongSpline(OtherDistance, ESplineCoordinateSpace::World);
			}
			else
			{
				Stop();
				return;
			}
		}
		else
		{
			// ���������ת
			RandTime += DeltaSeconds;

			if (RandTime > RandFrequency)
			{
				if (FMath::RandRange(-1.f, 1.f) >= 0)
				{
					SpiralSpeed = 400;
				}
				else
				{
					SpiralSpeed = 0;
				}

				RandFrequency = FMath::RandRange(2, 8);
				RandTime = 0.0f;
			}
			
			// ����������
			OtherDistance += SpiralSpeed * DeltaSeconds;
			float length = SpiralTrace->GetSplineLength();
			OtherDistance = (OtherDistance / length - FMath::TruncToInt(OtherDistance / length)) * SpiralTrace->GetSplineLength();

			// �������ƫ��
			FTransform Transform = NavigationTrace->GetTransformAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
			Location = Transform.TransformPosition(SpiralTrace->GetLocationAtDistanceAlongSpline(OtherDistance, ESplineCoordinateSpace::Local));
			Rotation = NavigationTrace->GetRotationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		}

		// ���ù�Чλ��
		SetActorLocationAndRotation(Location, Rotation.Quaternion());
	}
	
	AEmitter::Tick(DeltaSeconds);
}

CONTROL_COMPILE_OPTIMIZE_END
