// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//UE4
#include "Engine/EngineTypes.h"
//CS3����
#include "GameData/RoleJumpData.h"
#include "Engine/DataTable.h"
#include "GameData/GameDeFine.h"
//CS3
#include "Components/ActorComponent.h"
#include "JumpComponent.generated.h"

class ACharacter;
class UCharacterMovementComponent;

DECLARE_STATS_GROUP(TEXT("UJumpComponent"), STATGROUP_UJumpComponent, STATCAT_Advanced);

/*
* �ļ����ƣ�JumpComponent.h
* ����˵�����������ǵ���Ծ����
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2017-10-09
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHUANGSHI_API UJumpComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UJumpComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void InitJumpData();

	///��ʼ������Ծ����ִ��
	void OnStartActiveJump();
	///��ʼ������Ծ����ִ��
	void OnStartPassiveJump(float Height);
	///������Ծ��������
	void SetJumpMaxCountBySkill();
	///������Ծ�Ĵ���
	void ResetJumpCount();
	///��Ծģ�ͷ����ı�ʱ
	void MovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode /*= 0*/);
	///������Ծ״̬
	void UpdateJumpState(JUMP_SHOW_STATE InJumpShowState);
	
	/**
	*��ʼִ�б�Ե��������
	*@param bUpJump  �Ƿ���������true���ϣ�false���£�
	*@param JumpHeight	�����߶�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "JumpComponent")
		void OnStartLedgesJump(bool bUpJump, float JumpHeight);

	void ChangeJumpStateToServer(JUMP_SHOW_STATE JumpState);///������Ծ״̬��֪ͨ������

	void SetJumpShowType(JUMP_SHOW_TYPE InJumpShowType);///������Ծ��������
	void SetJumpHeight(float JumpHeight);///���ÿ���Ծ�߶�

	bool IsCanJump();///����ܷ���Ծ
	void SetSynchroPlayerJumpState(JUMP_SHOW_STATE InJumpShowState);///����ͬ��ʱ������ɫ����Ծ״̬(�Ǳ��ؿ��Ƶ�����)
	JUMP_SHOW_STATE GetCurJumpShowState();///��ȡ��ǰ��Ծ����״̬

protected:
	virtual void BeginPlay() override;

private:
	void CheckJumpFalling();///�Ƿ�����Ծ���������

	ACharacter* GetOwnerCharacter();

public:
	UPROPERTY(BlueprintReadOnly, Category = CameraRock)
		bool IsJumpState = false;//�Ƿ���Ծ������(����IsTheFalling��IsTheUping)

	UPROPERTY(BlueprintReadOnly, Category = CameraRock)
		bool IsTheLand = true;//�Ƿ���½��

	UPROPERTY(BlueprintReadOnly, Category = CameraRock)
		bool IsTheFalling = false;//����������

	UPROPERTY(BlueprintReadOnly, Category = CameraRock)
		bool IsTheUping = false;//����������

	int32 PlayerJumpMaxCount;///�������JumpMaxCount�������޴�ʹ��PlayerJumpMaxCount�����ж�

protected:

private:
	FVector OldLoctionForJumpHorizontal;///��¼���λ��-��Ծˮƽ�ƶ�ʱ
	JUMP_SHOW_STATE CurJumpShowState;

	float LedgesJumpHeight = 0.0f;///��Ե������Ծ�߶�
		
};
