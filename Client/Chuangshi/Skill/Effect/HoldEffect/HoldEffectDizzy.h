#pragma once
#include "HoldEffect.h"

#include "HoldEffectDizzy.generated.h"


/*
* �ļ����ƣ�HoldEffectDizzy.h
* ����˵��������Ч����ѣ��
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffectDizzy :public UHoldEffect
{
	GENERATED_BODY()
public:
	UHoldEffectDizzy();
	~UHoldEffectDizzy();

public:
	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);
private:

};

