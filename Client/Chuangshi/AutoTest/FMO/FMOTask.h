// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AutoTest/BaseTest/BaseTask.h"
#include "FMOTask.generated.h"

/*
* �ļ����ƣ�FMOTask.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

USTRUCT(BlueprintType)
struct CHUANGSHI_API FFMORECORD
{
	GENERATED_USTRUCT_BODY()

public:
	FDateTime Time;
	float FPS;	//FPS
	float UsePhysical; //ʹ�������ڴ�
	float UseVirtual;	//ʹ�õ������ڴ�
	int32 ObjCounts;	//�������ᱻGC��CDO����
	int32 GCObjCount;	//�ᱻGC�Ķ���
};

/**
 * ͳ��֡�ʣ��ڴ��UObject��������
 */
UCLASS(BlueprintType)
class CHUANGSHI_API UFMOTask : public UBaseTask
{
	GENERATED_BODY()
public:
	UFMOTask();
	virtual void InitParam() override;	//��������һ��������
	virtual void TickObject() override;		//tick task
	virtual bool Condition() override;

	//��ȡ�˵�ͼ��ƽ��֡��
	void GetAvgData(float& AvgFrame, float& AvgMemUse, int32& AvgObjCount);
	void GetMinData(float& MinFrame, float& MinMemUse, int32& MinObjCount);
	void GetMaxData(float& MaxFrame, float& MaxMemUse, int32& MaxObjCount);

	//��ȡ�����ڴ���
	FString GetLine();
	static FString GetTitle();

	//��ȡ����ڴ���
	FString GetVirtualLine();
	static FString GetVirtualTitle();

	//��ȡ��ϸ���
	FString GetDetailLine();
	static FString GetDetailTitle();
public:
	float LifeTime;		//��Ҫ��¼��ʱ��
	FString MapName;	//��ͼ��
	UPROPERTY(BlueprintReadWrite, Category = "Object")
		TArray<FFMORECORD> FMORecords;
	
	
	
};
