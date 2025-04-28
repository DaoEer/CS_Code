#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/GameDeFine.h"
#include "GameData/Skill/SkillTableData.h"
#include "GameData/Skill/HoldEffectDataType.h"

#include "HoldEffect.generated.h"

class USkill;
/*
* �ļ����ƣ�HoldEffect.h
* ����˵��������Ч������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/


UCLASS(BlueprintType)
class CHUANGSHI_API UHoldEffect:public UCS3Object
{
	GENERATED_BODY()
public:
	UHoldEffect();
	~UHoldEffect();

public:
	/*��ȡ��������*/
	virtual void init(FHOLD_EFFECT dictDat, USkill * skill);

	/*���ɳ���Ч������*/
	virtual UHoldEffectDataType* getNewEffectData(CS3Entity* caster, CS3Entity* receiver);

	/*Ч����Ӽ��*/
	virtual bool canEffect(CS3Entity* caster, CS3Entity* receiver);

	/*Ч����ʼ*/
	virtual void onBegin(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*Ч������*/
	virtual void onEnd(UHoldEffectDataType* effectData, CS3Entity* receiver);

	/*receiver��ĳ�ͻ��˱���������*/
	virtual void onClientActorCreate(UHoldEffectDataType* effectData, CS3Entity* receiver);
};

