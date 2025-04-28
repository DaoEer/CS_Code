// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PerformanceComponent.generated.h"

/*
* �ļ����ƣ�PerformanceComponent.h
* ����˵��������ͳһ���������Ч����������
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-08-27
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UPerformanceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPerformanceComponent();

	// ���������ʱ���������д洢������
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// ���UID���б�
	FORCEINLINE void AddEffect(int32 EffectUID)
	{
		EffectUIDList.Add(EffectUID);
	}

private:	

	// �洢���ӵ�UID��ֻ���룬���Ƴ�
	TArray<int32> EffectUIDList;
	
};
