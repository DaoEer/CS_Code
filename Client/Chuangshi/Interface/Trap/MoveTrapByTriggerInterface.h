// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TrapInterface.h"
#include "MoveTrapByTriggerInterface.generated.h"

/*
* �ļ����ƣ�MoveTrapByTriggerInterface.h
* ����˵����
* �ļ����ߣ�zhutianyang
* Ŀǰά����chendongyong
* ����ʱ�䣺2017-10-17
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMoveTrapByTriggerInterface : public UTrapInterface
{
	GENERATED_BODY()
	typedef UTrapInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMoveTrapByTriggerInterface();
	~UMoveTrapByTriggerInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MoveTrapByTriggerInterface'"); } //��ȡ��ͼ����·��

	
};
