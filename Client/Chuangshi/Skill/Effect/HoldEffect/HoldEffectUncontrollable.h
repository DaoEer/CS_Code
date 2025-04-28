#pragma once
#include "HoldEffect.h"

#include "HoldEffectUncontrollable.generated.h"


/*
* �ļ����ƣ�HoldEffectUncontrollable.h
* ����˵��������Ч��������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffectUncontrollable :public UHoldEffect
{
	GENERATED_BODY()
public:
	UHoldEffectUncontrollable();
	~UHoldEffectUncontrollable();

public:
	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);

private:

};

