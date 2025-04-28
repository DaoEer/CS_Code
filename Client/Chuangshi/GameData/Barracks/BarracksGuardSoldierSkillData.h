// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameData/CsvTableRowBase.h"
#include "BarracksGuardSoldierSkillData.generated.h"

/**
* �ļ����ƣ�BarracksGuardSoldierSkillData.h
* ����˵�������ļ�����������
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-12-30
*/

USTRUCT(BlueprintType)
struct CHUANGSHI_API FBARRACKS_GUARD_SOLDIER_SKILL_DATA : public FCSV_TABLE_ROW_BASE
{
	GENERATED_BODY()
public:
	///��ScriptID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ScriptID")
	FString ScriptID;
	///������ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "CurrentSkillID")
	int32 CurrentSkillID = 0;
	///��һ��������ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "NextLevelSkillID")
	int32 NextLevelSkillID = 0;
	///���ĵľ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ReqExp")
	int32 ReqExp = 0;
	///�ȼ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Level")
	int32 Level = 0;
	///��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "SkillName")
	FString SkillName;
	///����ͼ��·��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Icon")
	TSoftObjectPtr<UTexture2D> Icon;
	///����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Description")
	FString Description = "";
};