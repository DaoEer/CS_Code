#pragma once
#include "HoldEffect.h"

#include "HoldEffectConfusion.generated.h"



/*
* �ļ����ƣ�HoldEffectConfusion.h
* ����˵��������Ч�������ң�PC�޷������ƣ����ߣ�
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffectConfusion :public UHoldEffect
{
	GENERATED_BODY()
public:
	UHoldEffectConfusion();
	~UHoldEffectConfusion();

public:
	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);

private:

};

