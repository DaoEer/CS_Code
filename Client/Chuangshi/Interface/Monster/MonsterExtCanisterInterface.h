// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtCanisterInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtCanisterInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-02-17
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtCanisterInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()

public:
	UMonsterExtCanisterInterface();

	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtCanisterInterface'"); } //��ȡ��ͼ����·��

	UFUNCTION(BlueprintCallable)
		void AddTrap();

	void OnPlayerBeginOverlap();
	void OnPlayerEndOverlap();

	// ����������
	UFUNCTION(BlueprintCallable)
		void OperationCanister(const int32& EntityID_);
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_OnOperationCanister(const int32& Ammo, float CdTime);
	virtual void InitBlueCB() override;

};