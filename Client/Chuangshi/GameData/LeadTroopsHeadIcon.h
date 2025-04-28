#pragma once

#include "CoreMinimal.h"
#include "CsvTableRowBase.h"
#include "LeadTroopsHeadIcon.generated.h"

/**
* �ļ����ƣ�LeadTroopsHeadIcon.h
* ����˵�������ģʽͷ���������
* �ļ����ߣ�zhuangzhenguo
* Ŀǰά����zhuangzhenguo
* ����ʱ�䣺2020-05-08
*/

USTRUCT(BlueprintType)
struct CHUANGSHI_API FLEADTROOPSHEAD_ICON_DATA : public FCSV_TABLE_ROW_BASE
{
	GENERATED_USTRUCT_BODY()

public:

	///ScriptID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "LEADTROOPSHEAD_ICON_DATA", DisplayName = "ScriptID")
		FString  ScriptId;
	///�Ѻù�ϵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "LEADTROOPSHEAD_ICON_DATA", DisplayName = "RelationNormal")
		TSoftObjectPtr<UTexture2D> RelationNormal;
	///�жԹ�ϵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "LEADTROOPSHEAD_ICON_DATA", DisplayName = "RelationEnemy")
		TSoftObjectPtr<UTexture2D> RelationEnemy;

};