// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TrapBattleFlagInterface.h"
#include "TrapBarracksInterface.generated.h"

/*
* �ļ����ƣ�TrapBarracksInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-02-28
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UTrapBarracksInterface : public UTrapBattleFlagInterface
{
	GENERATED_BODY()
		typedef UTrapBattleFlagInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:

	UTrapBarracksInterface();
	~UTrapBarracksInterface();
	static FString GetName() { return TEXT("TrapBarracksInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_TrapBarracksInterface.BP_TrapBarracksInterface_C'"); } //��ȡ��ͼ����·��
		
	UFUNCTION(BlueprintCallable)
		void AddTrap();

	void OnPlayerBeginOverlap();
	void OnPlayerEndOverlap();

	/**
	* BlueprintCallable���������Ҹ������ӽ���
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable)
	void OpenBarracksArmyWin(const int32& EntityID_);

	UFUNCTION(BlueprintImplementableEvent, Category = "ServerCharacter")
	void OnHideBarracksArmyWin();///<���ظ������ӽ���

};
