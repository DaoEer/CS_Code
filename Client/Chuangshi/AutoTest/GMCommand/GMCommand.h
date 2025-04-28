// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AutoTest/BaseTest/BaseTask.h"
#include "GMCommand.generated.h"

/*
* �ļ����ƣ�GMCommand.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UGMCommand : public UBaseTask
{
	GENERATED_BODY()
	
public:
	UGMCommand();
	/****		need to override		****/
	virtual void InitParam() override;	//��������һ��������
	virtual void BeginTask() override;	//��ʼִ��task
	virtual void TickObject() override;		//tick task
	virtual bool Condition() override;
	virtual void EndTask() override;		//����ִ��task
	/****		need to override		****/

public:
	float LifeTime;		//ִ��ָ�����ֱ��������ɴ�����
	FString GMCmd;	//GMָ�����
	

};
