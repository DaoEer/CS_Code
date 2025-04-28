// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameData/CharacterData.h"
#include "GameData/GameDeFine.h"
#include "LadderCustomMovementComponent.generated.h"

/*
* �ļ����ƣ�LadderCustomMovementComponent.h
* ����˵�����������ǵ��������ӹ���
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2020-02-22
*/
class APlayerCharacter;
class AMonsterCharacter;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHUANGSHI_API ULadderCustomMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULadderCustomMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitLadderData();
	void ClearLadderData();//�˳�����ʱ������������

	void BeginOverlappedCustomMoveZone(AMonsterCharacter *LadderCharacter);//������������
	void EndOverlappedCustomMoveZone(AMonsterCharacter *LadderCharacter);//�뿪��������
	void AddMovementLadderUp(float InputScale);//�����ⲿWS��������

	bool IsLadderMovement();//�Ƿ�����ģʽ(�����ӹ��̡������ӡ������ӹ���)
	void StartFallToLadder();//��Ҵ����ӵ���
	void StartEnterLadderBottom();//F��������ɣ��ӵײ���������
	void LadderFallLand();//�����ӵ�����½

	void NotifyClimbLadderStateToServer(CLIMB_LADDER_STATE InClimbLadderState, float InLadderStepPos = 0.0f);//�������������״̬֪ͨ��������
	void SetSynchroPlayerClimbLadderState(CLIMB_LADDER_STATE InClimbLadderState, float InLadderStepPos = 0.0f);//ͬ�������ͻ��˱���
protected:

private:
	void UpdateCustomMovement(float DeltaTime);//�Զ����ƶ���tick����
	void UpdateLadderMovement(float DeltaTime);
	void UpdateRootMotion(float DeltaTime);
	float GetClimbLadderActionFramePos();//��ȡ�������������Ĳ���λ�õ�
	void ResetCharacterPitch();//�ָ���ҵ�pitch�Ƕ�

	void CheckEnterLadder(float InputScale);//�����ҽ�������
	bool CheckEnterBottom(FVector CharacterFootLocation, FVector CharacterInputDirection, float CharacterInputScale);
	bool CheckEnterTop(FVector CharacterFootLocation, FVector CharacterInputDirection, float CharacterInputScale);
	bool CheckEnterMiddle(FVector CharacterFootLocation, FVector CharacterInputDirection, float CharacterInputScale);
	void EnterBottom();
	void EnterTop();
	void EnterMiddle();
	void ActionEnterBottomBlendOutOver(ACharacter * Character, FACTION_DATA Action);

	void CheckExitLadder(float InputScale);//�������˳�����
	bool CheckExitBottom(float InputScale, FVector CharacterFootLocation);
	bool CheckExitTop(float InputScale, FVector CharacterFootLocation);
	bool CheckExitMiddle(float InputScale, FVector CharacterFootLocation);
	void ExitBottom();
	void ExitTop();
	void ExitMiddle();
	void ActionExitBottomOver(ACharacter * Character, FACTION_DATA Action);
	void ActionExitTopOver(ACharacter * Character, FACTION_DATA Action);

	APlayerCharacter* GetPlayerCharacter();

public:
	UPROPERTY(BlueprintReadWrite, Category = "LadderCustomMovementComponent")
		float ClimbLadderSpeed = 200;///<�����������ƶ��ٶ�(��/��)

	UPROPERTY(BlueprintReadWrite, Category = "LadderCustomMovementComponent")
		bool IsRootMotionHaveUpAction;///<�Ƿ���Ҫ�������˶���������

	UPROPERTY(BlueprintReadWrite, Category = "LadderCustomMovementComponent")
		CUSTOM_MOVEMENT_MODE_ENUM TempCustomMovementMode;///<����������Զ����ƶ�ģʽ

	UPROPERTY(BlueprintReadWrite, Category = "LadderCustomMovementComponent")
		float ClimbLadderActionFramePos;///<�м�������������λ��

	CLIMB_LADDER_STATE CurClimbLadderState;///<�Ǳ�����ҵ�����״̬��ͬ���ã�

protected:

	UPROPERTY(BlueprintReadOnly, Category = "LadderCustomMovementComponent")
		AMonsterCharacter* CurLadderCharacter;///��ǰ����

private: 
	bool IsOverLadderZone = false;//�Ƿ����������ײ����(��������������ӣ����о��뷽����ж�)
	bool IsCustomLadderModel = false;//�Ƿ�����ģʽ(�����ӹ��̡������ӡ������ӹ���)  [ע:�Ǳ������(ͬ��ʱ)���д�״̬]
	bool IsEnterLaddering = false;//�Ƿ�������ӹ�����
	bool IsExitLaddering = false;//�Ƿ�����ӹ�����

	float LadderStetPosOnStoping = 0.0f;

	FDelegateHandle EnterLadderHandle;
};
