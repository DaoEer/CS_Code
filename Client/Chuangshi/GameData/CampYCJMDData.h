#pragma once
#include "CoreMinimal.h"
#include "CampYCJMDData.generated.h"

/**
* �ļ����ƣ�CampYCJMDData.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2020/02/28
*/


USTRUCT(BlueprintType)
struct CHUANGSHI_API FCampYCJMDData
{
	GENERATED_USTRUCT_BODY()
		FCampYCJMDData() {};
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "id")
		int32 id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "name")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "camp")
		int32 camp = 0;
	/// ��ɱ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "kill")
		int32 kill = 0;
	/// ��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "dead")
		int32 dead = 0;
	/// ��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "assist")
		int32 assist = 0;
};
