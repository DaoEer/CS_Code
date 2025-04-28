#pragma once
#include "EffectSkillBase.h"
#include "EffectRemoveBuff.generated.h"

/*
* �ļ����ƣ�EffectRemoveBuff.h
* ����˵�����Ƴ�buffЧ��������չ�����Ƴ���ʽ
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UEffectRemoveBuff : public UEffectSkillBase
{
	GENERATED_BODY()
public:
	UEffectRemoveBuff();
	~UEffectRemoveBuff();

public:
	/*��ȡ��������*/
	virtual void init(FHIT_EFFECT dictDat, USkill* skill);

	/*����Ч��*/
	virtual void onReceive(USkill* skill, CS3Entity* caster, CS3Entity* receiver);

private:
	TArray<int32> _buffIdList;
};

