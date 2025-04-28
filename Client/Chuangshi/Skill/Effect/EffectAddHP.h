#pragma once
#include "EffectSkillBase.h"
#include "EffectAddHP.generated.h"

/*
* �ļ����ƣ�EffectAddHP.h
* ����˵������ѪЧ��
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UEffectAddHP : public UEffectSkillBase
{
	GENERATED_BODY()
public:
	UEffectAddHP();
	~UEffectAddHP();

public:
	/*��ȡ��������*/
	virtual void init(FHIT_EFFECT dictDat, USkill* skill);
	/*Ч����Ӽ��*/
	virtual bool canEffect(USkill* skill, CS3Entity* caster, CS3Entity* receiver);
	/*����Ч��*/
	virtual void onReceive(USkill* skill, CS3Entity* caster, CS3Entity* receiver);

private:
	int32 _addValue = 0;
	float _percent = 0.0;
	bool _isSkipEvent = false;
};


