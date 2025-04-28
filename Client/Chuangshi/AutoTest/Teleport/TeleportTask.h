// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AutoTest/BaseTest/BaseTask.h"
#include "TeleportTask.generated.h"

/*
* �ļ����ƣ�TeleportTask.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UTeleportTask : public UBaseTask
{
	GENERATED_BODY()
	
public:
	UTeleportTask();
	/****		need to override		****/
	virtual void InitParam() override;	//��������һ��������
	virtual void BeginTask() override;	//��ʼִ��task
	virtual void TickObject() override;		//tick task
	virtual bool Condition() override;
	virtual void EndTask() override;		//����ִ��task
	/****		need to override		****/

public:
	FString Position;	//�Կո�ָ���"0 0 0"
	FString Direction;	//�Կո�ָ���"0 0 0"
	FString ScriptID;

	
	
};
