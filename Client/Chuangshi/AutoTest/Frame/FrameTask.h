// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AutoTest/BaseTest/BaseTask.h"
#include "FrameTask.generated.h"

/*
* �ļ����ƣ�FrameTask.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/


USTRUCT(BlueprintType)
struct CHUANGSHI_API FFRAMERECORD
{
	GENERATED_USTRUCT_BODY()

public:
	FDateTime Time;
	float FPS;	//FPS
};

/**
 * ��¼�ͻ��˵�FPS
 */
UCLASS(BlueprintType)
class CHUANGSHI_API UFrameTask : public UBaseTask
{
	GENERATED_BODY()
public:
	UFrameTask();
	virtual void InitParam() override;	//��������һ��������
	virtual void TickObject() override;		//tick task
	virtual bool Condition() override;

	//��ȡ�˵�ͼ��ƽ��֡��
	int32 GetAvgFrame();
	int32 GetMinFrame();
	int32 GetMaxFrame();

public:
	float LifeTime;		//��Ҫ��¼��ʱ��
	UPROPERTY(BlueprintReadWrite, Category = "Object")
		TArray<FFRAMERECORD> FrameRecords;
	
	
	
};
