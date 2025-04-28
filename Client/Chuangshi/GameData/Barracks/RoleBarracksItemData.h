// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "BarracksTableData.h"
#include "RoleBarracksItemData.generated.h"



/**
* �ļ����ƣ�RoleBarracksItemData.h
* ����˵������ұ�Ӫ����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-12-24
*/
USTRUCT(BlueprintType)
struct FPASSIVESKILLDATA {
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 SkillID = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Exp = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxExp = 0;
};



USTRUCT(BlueprintType)
struct FROLEBARRACKSITEMDATA {
	GENERATED_USTRUCT_BODY()
	/// id ���ݽ�������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Id = 0;
	/// ����scriptID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ScriptID;
	/// ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ENUM_BARRACKS_SOLDIER_TYPE SoldierType;
	/// ���ĵȼ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Level = 0;
	/// ���ĵ�ǰ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Exp = 0;
	/// ���������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxExp = 0;
	/// ���Ƿ��ڲ�����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsInArmy = 0;
	/// ���ı�������(�츳)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FPASSIVESKILLDATA> PassiveSkillDatas;
	///�Ƿ񼤻�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsActive = 1;

	bool operator ==(const FROLEBARRACKSITEMDATA& other)
	{
		if (other.Id == Id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};