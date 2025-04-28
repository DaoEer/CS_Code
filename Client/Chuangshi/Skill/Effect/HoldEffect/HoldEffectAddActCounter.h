#pragma once
#include "HoldEffect.h"

#include "HoldEffectAddActCounter.generated.h"


/*
* �ļ����ƣ�HoldEffectAddAttr.h
* ����˵��������Ч�����Ӷ���������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffectAddActCounter :public UHoldEffect
{
	GENERATED_BODY()
public:
	UHoldEffectAddActCounter();
	~UHoldEffectAddActCounter();

public:
	/*��ȡ��������*/
	virtual void init(FHOLD_EFFECT dictDat, USkill* skill);

	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);

private:
	TArray<int32> _actList;
};


