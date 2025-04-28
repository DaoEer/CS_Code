// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TrapInterface.h"
#include "TrapBattleFlagInterface.generated.h"

/*
* �ļ����ƣ�TrapBattleFlagInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-02-26
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UTrapBattleFlagInterface : public UTrapInterface
{
	GENERATED_BODY()
		typedef UTrapInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:

	UTrapBattleFlagInterface();
	~UTrapBattleFlagInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.TrapBattleFlagInterface'"); } //��ȡ��ͼ����·��
	UFUNCTION(BlueprintCallable, Category = "TrapBattleFlagInterface")
	void OnRep_occurProgress();
	UFUNCTION(BlueprintCallable, Category = "TrapBattleFlagInterface")
	void OnRep_maxProgress();
	UFUNCTION(BlueprintCallable, Category = "TrapBattleFlagInterface")
	void OnRep_barracksBelongType();
};
