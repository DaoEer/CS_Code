#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "HoldEffect.h"

#include "HoldEffectBindDisplayObject.generated.h"

/*
* �ļ����ƣ�HoldEffectBindDisplayObject.h
* ����˵��������Ч����ģ�Ͱ󶨲���
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/


UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffectBindDisplayObject :public UHoldEffect
{
	GENERATED_BODY()
public:
	UHoldEffectBindDisplayObject();
	~UHoldEffectBindDisplayObject();

public:
	/*��ȡ��������*/
	virtual void init(FHOLD_EFFECT dictDat, USkill * skill);

	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);
private:
	FString _meshID;
};

