// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AutoTest/BaseTest/BaseTask.h"
#include "AutoTest/AutoTestDebug.h"
#include "ObjectTask.generated.h"

/*
* �ļ����ƣ�ObjectTask.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

USTRUCT(BlueprintType)
struct CHUANGSHI_API FOBJRECORD
{
	GENERATED_USTRUCT_BODY()

public:
	FDateTime Time;
	int32 ObjCounts;	//�������ᱻGC��CDO����
	int32 GCObjCounts;	//�ᱻGC�Ķ���
};

/**
 * ��¼�ͻ��˵�UObject����
 */
UCLASS(BlueprintType)
class CHUANGSHI_API UObjectTask : public UBaseTask
{
	GENERATED_BODY()
public:
	UObjectTask();
	virtual void InitParam() override;	//��������һ��������
	virtual void TickObject() override;		//tick task
	virtual bool Condition() override;

	//��ȡ�˵�ͼ�ϴ�����UObject��ƽ������
	int32 GetAvgObjCount();	
	int32 GetMinObjCount();
	int32 GetMaxObjCount();

public:
	float LifeTime;		//��Ҫ��¼��ʱ��
	UPROPERTY(BlueprintReadWrite, Category = "Object")
		TArray<FOBJRECORD> ObjRecords;

};
