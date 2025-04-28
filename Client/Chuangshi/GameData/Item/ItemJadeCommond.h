// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/Item/ItemBase.h"
#include "ItemJadeCommond.generated.h"



/**
* �ļ����ƣ�ItemJadeCommond.h
* ����˵������������ű�
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020-03-31
*/
UCLASS()
class CHUANGSHI_API UItemJadeCommond : public UItemBase
{
	GENERATED_BODY()

public:
	virtual void InitDynamicDataForJson(FString jsonStr) override;

	// ��������ȼ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equip | Property")
		int32 jadeLevel;
	// �Ƿ���Ч
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equip | Property")
		int32 isValid;
	
};
