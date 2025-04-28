// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "CsvTableRowBase.h"
#include "LingHuanJueData.generated.h"

/**
* �ļ����ƣ�LingHuanJueData.h
* ����˵����
* �ļ����ߣ�fangpengjun
* Ŀǰά����fangpengjun
* ����ʱ�䣺2020-04-22
*/

USTRUCT(BlueprintType)
struct CHUANGSHI_API FLINGHUANJUE_DATA : public FCSV_TABLE_ROW_BASE
{
	GENERATED_USTRUCT_BODY()
public:
	///ÿ���Ѷ��ж��飬ÿ���ж������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FLINGHUANJUE_DATA", DisplayName = "GroupID")
		int32  GroupID;
	///��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FLINGHUANJUE_DATA", DisplayName = "LatticeIndex")
		int32 LatticeIndex;
		///�Ѷ�
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FLINGHUANJUE_DATA", DisplayName = "Difficulty")
		int32 Difficulty;
	///�����е�һ��ָ���ʼ������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FLINGHUANJUE_DATA", DisplayName = "PointerIndex")
		int32 PointerIndex;
	///�нǣ�����0��ʾ��2��ָ��,����0��ʾֻ��1��ָ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FLINGHUANJUE_DATA", DisplayName = "PointerAngle")
		float PointerAngle = 0.0;
};
