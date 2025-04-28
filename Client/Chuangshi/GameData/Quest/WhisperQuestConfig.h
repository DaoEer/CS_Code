#pragma once
#include "CoreMinimal.h"
#include "GameData/CsvTableRowBase.h"
#include "WhisperQuestConfig.generated.h"

/**
* �ļ����ƣ�WhisperQuestConfig.h
* ����˵���������������ݱ�
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2020-01-20
*/

//�����������ݱ�
USTRUCT(BlueprintType)
struct CHUANGSHI_API FWHISPER_QUEST_CONFIG : public FCSV_TABLE_ROW_BASE
{
	GENERATED_USTRUCT_BODY()
public:
	///������ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		int32 rootQuestID;
	///����Ŀ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		int32 taskID;
	///����Ŀ�����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		FString taskName = "";
	///npcID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		int32 npcID = 0;
	///Ѱ·����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		FString navigateData = "";
	///NPC��ʼ�Ի�ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		FString npcSoundID = "";
	///��ҿ�ʼ�Ի�ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		FString startSoundID = "";
	///�����ɹ��Ի�ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		FString succeedSoundID = "";
	///����ʧ�ܶԻ�ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		FString failedSoundID = "";
	///��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		FString dialogue = "";
	///������ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		int32 taskQuestID = 0;
	///������ʱ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WhisperQuestConfig")
		float taskQuestTime = 0;
};