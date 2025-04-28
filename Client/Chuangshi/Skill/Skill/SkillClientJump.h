#pragma once
#include "CoreMinimal.h"
#include "Skill/Skill/CombatSkillClient.h"
#include "SkillClientJump.generated.h"

/*
* �ļ����ƣ�SkillClientJump.h
* ����˵�����ͻ������˼���
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-11
*/

UCLASS(BlueprintType)
class CHUANGSHI_API USkillClientJump :public UCombatSkillClient
{
	GENERATED_BODY()
public:
	USkillClientJump();
	~USkillClientJump();

public:
	/*��ʼ����������*/
	virtual void init(FString SkillId, const FSKILL_TABLE_DATA* dictDat);

	/*��鼼���Ƿ����ʹ��*/
	virtual int32 useableCheck(CS3Entity* caster, USkillTargetObjImpl* target);

	/*ʩ�ż���*/
	virtual void cast(CS3Entity* caster, USkillTargetObjImpl* target);

	/*���ܽ���*/
	virtual void onSkillEnd(CS3Entity* caster, USkillTargetObjImpl* target, bool castResult);
private:
	float delayTime;
	float moveTime;
};

