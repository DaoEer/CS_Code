// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/Item/ItemBase.h"
#include "ItemBattleFormations.generated.h"



/**
* �ļ����ƣ�ItemBattleFormations.h
* ����˵����ͼ��
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020-05-14
*/
UCLASS()
class CHUANGSHI_API UItemBattleFormations : public UItemBase
{
	GENERATED_BODY()

public:
	// ��ȡͼ��Ѫ��
	UFUNCTION(BlueprintPure)
		FString GetBattleFormationsHP();
		
	// ��ȡÿ�������� �� ��������
	UFUNCTION(BluePrintCallable)
		void GetPerAndTotalSoume(int32& PerSoume, int32& TotalSoume);
};
