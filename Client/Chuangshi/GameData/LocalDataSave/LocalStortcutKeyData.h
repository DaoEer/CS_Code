// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameData/ShortcutKey.h"
#include "LocalStortcutKeyData.generated.h"

/**
* �ļ����ƣ�LocalChatSettingData.h
* ����˵������ݼ���������
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2020-05-06
*/

UCLASS(Blueprintable, BlueprintType)
class CHUANGSHI_API ULocalStortcutKeyData : public USaveGame
{
	GENERATED_BODY()
		
public:
	ULocalStortcutKeyData();
	UFUNCTION(BlueprintCallable, Category = "LocalChatSettingData")
		const FString& GetFileName();
	
	/**
	*�����ݼ���������
	*
	*@param SHORTCUTKEY_TYPE_ENUM ��ݼ�����
	*@param TArray<FSHORTCUTKEY> ��ݼ�����
	*
	*@return ��
	*/
	void SaveShortcutKeyDataByTypeToFile(SHORTCUTKEY_TYPE_ENUM Type, TArray<FSHORTCUTKEY> NewKeys);

	/**
	*�����ݼ���������
	*
	*@param TArray<FSHORTCUTKEY> ��ݼ�����
	*
	*@return ��
	*/
	void SaveShortcutKeyDataToFile(TArray<FSHORTCUTKEY> NewKeys);

public:
	/** ���޸Ŀ�ݼ��������� */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<FSHORTCUTKEY> ChangedKeys;
private:
	UPROPERTY(VisibleAnywhere)
		FString FileName;///�ļ�����
};