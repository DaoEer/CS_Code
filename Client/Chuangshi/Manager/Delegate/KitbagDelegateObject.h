// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Manager/Delegate/QuestDelegateObject.h"
#include "KitbagDelegateObject.generated.h"

/**
 * ����/��Ʒ/���� ί����������
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSuccessBuyItem);

UCLASS()
class CHUANGSHI_API UKitbagDelegateObject : public UQuestDelegateObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable, Category = "CS3|MysteriousShopNPC")
		FOnSuccessBuyItem OnSuccessBuyItemEvent;	//�������˹���ɹ�
	
};
