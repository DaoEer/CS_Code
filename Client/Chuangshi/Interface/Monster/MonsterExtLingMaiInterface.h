// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtLingMaiInterface.generated.h"

/**
* �ļ����ƣ�MonsterExtLingMaiInterface.h
* ����˵����
* �ļ����ߣ�fangpengjun
* Ŀǰά����fangpengjun
* ����ʱ�䣺2021-01-19
 */
UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtLingMaiInterface : public UMonsterInterface
{
	GENERATED_BODY()
		typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtLingMaiInterface();
	~UMonsterExtLingMaiInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtLingMaiInterface'"); } //��ȡ��ͼ����·��
	virtual void InitBlueCB() override;
	void onEnterWorld() override;
	void onLeaveWorld() override;
	
	UFUNCTION(BlueprintCallable, Category = "cs3|MonsterExtLingMaiInterface")
	void OnRep_xianDamage();
	UFUNCTION(BlueprintCallable, Category = "cs3|MonsterExtLingMaiInterface")
	void OnRep_moDamage();
	
	void LingMaiBossHPChanged();

private:
	int32 xianDamage = 0;
	int32 moDamage = 0;		//0:δ��ռ��  1�����ռ��  2��bossռ��	
};
