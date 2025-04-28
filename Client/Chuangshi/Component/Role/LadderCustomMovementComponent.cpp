// Fill out your copyright notice in the Description page of Project Settings.


#include "LadderCustomMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameData/CharacterData.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "UnrealMathUtility.h"
#include "Actor/Monster/MonsterCharacter.h"
#include "JumpComponent.h"
#include "Interface/GameObjectInterface.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "Interface/Role/RoleSpaceContentInterface.h"
#include "Actor/Player/PlayerCharacter.h"
#include "Interface/Role/RoleStateInterface.h"
#include "CS3Base/GameObject.h"

CONTROL_COMPILE_OPTIMIZE_START
ULadderCustomMovementComponent::ULadderCustomMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurLadderCharacter = nullptr;
}

void ULadderCustomMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void ULadderCustomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (IsOverLadderZone)
	{
		UpdateCustomMovement(DeltaTime);
		CheckEnterLadder(DeltaTime);
	}
}

void ULadderCustomMovementComponent::InitLadderData()
{
}

void ULadderCustomMovementComponent::ClearLadderData()
{
	CS3_Display(CS3DebugType::CL_Actor, TEXT("ULadderCustomMovementComponent::Debug[EntityID=%d]=======ClearLadderData"),
		GetPlayerCharacter()->GetSelfEntity()->ID());

	IsOverLadderZone = false;
	IsCustomLadderModel = false;
	IsEnterLaddering = false;
	IsExitLaddering = false;
	LadderStetPosOnStoping = 0.0f;
	CurLadderCharacter = nullptr;
	ClimbLadderSpeed = 200.0f;
	IsRootMotionHaveUpAction = false;
	TempCustomMovementMode = CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_NONE;
	ClimbLadderActionFramePos = 0.0f;
	CurClimbLadderState = CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_STAND;
}

void ULadderCustomMovementComponent::BeginOverlappedCustomMoveZone(AMonsterCharacter *LadderCharacter)
{
	CurLadderCharacter = LadderCharacter;
	IsOverLadderZone = true;

	NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_ENTER_ZONE);
}

void ULadderCustomMovementComponent::EndOverlappedCustomMoveZone(AMonsterCharacter *LadderCharacter)
{
	CurLadderCharacter = LadderCharacter;
	IsOverLadderZone = false;
	IsEnterLaddering = false;
}

void ULadderCustomMovementComponent::AddMovementLadderUp(float InputScale)
{
	CheckExitLadder(InputScale);
	if (IsLadderMovement())
	{
		FVector BottomLocation = CurLadderCharacter->GetLadderBottomLocation();
		FVector TopLocation = CurLadderCharacter->GetLadderTopLocation();
		FVector WorldDirection = TopLocation - BottomLocation;
		WorldDirection.Normalize(0.0001);
		GetPlayerCharacter()->AddMovementInput(WorldDirection, InputScale);
	}
}

bool ULadderCustomMovementComponent::IsLadderMovement()
{
	return IsCustomLadderModel;
}

void ULadderCustomMovementComponent::UpdateCustomMovement(float DeltaTime)
{
	if (IsLadderMovement())
	{
		ClimbLadderActionFramePos = GetClimbLadderActionFramePos();
		if (TempCustomMovementMode == CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_ROOT_MOTION)
		{
			UpdateRootMotion(DeltaTime);
		}
		else if (TempCustomMovementMode == CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_LADDER)
		{
			UpdateLadderMovement(DeltaTime);
		}
		
		NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_MOVE, ClimbLadderActionFramePos);
	}
}

void ULadderCustomMovementComponent::UpdateLadderMovement(float DeltaTime)
{
	FVector BottomLocation = CurLadderCharacter->GetLadderBottomLocation();
	FVector TopLocation = CurLadderCharacter->GetLadderTopLocation();
	FRotator TempLadderRotation = CurLadderCharacter->GetLadderBottomRotation();
	float TempLadderStepHeight = CurLadderCharacter->StepHeight;
	float CapsuleHalfHeight = GetPlayerCharacter()->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	FVector ActorLoccation = GetPlayerCharacter()->GetActorLocation();

	FVector CharacterFootLocation = FVector(ActorLoccation.X, ActorLoccation.Y, ActorLoccation.Z - CapsuleHalfHeight);//��ҽŵ�λ��
	FVector NextCharacterFootLocation = ((GetPlayerCharacter()->GetCharacterMovement()->GetCurrentAcceleration() / GetPlayerCharacter()->GetCharacterMovement()->MaxAcceleration) *
		(DeltaTime * ClimbLadderSpeed)) + CharacterFootLocation;//��һ֡����ҽŵ�λ��(ʱ��*�ٶ�+��ҵ�ǰ�ŵ�λ��)
	FVector FindFootLocation = UKismetMathLibrary::FindClosestPointOnSegment(NextCharacterFootLocation, TopLocation, BottomLocation);//���ӷ�Χ����һ�������
	FindFootLocation -= CharacterFootLocation;//MoveUpdatedComponent��Ҫ����ƫ�Ƶľ���
	float FindFootLocationSize = FindFootLocation.Size();

	FVector TempDeltaMovement;
	if (FindFootLocationSize < 0.1f)
	{
		float LerpValue = UKismetMathLibrary::Lerp(LadderStetPosOnStoping, UKismetMathLibrary::Round(LadderStetPosOnStoping), 0.1);
		float TempStepDownPos = LadderStetPosOnStoping - LerpValue;
		LadderStetPosOnStoping = LerpValue;

		FVector TopToBottomLocation = BottomLocation - TopLocation;
		TopToBottomLocation.Normalize(0.0001);
		TempDeltaMovement = TopToBottomLocation * (TempStepDownPos * TempLadderStepHeight);
	}
	else
	{
		TempDeltaMovement = FindFootLocation;
	}
	/*CS3_Display(CS3DebugType::CL_Undefined, TEXT("ULadderCustomMovementComponent[TempDeltaMovement=(%f,  %f,  %f), CharacterFootLoccation=(%f,  %f,  %f),   CurrentAcceleration=(%f,  %f,  %f)]"),
		TempDeltaMovement.X, TempDeltaMovement.Y, TempDeltaMovement.Z,
		CharacterFootLocation.X, CharacterFootLocation.Y, CharacterFootLocation.Z,
		CurCharacterMovement->GetCurrentAcceleration().X, CurCharacterMovement->GetCurrentAcceleration().Y, CurCharacterMovement->GetCurrentAcceleration().Z);*/

	GetPlayerCharacter()->GetCharacterMovement()->MoveUpdatedComponent(TempDeltaMovement, TempLadderRotation, false);
	GetPlayerCharacter()->GetCharacterMovement()->Velocity = FVector(0.0f, 0.0f, 0.0f);
}

void ULadderCustomMovementComponent::UpdateRootMotion(float DeltaTime)
{
	if (GetPlayerCharacter()->IsPlayingRootMotion())
	{
		FVector DeltaVector = GetPlayerCharacter()->GetCharacterMovement()->Velocity * DeltaTime;
		GetPlayerCharacter()->GetCharacterMovement()->MoveUpdatedComponent(DeltaVector, GetPlayerCharacter()->GetActorRotation(), false);
		FVector CurLocation = GetPlayerCharacter()->GetActorLocation();
		/*CS3_Display(CS3DebugType::CL_Undefined, TEXT("ULadderCustomMovementComponent:UpdateRootMotion  Velocity(%f,  %f, %f)  ,   (%f,  %f, %f),  (%f,  %f, %f)"),
			CurCharacterMovement->Velocity.X, CurCharacterMovement->Velocity.Y, CurCharacterMovement->Velocity.Z,
			DeltaVector.X, DeltaVector.Y, DeltaVector.Z, CurLocation.X, CurLocation.Y, CurLocation.Z);*/
		GetPlayerCharacter()->GetCharacterMovement()->Velocity = FVector(0.0f, 0.0f, 0.0f);
	}
	else
	{
		GetPlayerCharacter()->GetCharacterMovement()->Velocity = FVector(0.0f, 0.0f, 0.0f);
	}
}

float ULadderCustomMovementComponent::GetClimbLadderActionFramePos()
{
	FVector ActorOffectLocation = UKismetMathLibrary::TransformDirection(GetPlayerCharacter()->GetActorTransform(), GetPlayerCharacter()->GetBaseTranslationOffset());
	FVector CharacterCurPoint = GetPlayerCharacter()->GetMesh()->GetComponentLocation() - ActorOffectLocation;
	CharacterCurPoint.Z -= GetPlayerCharacter()->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();//������ڵĵ�ǰ�ŵ׵�
	/*CS3_Display(CS3DebugType::CL_Undefined, TEXT("GetLadderStepPos[CharacterCurPoint=(%f,  %f,  %f)]"),
		CharacterCurPoint.X, CharacterCurPoint.Y, CharacterCurPoint.Z);*/

	FVector BottomLocation = CurLadderCharacter->GetLadderBottomLocation();
	FVector TopLocation = CurLadderCharacter->GetLadderTopLocation();
	FVector FindCharacterPoing = UKismetMathLibrary::FindClosestPointOnSegment(CharacterCurPoint, TopLocation, BottomLocation);
	FindCharacterPoing -= BottomLocation;
	float FindCharacterPoingSize = FindCharacterPoing.Size();
	float NumberValue = FindCharacterPoingSize / CurLadderCharacter->StepHeight;
	return FMath::Fmod(NumberValue, 2.0f);
}

void ULadderCustomMovementComponent::ResetCharacterPitch()
{
	FRotator ActorRotation = GetPlayerCharacter()->GetActorRotation();
	ActorRotation.Pitch += CurLadderCharacter->LadderPitchValue;
	GetPlayerCharacter()->SetActorRotation(ActorRotation);
}


void ULadderCustomMovementComponent::CheckEnterLadder(float InputScale)
{
	if (!IsLadderMovement() && !IsExitLaddering && !IsEnterLaddering)
	{
		FVector ActorLoccation = GetPlayerCharacter()->GetActorLocation();
		float CapsuleHalfHeight = GetPlayerCharacter()->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
		FVector CharacterFootLoccation = FVector(ActorLoccation.X, ActorLoccation.Y, ActorLoccation.Z - CapsuleHalfHeight);
		FVector TempCharacterInputDir = GetPlayerCharacter()->GetCharacterMovement()->GetLastInputVector();
		float TempCharacterInputScale = TempCharacterInputDir.Size();
		TempCharacterInputDir.Normalize(0.0001f);

		bool IsEnterBottom = CheckEnterBottom(CharacterFootLoccation, TempCharacterInputDir, TempCharacterInputScale);
		if (IsEnterBottom)
		{
			CS3_Display(CS3DebugType::CL_Actor, TEXT("ULadderCustomMovementComponent::Debug[EntityID=%d]=======CheckEnterLadder IsEnterBottom"),
				GetPlayerCharacter()->GetSelfEntity()->ID());

			IsEnterLaddering = true;
			//�������ӽ�������ʾF
			GetPlayerCharacter()->AddToInteractivityList(CurLadderCharacter);

			//���ݵ���������Ҫ�޸ĵ�λ��
			//EnterBottom();
		}
		else
		{
			//�����Ǽ�ⶥ�����м�������ӵ��߼�(��CS3��Ŀ����Ҫ����ֽ��뷽ʽ)
		}
	}
}

bool ULadderCustomMovementComponent::CheckEnterBottom(FVector CharacterFootLocation,
	FVector CharacterInputDirection, float CharacterInputScale)
{
	FVector BottomLocation = CurLadderCharacter->GetLadderBottomLocation();
	FVector DistanceLocation = CharacterFootLocation - BottomLocation;
	float DistanceLocationSize = DistanceLocation.Size();
	bool BoolValue1 = DistanceLocationSize <= 50.0f;

	FVector BottomForwardVector = CurLadderCharacter->Bottom->GetForwardVector();
	float BottomDotCharacter = UKismetMathLibrary::Dot_VectorVector(BottomForwardVector, CharacterInputDirection);
	float CharacterDotTop = UKismetMathLibrary::Dot_VectorVector(CharacterInputDirection, BottomForwardVector);

	bool BoolValue2 = CharacterInputScale > 0.8f && BottomDotCharacter <= -0.8f;
	//bool BoolValue3 = CharacterInputScale < -0.8f && BottomDotCharacter <= -0.8f;

	CS3_Display(CS3DebugType::CL_Undefined, TEXT("CheckEnterBottom[DistanceLocationSize=%f   BottomDotCharacter=%f   CharacterInputScale=%f]"),
		DistanceLocationSize, BottomDotCharacter, CharacterInputScale);
	return BoolValue1 && BoolValue2;
}

bool ULadderCustomMovementComponent::CheckEnterTop(FVector CharacterFootLocation, FVector CharacterInputDirection, float CharacterInputScale)
{
	FVector TopLocation = CurLadderCharacter->GetLadderTopLocation();
	FVector DistanceLocation = CharacterFootLocation - TopLocation;
	bool BoolValue1 = DistanceLocation.Size() <= 50.0f;

	FVector TopForwardVec = CurLadderCharacter->Top->GetForwardVector();
	float TopDotCharacter = UKismetMathLibrary::Dot_VectorVector(TopForwardVec, CharacterInputDirection);
	float CharacterDotTop = UKismetMathLibrary::Dot_VectorVector(CharacterInputDirection, TopForwardVec);

	bool BoolValue2 = TopDotCharacter <= -0.7f && CharacterInputScale > 0.3f;
	bool BoolValue3 = TopDotCharacter >= 0.7f && CharacterInputScale < -0.3f;
	return BoolValue1 && (BoolValue2 || BoolValue3);
}

bool ULadderCustomMovementComponent::CheckEnterMiddle(FVector CharacterFootLocation, FVector CharacterInputDirection, float CharacterInputScale)
{
	FVector BottomLocation = CurLadderCharacter->GetLadderBottomLocation();
	FVector DistanceLocation = CharacterFootLocation - BottomLocation;
	bool BoolValue1 = DistanceLocation.Size() <= 50.0f;

	FVector TopForwardVec = CurLadderCharacter->Top->GetForwardVector();
	float TopDotCharacter = UKismetMathLibrary::Dot_VectorVector(TopForwardVec, CharacterInputDirection);
	float CharacterDotTop = UKismetMathLibrary::Dot_VectorVector(CharacterInputDirection, TopForwardVec);

	bool BoolValue2 = TopDotCharacter >= 0.7f && CharacterInputScale > 0.8f;
	bool BoolValue3 = TopDotCharacter <= -0.7f && CharacterInputScale < -0.8f;
	return BoolValue1 && (BoolValue2 || BoolValue3);
}

void ULadderCustomMovementComponent::StartEnterLadderBottom()
{
	CS3_Display(CS3DebugType::CL_Actor, TEXT("ULadderCustomMovementComponent::Debug[EntityID=%d]=======StartEnterLadderBottom"),
		GetPlayerCharacter()->GetSelfEntity()->ID());

	//�����л�����������ɣ��ٽ���ײ�
	TWeakObjectPtr<ULadderCustomMovementComponent> DelayThisPtr(this);
	if (EnterLadderHandle.IsValid())
	{
		GetPlayerCharacter()->OnModelChangeAppearanceOverDelegate.Remove(EnterLadderHandle);
		EnterLadderHandle.Reset();
	}
	EnterLadderHandle = GetPlayerCharacter()->OnModelChangeAppearanceOverDelegate.AddLambda([DelayThisPtr]()
		{
			if (DelayThisPtr.IsValid())
			{
				ULadderCustomMovementComponent* ThisPtr = DelayThisPtr.Get();
				ThisPtr->EnterBottom();
				ThisPtr->GetPlayerCharacter()->OnModelChangeAppearanceOverDelegate.Remove(ThisPtr->EnterLadderHandle);
			}
		});
	if (GetPlayerCharacter()->ActorIsPlayer())//ֻ�б�����Ҳ���Ҫ�����������߼�
	{
		//֪ͨ�������л���������
		CurLadderCharacter->EntityEnterLadder(GetPlayerCharacter()->GetSelfEntity()->ID());
	}

	//���ݵ���������Ҫ�޸ĵ�λ��(�л���������)
	/*UGameObjectInterface* Interface = Cast<UGameObjectInterface>(UGolbalBPFunctionLibrary::GetInterfaceByName(TEXT("GameObjectInterface"), 0));
	FString ModelId = "SK_M_02YuXu_Ladder";
	FString ActionId = "";
	Interface->ChangeShowPosture(ModelId, ActionId, ActionId);
	CurCharacterMovement->StopMovementImmediately();*/
}

void ULadderCustomMovementComponent::EnterBottom()
{
	CS3_Display(CS3DebugType::CL_Actor, TEXT("ULadderCustomMovementComponent::Debug[EntityID=%d]=======EnterBottom"),
		GetPlayerCharacter()->GetSelfEntity()->ID());

	IsCustomLadderModel = true;

	//�������в�����EnterBottom�����붯���޹أ�ֻ��¼״̬����ΪLadderEnterBottom������û�и��˶�λ�Ƶģ�
	IsRootMotionHaveUpAction = false;
	GetPlayerCharacter()->GetCharacterMovement()->SetMovementMode(MOVE_Custom, (uint8)CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_ROOT_MOTION);
	TempCustomMovementMode = CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_ROOT_MOTION;

	GetPlayerCharacter()->GetCharacterMovement()->Velocity = FVector(0.0f,0.0f,0.0f);
	GetPlayerCharacter()->GetCharacterMovement()->bOrientRotationToMovement = false;
	GetPlayerCharacter()->GetCharacterMovement()->bUseControllerDesiredRotation = false;

	FVector BottomLocation = CurLadderCharacter->GetLadderBottomLocation();
	FRotator BottomRotator = CurLadderCharacter->GetLadderBottomRotation();
	float UnscaledCapsuleHalfHeight = GetPlayerCharacter()->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	BottomLocation.Z += UnscaledCapsuleHalfHeight;
	GetPlayerCharacter()->SetActorLocationAndRotation(BottomLocation, BottomRotator);

	CS3_Display(CS3DebugType::CL_Undefined, TEXT("ULadderCustomMovementComponent::[BottomLocation=(%f,  %f,  %f)]"),
		BottomLocation.X, BottomLocation.Y, BottomLocation.Z);

	FName LadderEnterBottom = "LadderEnterBottom";
	FActionOverDelegate ActionOverDelegate;
	FActionBlendOutDelegate ActionBlendOutDelegate;
	ActionBlendOutDelegate.AddUObject(this, &ULadderCustomMovementComponent::ActionEnterBottomBlendOutOver);
	GetPlayerCharacter()->PlayAction(LadderEnterBottom, 0.0f, ActionOverDelegate, ActionBlendOutDelegate);

	NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_ENTER_BOTTOM);
}

void ULadderCustomMovementComponent::StartFallToLadder()
{
	ExitMiddle();
}

void ULadderCustomMovementComponent::EnterTop()
{
	//Ԥ���Ժ���չ��Ŀǰû����
}

void ULadderCustomMovementComponent::EnterMiddle()
{
	//Ԥ���Ժ���չ��Ŀǰû����
}

void ULadderCustomMovementComponent::ActionEnterBottomBlendOutOver(ACharacter * Character, FACTION_DATA Action)
{
	GetPlayerCharacter()->GetCharacterMovement()->SetMovementMode(MOVE_Custom, (uint8)CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_LADDER);
	TempCustomMovementMode = CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_LADDER;

	NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_MOVE);
}

void ULadderCustomMovementComponent::CheckExitLadder(float InputScale)
{
	if (IsLadderMovement() && !IsExitLaddering)
	{
		FVector ActorLoccation = GetPlayerCharacter()->GetActorLocation();
		float CapsuleHalfHeight = GetPlayerCharacter()->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
		FVector CharacterFootLoccation = FVector(ActorLoccation.X, ActorLoccation.Y, ActorLoccation.Z - CapsuleHalfHeight);
		bool IsExitBottom = CheckExitBottom(InputScale, CharacterFootLoccation);
		if (IsExitBottom)
		{
			ExitBottom();
		}
		else
		{
			bool IsExitTop = CheckExitTop(InputScale, CharacterFootLoccation);
			if (IsExitTop)
			{
				ExitTop();
			}
			else
			{
				//�����Ǽ���м������˳����ӵ��߼�(��CS3��Ŀ����Ҫ�����˳���ʽ)
			}
		}
	}
}

bool ULadderCustomMovementComponent::CheckExitBottom(float InputScale, FVector CharacterBottomLocation)
{
	if (!CurLadderCharacter)
	{
		return false;
	}
	FVector BottomLocation = CurLadderCharacter->GetLadderBottomLocation();
	FVector DistanceLocation = CharacterBottomLocation - BottomLocation;
	float DistanceLocationSize = DistanceLocation.Size();
	return InputScale < -0.8f && DistanceLocationSize <= 1.0f;
}

bool ULadderCustomMovementComponent::CheckExitTop(float InputScale, FVector CharacterBottomLocation)
{
	if (!CurLadderCharacter)
	{
		return false;
	}
	FVector TopLocation = CurLadderCharacter->GetLadderTopLocation();
	FVector DistanceLocation = CharacterBottomLocation - TopLocation;
	float DistanceLocationSize = DistanceLocation.Size();
	return InputScale > 0.8f && DistanceLocationSize <= 1.0f;
}

bool ULadderCustomMovementComponent::CheckExitMiddle(float InputScale, FVector CharacterBottomLocation)
{
	return false;
	//Ԥ���Ժ���չ��Ŀǰû����
}

void ULadderCustomMovementComponent::ExitBottom()
{
	CS3_Display(CS3DebugType::CL_Actor, TEXT("ULadderCustomMovementComponent::Debug[EntityID=%d]=======ExitBottom"),
		GetPlayerCharacter()->GetSelfEntity()->ID());

	IsExitLaddering = true;
	//�ָ���б10��
	ResetCharacterPitch();

	//�������в�����EnterBottom�����붯���޹أ�ֻ��¼״̬����ΪLadderEnterBottom������û�и��˶�λ�Ƶģ�
	IsRootMotionHaveUpAction = false;
	GetPlayerCharacter()->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	TempCustomMovementMode = CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_ROOT_MOTION;

	FName LadderEnterBottom = "LadderExitBottom";
	FActionOverDelegate ActionOverDelegate;
	FActionBlendOutDelegate ActionBlendOutDelegate;
	ActionBlendOutDelegate.AddUObject(this, &ULadderCustomMovementComponent::ActionExitBottomOver);
	GetPlayerCharacter()->PlayAction(LadderEnterBottom, 0.0f, ActionOverDelegate, ActionBlendOutDelegate);

	NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_EXIT_BOTTOM);
}

void ULadderCustomMovementComponent::ExitTop()
{
	CS3_Display(CS3DebugType::CL_Actor, TEXT("ULadderCustomMovementComponent::Debug[EntityID=%d]=======ExitTop"),
		GetPlayerCharacter()->GetSelfEntity()->ID());

	IsExitLaddering = true;
	//�ָ���б10��
	ResetCharacterPitch();

	IsRootMotionHaveUpAction = true;
	GetPlayerCharacter()->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	TempCustomMovementMode = CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_ROOT_MOTION;

	FName LadderEnterBottom = "LadderExitTop";
	FActionOverDelegate ActionOverDelegate;
	FActionBlendOutDelegate ActionBlendOutDelegate;
	ActionBlendOutDelegate.AddUObject(this, &ULadderCustomMovementComponent::ActionExitTopOver);
	GetPlayerCharacter()->PlayAction(LadderEnterBottom, 0.0f, ActionOverDelegate, ActionBlendOutDelegate);

	NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_EXIT_TOP);
}

void ULadderCustomMovementComponent::ExitMiddle()
{
	CS3_Display(CS3DebugType::CL_Actor, TEXT("ULadderCustomMovementComponent::Debug[EntityID=%d]=======ExitMiddle"),
		GetPlayerCharacter()->GetSelfEntity()->ID());

	IsExitLaddering = true;
	IsCustomLadderModel = false;
	//�ָ���б10��
	ResetCharacterPitch();

	IsRootMotionHaveUpAction = false;
	GetPlayerCharacter()->GetCharacterMovement()->SetMovementMode(MOVE_Falling);
	TempCustomMovementMode = CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_NONE;

	GetPlayerCharacter()->GetCharacterMovement()->bOrientRotationToMovement = true;
	GetPlayerCharacter()->GetCharacterMovement()->bUseControllerDesiredRotation = true;

	NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_FALL_EXIT);
}

void ULadderCustomMovementComponent::ActionExitBottomOver(ACharacter * Character, FACTION_DATA Action)
{
	IsExitLaddering = false;
	IsCustomLadderModel = false;

	GetPlayerCharacter()->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	TempCustomMovementMode = CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_NONE;
	GetPlayerCharacter()->GetCharacterMovement()->bOrientRotationToMovement = true;
	GetPlayerCharacter()->GetCharacterMovement()->bUseControllerDesiredRotation = true;

	if (GetPlayerCharacter()->ActorIsPlayer())//ֻ�б�����Ҳ���Ҫ�����������߼�
	{
		//֪ͨ�������л���PC��׼������
		CurLadderCharacter->EntityExitLadder(GetPlayerCharacter()->GetSelfEntity()->ID());
	}

	NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_STAND);
}

void ULadderCustomMovementComponent::ActionExitTopOver(ACharacter * Character, FACTION_DATA Action)
{
	IsExitLaddering = false;
	IsCustomLadderModel = false;

	GetPlayerCharacter()->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	TempCustomMovementMode = CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_NONE;
	GetPlayerCharacter()->GetCharacterMovement()->bOrientRotationToMovement = true;
	GetPlayerCharacter()->GetCharacterMovement()->bUseControllerDesiredRotation = true;

	if (GetPlayerCharacter()->ActorIsPlayer())//ֻ�б�����Ҳ���Ҫ�����������߼�
	{
		//֪ͨ�������л���PC��׼������
		CurLadderCharacter->EntityExitLadder(GetPlayerCharacter()->GetSelfEntity()->ID());
	}

	NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_STAND);
}

void ULadderCustomMovementComponent::LadderFallLand()
{
	if (IsExitLaddering)
	{
		if (IsValid(GetPlayerCharacter()->GetBaseAnimInstance()))
		{
			GetPlayerCharacter()->GetBaseAnimInstance()->PlayFallLandAction();
		}

		if (GetPlayerCharacter()->ActorIsPlayer())//ֻ�б�����Ҳ���Ҫ�����������߼�
		{
			//֪ͨ�������л���PC��׼������
			CurLadderCharacter->EntityExitLadder(GetPlayerCharacter()->GetSelfEntity()->ID());
		}

		IsExitLaddering = false;
		NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_FALL_EXIT_LAND);
	}
}

APlayerCharacter* ULadderCustomMovementComponent::GetPlayerCharacter()
{
	return Cast<APlayerCharacter>(GetOwner());
}

void ULadderCustomMovementComponent::NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE InClimbLadderState, float InLadderStepPos /*= 0.0f*/)
{
	//��ȡ���ؿ��Ƶ���ҵ�interface[0��ʾ�ǿ������]
	URoleStateInterface* RoleStateInterface = Cast<URoleStateInterface>(UGolbalBPFunctionLibrary::GetCS3PlayerEntity() ? 
		UGolbalBPFunctionLibrary::GetCS3PlayerEntity()->Interface_Cache.StateInterface : nullptr);
	if (!IsValid(RoleStateInterface))
	{
		return;
	}
	RoleStateInterface->RequestUpdateClimbLadderActionStepPos(InLadderStepPos);//������������posֵ

	if (CurClimbLadderState == InClimbLadderState)
	{
		return;
	}
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("UJumpComponent::ChangeJumpStateToServer[CurClimbLadderState=%d, ClimbLadderState=%d]"),
		(int32)CurClimbLadderState, (int32)InClimbLadderState);
	CurClimbLadderState = InClimbLadderState;
	RoleStateInterface->RequestChangeClimbLadderState(CurClimbLadderState);///֪ͨ���������������ͻ��˱������ǵı���
}

void ULadderCustomMovementComponent::SetSynchroPlayerClimbLadderState(CLIMB_LADDER_STATE InClimbLadderState, float InLadderStepPos /*= 0.0f*/)
{
	CurClimbLadderState = InClimbLadderState;
	ClimbLadderActionFramePos = InLadderStepPos;
	switch (CurClimbLadderState)
	{
	case CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_STAND:
	case CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_ENTER_ZONE:
	case CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_EXIT_BOTTOM:
	case CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_EXIT_TOP:
	case CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_FALL_EXIT:
	case CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_FALL_EXIT_LAND:
	{
		IsCustomLadderModel = false;
		break;
	}
	case CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_ENTER_BOTTOM:
	case CLIMB_LADDER_STATE::CLIMB_LADDER_STATE_MOVE:
	{
		IsCustomLadderModel = true;
		break;
	}
	default:
	{
		break;
	}
	}
}

CONTROL_COMPILE_OPTIMIZE_END
