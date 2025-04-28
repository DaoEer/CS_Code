#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/GameDeFine.h"
#include "GameData/Skill/SkillTableData.h"
#include "EffectSkillBase.generated.h"

class USkill;
/*
* �ļ����ƣ�EffectSkillBase.h
* ����˵��������Ч��
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UEffectSkillBase :public UCS3Object
{
	GENERATED_BODY() 
public:
	UEffectSkillBase();
	~UEffectSkillBase();

public:
	/*��ȡ��������*/
	virtual void init(FHIT_EFFECT dictDat, USkill* skill);
	/*Ч����Ӽ��*/
	virtual bool canEffect(USkill* skill, CS3Entity* caster, CS3Entity* receiver);
	/*����Ч��*/
	virtual void onReceive(USkill* skill, CS3Entity* caster, CS3Entity* receiver);
protected:
	ACTION_FLAG _receiverActForbid;
	ACTION_FLAG _casterActForbid;
};

