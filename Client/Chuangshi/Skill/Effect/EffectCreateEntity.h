#pragma once
#include "EffectSkillBase.h"
#include "EffectCreateEntity.generated.h"

/*
* �ļ����ƣ�EffectCreateEntity.h
* ����˵����Ŀ��λ�ô���entity
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UEffectCreateEntity : public UEffectSkillBase
{
	GENERATED_BODY()
public:
	UEffectCreateEntity();
	~UEffectCreateEntity();

public:
	/*��ȡ��������*/
	virtual void init(FHIT_EFFECT dictDat, USkill* skill);

	/*����Ч��*/
	virtual void onReceive(USkill* skill, CS3Entity* caster, CS3Entity* receiver);

private:
	FString _scriptID;
	float _offsetFront = 0.0;
	float _offsetLeft = 0.0;
};

