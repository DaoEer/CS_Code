#pragma once
#include "HoldEffect.h"

#include "HoldEffectPlayEffect.generated.h"


/*
* �ļ����ƣ�HoldEffectPlayEffect.h
* ����˵��������Ч�����Ӷ���������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffectPlayEffect :public UHoldEffect
{
	GENERATED_BODY()
public:
	UHoldEffectPlayEffect();
	~UHoldEffectPlayEffect();

public:
	/*��ȡ��������*/
	virtual void init(FHOLD_EFFECT dictDat, USkill* skill);

	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);

private:
	TArray<FString> _actionID;
	TArray<FString> _actionBeginTime;
	FString _effectID;
	FString _soundID;
};

