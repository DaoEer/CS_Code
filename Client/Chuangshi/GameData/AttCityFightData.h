// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CsvTableRowBase.h"
#include "AttCityFightData.generated.h"

/**
* �ļ����ƣ�AttCityFightData.h
* ����˵��������ս�������
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2020-01-10
*/

/** �����ݽṹ�� */
USTRUCT(BlueprintType)
struct CHUANGSHI_API FATT_CITY_LADDER_DATA : public FCSV_TABLE_ROW_BASE
{
	GENERATED_USTRUCT_BODY()
public:
	//������ΨһID
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AttCityFightData")
		FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AttCityFightData")
		FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AttCityFightData")
		FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AttCityFightData")
		FVector Scale;
	//ģ��ID
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AttCityFightData")
		FString ModelNumber;
};