// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameData/CsvTableRowBase.h"
#include "GameData/TickObject.h"
#include "AutoTest/AutoTestDebug.h"
#include "BaseTask.generated.h"

/*
* �ļ����ƣ�BaseTash.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

USTRUCT(BlueprintType)
struct CHUANGSHI_API FTASKDATA : public FCSV_TABLE_ROW_BASE
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "TaskData")
		FString ClassScript;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "TaskData")
		int32 Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "TaskData")
		FString Param1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "TaskData")
		FString Param2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "TaskData")
		FString Param3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "TaskData")
		FString Param4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "TaskData")
		FString Param5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "TaskData")
		FString Comment;
};


/**
 *���ڴ����Զ��������еĻ������� 
 *
 */

UCLASS(BlueprintType, Blueprintable)
class CHUANGSHI_API UBaseTask : public UTickObject
{
	GENERATED_BODY()
	
public:
	UBaseTask();
	void SetParams(const FTASKDATA& TaskData);	//�ڴ�������֮����ã�����Ĭ�ϲ���һ��������
	void StartTick();		//�ڿ�ʼ��taskʱ����������tick����
	/****		need to override		****/
	virtual void InitParam() {}	//��������һ��������
	virtual void BeginTask() {}	//��ʼִ��task
	virtual void TickObject() override;		//tick task
	virtual bool Condition() { return true; }
	virtual void EndTask() {
		IsComplete = true; bCanEverTick = false; AT_INFO(TEXT("Close TickObject ->Index[%d]"), Index);
	}		//����ִ��task
	/****		need to override		****/

public:
	//��ǵ�ǰ�����Ƿ����
	bool IsComplete; 
	int32 Index;
	FString Param1;
	FString Param2;
	FString Param3;
	FString Param4;
	FString Param5;
	FString Comment;

};
