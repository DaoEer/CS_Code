// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/Quest/QuestBase/QuestBase.h"
#include "QuestQiYuan.generated.h"

/**
* �ļ����ƣ�QuestQiYuan.h
* ����˵������Ե����
* �ļ����ߣ�qrn
* Ŀǰά����qrn
* ����ʱ�䣺2020-06-18
 */
UCLASS(BlueprintType)
class CHUANGSHI_API UQuestQiYuan : public UQuestBase
{
	GENERATED_BODY()

public:
	/**
	*��ʼ����������
	*
	*@param FCS3QuestInfo ��������
	*
	*@return ��
	*/
	virtual void InitDatas(const FString JsonStr);

	/*
	*��ȡ����ʱ��
	*/
	UFUNCTION(BlueprintCallable, Category = "Quest")
		FString getCountDown() { return mCountDown; }

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "QuestQiYuan")
		int32 isShowTime; //1:��Ҫ��ʾ����ʱ   0������Ҫ��ʾ����ʱ

private:
	FString mCountDown;
};
