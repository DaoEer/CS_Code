// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/Item/ItemUseAssist.h"
#include "ItemUseBatteryAssist.generated.h"

/**
* �ļ����ƣ�ItemUseAssist.h
* ����˵���������Ҽ�ʹ����Ʒ�����ְ�͸��ģ����Ϊʩ�����������ܶ�λ��ʩ����
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020-03-30
*/
class AServerCharacter;

UCLASS()
class CHUANGSHI_API UItemUseBatteryAssist : public UItemUseAssist
{
	GENERATED_BODY()
	

public:
	// ʩ������ģ�� ����
	virtual FRotator GetModelRotationAssist(const AServerCharacter* Owner) override;
	// ���ʩ������ ��Ч��
	virtual bool CheckModelAssistValid(const FVector& Pos) override;
};
