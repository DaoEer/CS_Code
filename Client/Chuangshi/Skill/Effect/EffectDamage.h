#pragma once
#include "EffectSkillBase.h"
#include "EffectDamage.generated.h"

/*
* �ļ����ƣ�EffectDamage.h
* ����˵������ʵ�˺�Ч��
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UEffectDamage : public UEffectSkillBase
{
	GENERATED_BODY()
public:
	UEffectDamage();
	~UEffectDamage();

public:
	/*��ȡ��������*/
	virtual void init(FHIT_EFFECT dictDat, USkill* skill);
	/*Ч����Ӽ��*/
	virtual bool canEffect(USkill* skill, CS3Entity* caster, CS3Entity* receiver);
	/*����Ч��*/
	virtual void onReceive(USkill* skill, CS3Entity* caster, CS3Entity* receiver);

private:
	int32 _damageValue = 0;
	float _percent = 0.0;
	int32 _deadEffect = 0;
	bool _isSkipEvent = false;
};

