// Fill out your copyright notice in the Description page of Project Settings.

#include "IceBirdEffectEmitter.h"
// UE4
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimSequenceBase.h"
// ��������
#include "GameData/EffectEmitterData.h"
// CS3����
#include "GameDevelop/CS3GameInstance.h"
#include "Manager/CustomTimerManager.h"



void AIceBirdEffectEmitter::InitFromConfig()
{
	Super::InitFromConfig();

	//�����ٶ�Ĭ��10��ÿ��
	FlySpeed = FlySpeed > 0.f ? FlySpeed : 1000.f;
	//�����ЧĬ���ж���׶�
	bCanSpecialMove = true;
	//�������任�˶����������
	TransformationDistance = TransformationDistance > 0.f ? TransformationDistance : 1000.f;
	//����֧�ְ��������
	bIsFlyByTime = false;
	//����Ĭ�ϵ������߶�Ϊ10��
	RisingDistance = RisingDistance > 0.f ? RisingDistance : 1000.f;
}

void AIceBirdEffectEmitter::SecondMove(float DeltaTime)
{
	float RisingLength = DeltaTime * 1500.f;

	NormalMove(DeltaTime, FVector(0, 0, RisingLength));
}

void AIceBirdEffectEmitter::GetSecondMoveRotation(FRotator& OutRotation)
{
	// ����
	
	float Angle = -FMath::Acos(FlySpeed / 1000.f) * 180 / PI;
	OutRotation.Roll = Angle;
}

void AIceBirdEffectEmitter::EnterNextMove()
{
	switch (FlyType)
	{
		///�жϽ���ڶ��׶�
	case FLY_TYPE::NORMAL:
		if (bCanSpecialMove && RisingDistance > 0.0f && (GetActorLocation() - TargetPos).Size() < TransformationDistance)
		{
			FlyType = FLY_TYPE::SECOND;
			bCanSpecialMove = false;
			FlySpeed = 300.f;
		}
		break;
		///�жϽ�������׶�
	case FLY_TYPE::SECOND:
		if (TotalRisingOffset > RisingDistance)
		{
			FlyType = FLY_TYPE::THIRD;
			FlySpeed = 0.f;
			if (AnimAsset.Num() > 1 && SKComponent)
			{
				SKComponent->PlayAnimation(AnimAsset[1], true);
			}

			FRotator Rotation = GetActorRotation();
			Rotation.Roll = 0.f;
			SetActorRotation(Rotation);

			///��������׶κ�һ��֮������һ�׶�
			FTimerHandle Handle;
			float Length = 1.0f;
			if (AnimAsset.Num() > 1 && Cast<UAnimSequenceBase>(AnimAsset[1]))
			{
				Length = Cast<UAnimSequenceBase>(AnimAsset[1])->GetPlayLength() / EffectEmitterData->SkeletalMesh.PlayRate;
			}
			TWeakObjectPtr<AIceBirdEffectEmitter> ThisPtr(this);
			UUECS3GameInstance::Instance->CustomTimerManager->SetTimer(this, Handle, FTimerDelegate::CreateLambda([ThisPtr]()
			{
				if (ThisPtr.IsValid())
				{
					AIceBirdEffectEmitter* Self = ThisPtr.Get();

					if (Self->AnimAsset.Num() > 2 && Self->SKComponent)
					{
						Self->SKComponent->PlayAnimation(Self->AnimAsset[2], true);
					}

					Self->FlyType = FLY_TYPE::NORMAL;
					Self->FlySpeed = 3000.f;
					//�����������㣬��Ϊ���һ���׶���ֱ�ӷɹ�ȥ�ģ�û�м���ƫ��
					Self->TotalRisingOffset = 0.0f;
				}
			}), Length, false);
		}
		break;
	default:
		break;
	}
}

