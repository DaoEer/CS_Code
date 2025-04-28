// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/Item/ItemUse.h"
#include "ItemLearnShenTong.generated.h"

/*
* �ļ����ƣ�ItemLearnShenTong.h
* ����˵����ѧϰ��ͨ���ܵ���
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2020-08-24
*/
UCLASS()
class CHUANGSHI_API UItemLearnShenTong : public UItemUse
{
	GENERATED_BODY()
		typedef UItemUse Supper;
public:




	virtual void InitDynamicDataForJson(FString jsonStr) override;

public:
	// ���ܴ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemLearnShenTong | Property")
		int32 UseTimes;
	
};
