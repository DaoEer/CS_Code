// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/Item/ItemUse.h"
#include "ItemUseAssist.generated.h"



/**
* �ļ����ƣ�ItemUseAssist.h
* ����˵���������Ҽ�ʹ����Ʒ�����ְ�͸��ģ����Ϊʩ�����������ܶ�λ��ʩ����
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020-03-30
*/

class AServerCharacter;

UCLASS()
class CHUANGSHI_API UItemUseAssist : public UItemUse
{
	GENERATED_BODY()

public:
	/**
	*�麯������ѯʹ�ý��
	*
	*@param player ���
	*
	*@return int32 ʹ�ý��
	*/
	virtual int32 UseQuery(AServerCharacter* player) override;

	//��ȡ ʩ��������ģ�� ID
	FString GetModelAssist();
	
	// ��ȡʩ������ģ�� ƫ�Ƹ߶�
	float GetModelAssistOffsetH();

	// ʩ������ģ�� ����
	virtual FRotator GetModelRotationAssist(const AServerCharacter* Owner);
	// ���ʩ������ ��Ч��
	virtual bool CheckModelAssistValid(const FVector& Pos);

	virtual void UseItemToPosition() override;

	virtual bool IsUseDirection() { return false; };
};
