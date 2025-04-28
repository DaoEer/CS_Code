#pragma once
#include "EffectSkillBase.h"
#include "EffectAddBuff.generated.h"

/*
* �ļ����ƣ�EffectAddBuff.h
* ����˵�������buffЧ��
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UEffectAddBuff : public UEffectSkillBase
{
	GENERATED_BODY()
public:
	UEffectAddBuff();
	~UEffectAddBuff();
public:
	/*��ȡ��������*/
	virtual void init(FHIT_EFFECT dictDat, USkill* skill);

	/*����Ч��*/
	virtual void onReceive(USkill* skill, CS3Entity* caster, CS3Entity* receiver);

private:
	int32 _buffID;
};

