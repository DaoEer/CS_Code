// Fill out your copyright notice in the Description page of Project Settings.

#include "FlyEffectEmitter.h"
// ��������
#include "GameData/EffectEmitterData.h"
// CS3����
#include "Actor/GameCharacter.h"
#include "Actor/ServerCharacter.h"
#include "Manager/ParticleManager.h"
#include "Component/PerformanceComponent.h"
#include "Util/CS3Debug.h"
#include "Entity.h"


DECLARE_CYCLE_STAT(TEXT("GetFlyTargetPos"), STAT_GetFlyTargetPos, STATGROUP_AFlyEffectEmitter);
DECLARE_CYCLE_STAT(TEXT("GetFlySourcePos"), STAT_GetFlySourcePos, STATGROUP_AFlyEffectEmitter);
DECLARE_CYCLE_STAT(TEXT("NormalMove"), STAT_NormalMove, STATGROUP_AFlyEffectEmitter);
DECLARE_CYCLE_STAT(TEXT("CheckAndSetEmitterBase"), STAT_CheckAndSetEmitterBase, STATGROUP_AFlyEffectEmitter);

CONTROL_COMPILE_OPTIMIZE_START
AFlyEffectEmitter::AFlyEffectEmitter()
{
	
}

void AFlyEffectEmitter::BeginPlay()
{
	// �������Ч��ͳͳ����Tick
	PrimaryActorTick.bCanEverTick = true;

	// �󶨷��й�Ч�ִ��¼�
	OnEffectArrived.AddDynamic(this, &AFlyEffectEmitter::OnFlyFinished);

	Super::BeginPlay();
}

void AFlyEffectEmitter::InitFromConfig()
{
	Super::InitFromConfig();

	// �ڶ��׶��˶����
	bCanSpecialMove			= EffectData->SpecialData.bCanSpecialMove;
	TransformationDistance	= EffectData->SpecialData.TransformationDistance;
	RisingDistance			= EffectData->SpecialData.RisingDistance;

	// �ٶ�
	FlySpeed				= EffectData->FlyData.FlySpeed;
	bIsFlyByTime				= EffectData->FlyData.bIsFlyByTime;
}

void AFlyEffectEmitter::InitEmitterTransform()
{
	ACharacter* Character = Cast<ACharacter>(FirstTarget);

	//����λ��
	FTransform Transform = Character && FirstTransform->BindSocket != "" ? Character->GetMesh()->GetSocketTransform(FName(*FirstTransform->BindSocket)) : FirstTarget->GetActorTransform();
	//����bLocationOnWorld��������λ��
	FVector Location;
	if (FirstTransform->bIsLocationOnWorld)
	{
		Location = FirstTransform->Transform.GetLocation();
	}
	else
	{
		Location = Transform.TransformPosition(FirstTransform->Transform.GetLocation());
	}
	//����bRotationOnWorld��������λ��
	FRotator Rotation;
	if (FirstTransform->bIsRotationOnWorld)
	{
		Rotation = FirstTransform->Transform.GetRotation().Rotator();
	}
	else
	{
		Rotation = Transform.TransformRotation(FirstTransform->Transform.GetRotation()).Rotator();
	}
	SetActorLocation(Location);
	SetActorRotation(Rotation);
	//���󶨵Ĺ�ЧΪ���ñ�����
	SetActorScale3D(FirstTransform->Transform.GetScale3D());

	//������ʼ��
	SourcePos = GetActorLocation();
	//����Ŀ���
	GetFlyTargetPos(true);

	//���ó���
	if (FirstTarget != SecondTarget)
	{
		FRotator LookRotation = FRotationMatrix::MakeFromX(TargetPos - FirstTarget->GetActorLocation()).Rotator();
		SetActorRotation(LookRotation);
	}

	//�Ƿ�������ڶ��׶��˶�
	if ((TargetPos - GetActorLocation()).Size() < TransformationDistance && 
		TransformationDistance > 0.0f && RisingDistance > 0.0f)
	{
		bCanSpecialMove = false;
	}

	//�����ƶ�ƽ̨�������
	if (CheckAndSetEmitterBase() && Cast<AServerCharacter>(ParentActor)->GetSelfEntity())
	{
		AttachToActor(ParentActor, FAttachmentTransformRules::KeepWorldTransform);
	}
	
	//�����������Ӵ˹�Ч
	if (Cast<AGameCharacter>(FirstTarget) && EffectData->BaseEffectData.bIsBindingVisibility)
	{
		Cast<AGameCharacter>(FirstTarget)->GetPerformanceComponent()->AddEffect(UID);
	}

	//��·����Դ�Ĺ�Ч����ͼ�г�ʼ��λ��
	if (Spline)
	{
		InitSplineTransform();
	}
}

FVector AFlyEffectEmitter::GetFlyTargetPos(bool bInit /* = false */)
{
	SCOPE_CYCLE_COUNTER(STAT_GetFlyTargetPos);

	// ����Ŀ������ص㣬�ж�SecondTransform��������������
	if ((SecondTransform->bIsLocationOnWorld || !SecondTransform->bIsBind) && !bInit)
	{
		return TargetPos;
	}

	if (IsValid(SecondTarget))
	{
		ACharacter* Character = Cast<ACharacter>(SecondTarget);
		//ˢ��Ŀ��㣬�Լ���λ�ü������ƫ��
		FTransform Transform;
		Transform = Character && SecondTransform->BindSocket != "" ? Character->GetMesh()->GetSocketTransform(FName(*SecondTransform->BindSocket)) : SecondTarget->GetActorTransform();
		TargetPos = Transform.TransformPosition(SecondTransform->Transform.GetLocation());
	}

	if (!SecondTransform->bIsBind && SecondTransform->bIsLocationOnWorld)
	{
		return TargetPos = SecondTransform->Transform.GetLocation();
	}

	return TargetPos;
}

FVector AFlyEffectEmitter::GetFlySourcePos(bool bInit /* = false */)
{
	SCOPE_CYCLE_COUNTER(STAT_GetFlySourcePos);

	// ����Ŀ������ص㣬�ж�SecondTransform��������������
	if ((FirstTransform->bIsLocationOnWorld) && !bInit)
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
	
	if (FirstTransform->bIsLocationOnWorld)
	{
		return SourcePos = FirstTransform->Transform.GetLocation();
	}

	return SourcePos;
}

void AFlyEffectEmitter::PlayTriggerParticle()
{
	for (auto TriggerID : EffectData->FlyData.FlyArriveEffectList)
	{
		UUECS3GameInstance::Instance->ParticleManager->PlayParticle(TriggerID, 0.0f, FirstTarget, SecondTarget);
	}
}

void AFlyEffectEmitter::OnFlyFinished()
{
	PlayTriggerParticle();
}

void AFlyEffectEmitter::Tick(float DeltaTime)
{
	if (bPlaying)
	{
		//ˢ��Ŀ���
		GetFlyTargetPos();

		//ˢ���ƶ�ƽ̨��ֻ�г�ʼ����ʱ�����ƶ�ƽ̨�ϲż��
		if (ParentActor && !CheckAndSetEmitterBase())
		{
			DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		}

		//���ݷ���ʱ������ٶ�
		if (bIsFlyByTime)
		{
			FlySpeed = (GetActorLocation() - FVector(0, 0, TotalRisingOffset) - TargetPos).Size() / (EffectData->FlyData.FlyTime - CurrentTime);
		}

		switch (FlyType)
		{
		case FLY_TYPE::NORMAL:
			NormalMove(DeltaTime);
			break;
		case FLY_TYPE::SECOND:
			SecondMove(DeltaTime);
			break;
		default:
			break;
		}
	}
	
	AEffectEmitter::Tick(DeltaTime);
}
void AFlyEffectEmitter::SetEffectLocationAndRotation(const float& MoveDistance, const FVector& RisingOffset, const FVector& TargetLocation)
{
	// ���糯��
	FVector Location;
	FRotator Rotation = FRotationMatrix::MakeFromX(TargetLocation - GetActorLocation()).Rotator();
	if (ParentActor)
	{
		// ������ƶ�ƽ̨����Գ���
		FQuat Quaternion = ParentActor->GetActorTransform().InverseTransformRotation(Rotation.Quaternion());
		// Delta�����λ���ƶ�����Ҫ��������
		Location = (Quaternion.GetAxisX() * MoveDistance + Quaternion.GetAxisZ() * RisingOffset.Z) * GetActorRelativeScale3D();
		// ʵ�ʵ����λ�ø���
		Location += RootComponent->RelativeLocation;
		// ���ó��򣬼�-90��ƫ��
		Rotation = (Quaternion * FRotator(0, -90, 0).Quaternion()).Rotator();
		// �����׶����ó���
		if (FlyType == FLY_TYPE::SECOND)
		{
			GetSecondMoveRotation(Rotation);
		}
		SetActorRelativeTransform(FTransform(Rotation, Location, GetActorRelativeScale3D()));
	}
	else
	{
		// λ��
		Location = (TargetLocation - GetActorLocation() + FVector(0, 0, TotalRisingOffset)).GetSafeNormal() * MoveDistance + RisingOffset + GetActorLocation();
		// ���ó���
		Rotation = (Rotation.Quaternion() * FRotator(0, -90, 0).Quaternion()).Rotator();
		if (FlyType == FLY_TYPE::SECOND)
		{
			GetSecondMoveRotation(Rotation);
		}
		SetActorLocationAndRotation(Location, Rotation, true);
	}
}

void AFlyEffectEmitter::NormalMove(float DeltaTime, FVector RisingOffset /*= FVector(0,0,0)*/)
{
	SCOPE_CYCLE_COUNTER(STAT_NormalMove);

	float MoveLength;
	float FrameDistance = FlySpeed * DeltaTime;
	float RemainMoveDistance = FrameDistance;
	float DefaultMaxDistance = 60;//�������Ϊ60��Ӧ��1���Ľ�����ֱ��Ϊ68��60��֤���ԽӴ���
	float TargetDistance = (TargetPos - GetActorLocation() + FVector(0, 0, TotalRisingOffset)).Size(); // ��Ŀ���ľ���

	if (TargetDistance <= 1.0f)
	{
		SetActorLocation(TargetPos);
		OnEffectArrived.Broadcast();
		Stop();//�����ƶ�
		return;
	}

	if (FrameDistance < DefaultMaxDistance)
	{
		MoveLength = FMath::Min(FrameDistance, TargetDistance);
		SetEffectLocationAndRotation(MoveLength, RisingOffset, TargetPos);
		TargetDistance = (TargetPos - GetActorLocation() + FVector(0, 0, TotalRisingOffset)).Size();// ���»�ȡ����Ϊλ���Ѿ�����

		if (TargetDistance <= 1.0f)
		{
			SetActorLocation(TargetPos);
			OnEffectArrived.Broadcast();
			Stop();//�����ƶ�
			return;
		}		
	}
	else
	{
		//һ֡�ƶ��ľ������ֶ��ƶ���Ϊ����ײ���
		while (RemainMoveDistance - DefaultMaxDistance > 0)
		{
			MoveLength = FMath::Min(TargetDistance, DefaultMaxDistance);
			SetEffectLocationAndRotation(MoveLength, RisingOffset, TargetPos);
			RemainMoveDistance -= MoveLength;
			TargetDistance = (TargetPos - GetActorLocation() + FVector(0, 0, TotalRisingOffset)).Size();

			if (TargetDistance <= 1.0f)
			{
				SetActorLocation(TargetPos);
				OnEffectArrived.Broadcast();
				Stop();//�����ƶ�
				return;
			}
		}
		SetEffectLocationAndRotation(FMath::Min(TargetDistance, RemainMoveDistance), RisingOffset, TargetPos);
		TargetDistance = (TargetPos - GetActorLocation() + FVector(0, 0, TotalRisingOffset)).Size();
		if (TargetDistance <= 1.0f)
		{
			SetActorLocation(TargetPos);
			OnEffectArrived.Broadcast();
			Stop();//�����ƶ�
			return;
		}
	}

	// �ۼ������߶�
	TotalRisingOffset += RisingOffset.Z;

	// �ж��Ƿ�Ҫ������һ�׶�
	EnterNextMove();
}

void AFlyEffectEmitter::SecondMove(float DeltaTime)
{
	LastRisingPercent = RisingPercent;
	// ���㵱ǰ�Ľ���
	if (bIsFlyByTime)
	{
		RisingPercent = (CompletedTime - (EffectData->FlyData.FlyTime - CurrentTime)) / CompletedTime;
	}
	else
	{
		float CurrentPercent = 1 - (GetActorLocation() - FVector(0, 0, FMath::Sin(RisingPercent * PI) * RisingDistance) - TargetPos).Size() / TransformationDistance;

		if (CurrentPercent> RisingPercent)
		{
			RisingPercent = CurrentPercent;
		}
	}

	// �����ľ���
	float RisingLength = (FMath::Sin(RisingPercent * PI) - FMath::Sin(LastRisingPercent * PI)) * RisingDistance;
	
	NormalMove(DeltaTime, FVector(0, 0, RisingLength));
}

void AFlyEffectEmitter::GetSecondMoveRotation(FRotator& OutRotation)
{
	// б��
	float k = FMath::Cos(RisingPercent * PI) * (RisingDistance / (GetActorLocation() - FVector(0, 0, TotalRisingOffset) - TargetPos).Size());
	float Angle = -atan(k) * 180 / PI;
	OutRotation.Roll = Angle;
}

void AFlyEffectEmitter::EnterNextMove()
{
	// �ж��Ƿ�Ҫ�������߽׶�
	if (bCanSpecialMove && (GetActorLocation() - TargetPos).Size() < TransformationDistance)
	{
		FlyType = FLY_TYPE::SECOND;
		bCanSpecialMove = false;

		// ���ŵڶ��׶ζ���
		if (AnimAsset.Num() > 1 && SKComponent)
		{
			SKComponent->PlayAnimation(AnimAsset[1], true);
		}

		if (bIsFlyByTime)
		{
			CompletedTime = EffectData->FlyData.FlyTime - CurrentTime;
		}
	}
}

bool AFlyEffectEmitter::CheckAndSetEmitterBase()
{
	SCOPE_CYCLE_COUNTER(STAT_CheckAndSetEmitterBase);

	// ��ʩ���ߺ�Ŀ�궼����ͬ���ƶ�ƽ̨��ʱ���󶨹�Ч���ƶ�ƽ̨��
	AServerCharacter* SFTarget = Cast<AServerCharacter>(FirstTarget);
	AServerCharacter* SSTarget = Cast<AServerCharacter>(SecondTarget);
	// ��ʼ����ʱ���ж�����Ŀ���Parent������ֻ�ж�Ŀ��
	if (!ParentActor)
	{
		if (SFTarget && SSTarget && SFTarget->GetSelfEntity() && SSTarget->GetSelfEntity() && SFTarget->GetSelfEntity()->ParentID() != 0
			&& SFTarget->GetSelfEntity()->ParentID() == SSTarget->GetSelfEntity()->ParentID())
		{
			KBEngine::Entity* ParentEntity = SFTarget->GetSelfEntity()->Parent();
			if (ParentEntity != nullptr)
			{
				AActor* MovingPlatform = ParentEntity->Actor();
				if (IsValid(MovingPlatform))
				{
					ParentActor = MovingPlatform;
					return true;
				}
			}
		}
	}
	else
	{
		if (SSTarget && SSTarget->GetSelfEntity() && SSTarget->GetSelfEntity()->ParentID())
		{
			return true;
		}
	}
	// ʧ�������
	ParentActor = nullptr;
	return false;
}

CONTROL_COMPILE_OPTIMIZE_END
