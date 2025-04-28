// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtShowTopCountDownInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtShowTopCountDownInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2018-04-23
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtShowTopCountDownInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()

public:
	UMonsterExtShowTopCountDownInterface();
	~UMonsterExtShowTopCountDownInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtShowTopCountDownInterface'"); } //��ȡ��ͼ����·��

	virtual void InitBlueCB() override;

	/**
	*��ʾͷ������ʱ
	*
	*param remainTime ʣ��ʱ��
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|MonsterExtShowTopCountDownInterface")
		void CLIENT_ShowRemainLifeTime(const float& remainTime);
};
