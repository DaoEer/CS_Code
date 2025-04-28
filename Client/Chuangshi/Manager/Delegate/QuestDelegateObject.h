// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatDelegateObject.h"
#include "QuestDelegateObject.generated.h"

/**
 * ����/�Ի� ί�������������
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FOnShowTongDailyQuestSpaceWin, FString, Msg, FString, Statistics, FString, RewardStr, int32, GradeScore, int32, CountDown, FString, itemStr, FString, buff);
UCLASS()
class CHUANGSHI_API UQuestDelegateObject : public UCombatDelegateObject
{
	GENERATED_BODY()
public:

#pragma region	/** ����ճ����񸱱�ͨ�ؽ��� */
	//�򿪴�������
	UPROPERTY(BlueprintAssignable, Category = "SpaceContent|TongDailyQuest")
		FOnShowTongDailyQuestSpaceWin OnShowTongDailyQuestSpaceWin;
#pragma endregion
};
