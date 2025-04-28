// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameData/TickObject.h"
#include "BaseTask.h"
#include "AutoTest/AutoTestDebug.h"
#include "BaseProfile.generated.h"

/*
* �ļ����ƣ�BaseProfile.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

UCLASS(BlueprintType, Blueprintable)
class CHUANGSHI_API UBaseProfile : public UTickObject
{
	GENERATED_BODY()
	
public:
	UBaseProfile();

	//��ʼִ�м�¼
	void StartRecord();
	virtual void StartTickTask();
	/****		need to override		****/
	virtual void LoadCfg();
	/****		need to override		****/
	virtual void TickObject() override;
	virtual void EndRecord() {}		//һ�㴦������csv����
	bool IsComplete();

	UBaseTask* GetCurrTask();

	
public:
	UPROPERTY()
	TArray<UBaseTask*> Tasks;

	//��ǰִ�е��ڼ���task
	int32 CurrTaskIndex = 0;
	
};
