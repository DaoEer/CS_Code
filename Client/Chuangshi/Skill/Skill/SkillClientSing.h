#pragma once
#include "CoreMinimal.h"
#include "Skill/Skill/CombatSkillClient.h"
#include "SkillClientSing.generated.h"

/*
* �ļ����ƣ�SkillClientSing.h
* ����˵�����ͻ�����������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-11
*/

UCLASS(BlueprintType)
class CHUANGSHI_API USkillClientSing :public UCombatSkillClient
{
	GENERATED_BODY()
public:
	USkillClientSing();
	~USkillClientSing();
public:
	/*��ʼ����������*/
	virtual void init(FString SkillId, const FSKILL_TABLE_DATA* dictDat);

	/*ʩ�ż���*/
	virtual int32 useSkill(CS3Entity* caster, USkillTargetObjImpl* target);

	/*���ܽ���*/
	virtual void onSkillEnd(CS3Entity* caster, USkillTargetObjImpl* target, bool castResult);

	/*����ʩ�ż���*/
	int32 continueCastSkill(CS3Entity* caster, USkillTargetObjImpl* target);

	/*���ü�������Ŀ��*/
	void setSkillSingTarget(CS3Entity* caster, USkillTargetObjImpl* target);

	/*��ü�������Ŀ��*/
	USkillTargetObjImpl* getSkillSingTarget(CS3Entity* caster);

	/*�Ƴ���������Ŀ��*/
	void removeSkillSingTarget(CS3Entity* caster);
private:
	int32 _endHitSkill = 0;
};