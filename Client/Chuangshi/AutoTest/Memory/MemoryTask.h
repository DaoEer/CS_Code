// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AutoTest/BaseTest/BaseTask.h"
#include "MemoryTask.generated.h"

/*
* �ļ����ƣ�MemoryTask.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

USTRUCT(BlueprintType)
struct CHUANGSHI_API FMEMRECORD
{
	GENERATED_USTRUCT_BODY()

public:
	FDateTime Time;
	float UsePhysical;	//ʹ���˶���M�ڴ�
};

/**
 * 
 */
UCLASS(BlueprintType)
class CHUANGSHI_API UMemoryTask : public UBaseTask
{
	GENERATED_BODY()
	
public:
	UMemoryTask();
	virtual void InitParam() override;	//��������һ��������
	virtual void TickObject() override;		//tick task
	virtual bool Condition() override;

	//��ȡ�˵�ͼ��ƽ��ʹ���ڴ�
	int32 GetAvgUseMemory();
	int32 GetMinUseMemory();
	int32 GetMaxUseMemory();

public:
	float LifeTime;		//��Ҫ��¼��ʱ��
	UPROPERTY(BlueprintReadWrite, Category = "Object")
		TArray<FMEMRECORD> MemRecords;
	
	
};
