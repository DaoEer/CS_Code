#pragma once
#include "CoreMinimal.h"
#include "ZYJJRewardData.generated.h"
/**
* �ļ����ƣ�ZYJJRewardData.h
* ����˵������Ӫ5�˾����������ݽṹ
* �ļ����ߣ�fangpengjun
* Ŀǰά����fangpengjun
* ����ʱ�䣺2020-01-09
*/
USTRUCT(BlueprintType)
struct CHUANGSHI_API FZYJJRewardData
{
	GENERATED_USTRUCT_BODY()
public:
	//����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Exp;
	//��ѫ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Feats;
	//����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Exploit;
	//�ﹱ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Contribution;
};