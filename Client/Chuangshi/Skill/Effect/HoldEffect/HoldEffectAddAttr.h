#pragma once
#include "HoldEffect.h"

#include "HoldEffectAddAttr.generated.h"

/*
* �ļ����ƣ�HoldEffectAddAttr.h
* ����˵����ս������ ����/���� Ч��
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffectAddAttr : public UHoldEffect
{
	GENERATED_BODY()
public:
	UHoldEffectAddAttr();
	~UHoldEffectAddAttr();

public:
	/*��ȡ��������*/
	virtual void init(FHOLD_EFFECT dictDat, USkill* skill);

	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);

private:
	TArray<int32> _propertiesList;
	int32 _attrPercent = 0;
	int32 _attrValue = 0;
};



