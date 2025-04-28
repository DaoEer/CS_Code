// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/NPC/ClientGameCharacter.h"
#include "GameData/FlyBindMeshData.h"
#include "FlyBindCharacter.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class CHUANGSHI_API AFlyBindCharacter : public AClientGameCharacter
{
	GENERATED_BODY()
public:
	AFlyBindCharacter();
	void initFlyBindActor(const FFLY_BIND_MESH_DATA* Config,int32 PlayerId);

	UFUNCTION(BlueprintImplementableEvent, Category = "Effect")
		void OnInitFromConfig();

	UFUNCTION(BlueprintImplementableEvent, Category = "Effect")
		void UseSkill(int32 CasterID = 0, int32 TargetID = 0);

	///·����Դ
	UPROPERTY(BlueprintReadOnly)
		TSubclassOf<ABaseSplineAsset> SplineAsset;
	///ѭ������
	UPROPERTY(BlueprintReadOnly)
		int32 LoopNumber;

	///�ƶ��ٶ�
	UPROPERTY(BlueprintReadWrite)
		float FlySpeed;

	///�Ƿ�ʼ����λ��
	UPROPERTY(BlueprintReadOnly)
		bool bIsAbsoluteLocation;

	///�Ƿ�ʼ������ת
	UPROPERTY(BlueprintReadOnly)
		bool bIsAbsoluteRotation;

	///�Ƿ�ʼ�����С
	UPROPERTY(BlueprintReadOnly)
		bool bIsAbsoluteScale;

	UPROPERTY(BlueprintReadOnly)
		TArray<FString> AnimID;

	///������Чid�б�
	UPROPERTY(BlueprintReadOnly)
		TArray<FString> EffectID;

	///���������ӳ�ʱ�䣬���ݶ�������˳�����á�
	UPROPERTY(BlueprintReadOnly)
		TArray<float> PlayTime;

	///��������
	UPROPERTY(BlueprintReadOnly)
		FLYBINDSKILL_STATE SkillType;
	///���
	UPROPERTY(BlueprintReadOnly)
		FName FlyModeBindSocket;
	///���ID
	UPROPERTY(BlueprintReadOnly)
		int32 PlayerID;

	///�󶨵�λ�úͳ���
	UPROPERTY(BlueprintReadOnly)
		FTransform FlyTransform;
	///�󶨵�λ�úͳ���
	UPROPERTY(BlueprintReadOnly)
		FTransform FlySplineTransform;
	
};
