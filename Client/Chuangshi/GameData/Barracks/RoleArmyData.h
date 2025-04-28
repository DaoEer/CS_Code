// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "RoleArmyData.generated.h"



/**
* �ļ����ƣ�RoleArmyData.h
* ����˵������Ҳ�������
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-12-26
*/

USTRUCT(BlueprintType)
struct FROLEARMYDATA {
	GENERATED_USTRUCT_BODY()
	/// id
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Id = 0;
	/// �����Ƿ�æµ������������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 BeBusy = 0;
	/// ������scriptID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString FirstGuardScriptID;
	/// ������scriptID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString SecondGuardScriptID;
	/// ����scriptID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString SoldierScriptID;
	/// ����IDs
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> SoldierIDs;
};


/// ��������
USTRUCT(BlueprintType)
struct CHUANGSHI_API FTRAIN_GROUND_QUEST
{
	GENERATED_BODY()

public:
	/// ����ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "QuestID")
		int32 QuestID = 0;
	/// ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Title")
		FString Title;
	/// ���� Ŀ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "TaskTitle")
		FString TaskTitle;
	/// ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Reward")
		int32 Reward;
	/// С��scriptID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "SoldierScriptID")
		FString SoldierScriptID;
	

};