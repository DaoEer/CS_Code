// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// UE4
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
// ��������
#include "GameData/ModelPartData.h"
#include "CollisionComponent.generated.h"

/*
* �ļ����ƣ�CollisionComponent.h
* ����˵������ײ���
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-02-07
*/

struct FACTION_DATA;
//enum class WATER_TYPE_ENUM;

UCLASS(BlueprintType)
class CHUANGSHI_API UCollisionComponent : public UActorComponent
{
	GENERATED_BODY()
public:	

	void UpdateModelCollision();///<����ģ����ײ

	bool UpdateModelCollisionByFlag();

	bool UpdateModelCollisionByState();

	bool UpdateModelCollisionByChannel();

	void SetPlayerCollisionByNormal();///<���ÿͻ�������Լ�������ײ

	void SetPlayerCollisionByCast();///<���ÿͻ������ʩ��ʱ����ײ

	///<���ǵ���Ҫ���Ҳ��Ҫ������ײͨ���������������һ��Ĭ��ֵ������������ڲ�ʵ��
	void SetPlayerCollisionResponseToChannel(ECollisionChannel Channel, UPrimitiveComponent* Comp = nullptr);

	// ��ʼ������Mesh�ͽ��������ײ
	void InitCollision();

	// �ر�ģ��������ײ��һ����Actor������ʱ����
	void DisableAllCollision();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// ����ˮ����ײ
	UFUNCTION(BlueprintCallable, Category = "CollisionComponent")
	static void SetWaterCollision(UPrimitiveComponent* Component, WATER_TYPE_ENUM WaterType);

private:
	
	// ��ǰ��������ʹ�õ���ײͨ�� 24 �� 31 (ECC_GameTraceChannel11 - ECC_GameTraceChannel18)��ÿһ֡ˢ��Ϊ-1
	int32 CurrentTrace = -1;

	// ��ǰ��ײ��־λ�Ļ���
	int64 FlagCache = 0;

	FDelegateHandle BlockMeshHandle;
};
