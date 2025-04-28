#pragma once
#include "HoldEffect.h"

#include "HoldEffectFix.generated.h"


/*
* �ļ����ƣ�HoldEffectFix.h
* ����˵��������Ч���������޷�ת����Ծ���ƶ���
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffectFix :public UHoldEffect
{
	GENERATED_BODY()
public:
	UHoldEffectFix();
	~UHoldEffectFix();

public:
	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);

private:

};

