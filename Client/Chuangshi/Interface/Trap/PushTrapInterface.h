// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TrapInterface.h"
#include "PushTrapInterface.generated.h"

/*
* �ļ����ƣ�PushTrapInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-10-25
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UPushTrapInterface : public UTrapInterface
{
	GENERATED_BODY()
	typedef UTrapInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:

	UPushTrapInterface();
	~UPushTrapInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.TrapInterface'"); } //��ȡ��ͼ����·��
};
