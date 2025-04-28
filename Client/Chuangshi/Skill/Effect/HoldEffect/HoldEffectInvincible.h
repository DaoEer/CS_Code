#pragma once
#include "HoldEffect.h"

#include "HoldEffectInvincible.generated.h"


/*
* �ļ����ƣ�HoldEffectInvincible.h
* ����˵��������Ч�����޵�
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffectInvincible :public UHoldEffect
{
	GENERATED_BODY()
public:
	UHoldEffectInvincible();
	~UHoldEffectInvincible();

public:
	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);

private:

};

