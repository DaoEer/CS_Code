// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/Item/Equip.h"
#include "EquipPart.generated.h"

/*
* �ļ����ƣ�EquipPart.h
* ����˵�������Ʒװ������Ҫ�������ܴ���
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020-03-07
*/
UCLASS()
class CHUANGSHI_API UEquipPart : public UEquip
{
	GENERATED_BODY()

	typedef UEquip Super;
public:
	/**
	*�麯�����Ƿ����ʹ����Ʒ
	*
	*@return bool ����ʹ����Ʒ����TRUE�����򷵻�FALSE
	*/
	virtual bool IsCanUse() override;
	
	virtual FString GetItemName()override;

	/**
	*virtual����ȡ��������ֵ
	*
	*@return FString ��������ֵ
	*/
	virtual FString GetAttachPropertyStr() override;

	virtual void InitDynamicDataForJson(FString jsonStr) override;

	//����
	void OnQuenching();
public:
	// ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equip | Property")
		int32 quenchingNum;
	
};
