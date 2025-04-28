// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTask.h"
#include "Util/CS3Debug.h"


CONTROL_COMPILE_OPTIMIZE_START

UBaseTask::UBaseTask()
	: Super()
{
	CustomTimeDilation = 1.0;
	IsComplete = false;
	
}

void UBaseTask::SetParams(const FTASKDATA& TaskData)
{
	Index = TaskData.Index;
	Param1 = TaskData.Param1;
	Param2 = TaskData.Param2;
	Param3 = TaskData.Param3;
	Param4 = TaskData.Param4;
	Param5 = TaskData.Param5;
}

void UBaseTask::StartTick()
{
	InitParam();
	BeginTask();
	bCanEverTick = true;		//�ⲿ���ÿ��ſ���tick����
	AT_INFO(TEXT("Open TickObject ->Index[%d]"), Index);
}

void UBaseTask::TickObject()
{
	if (!IsPlaying())	return;
	if (Condition())
	{
		EndTask();
	}
}

CONTROL_COMPILE_OPTIMIZE_END
