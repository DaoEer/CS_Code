#pragma once
#include "CoreMinimal.h"
#include "Skill/SkillBase/Skill.h"
#include "InstantSkillClient.generated.h"

/*
* �ļ����ƣ�InstantSkillClient.h
* ����˵�����ͻ���˲������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-11
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UInstantSkillClient :public USkill
{
	GENERATED_BODY()
public:
	UInstantSkillClient();
	~UInstantSkillClient();


public:
	/*��鼼���Ƿ����ʹ��*/
	virtual int32 useableCheck(CS3Entity* caster, USkillTargetObjImpl* target);

	/*���ܿ�ʼ*/
	virtual void onSkillBegin(CS3Entity* caster, USkillTargetObjImpl* target);

	/*���ܽ���*/
	virtual void onSkillEnd(CS3Entity* caster, USkillTargetObjImpl* target, bool castResult);

	/*���������¼�*/
	virtual void triggerSkillEvent(CS3Entity* caster, ENUM_SKILL_EVENT eventType, int32 triggerID, TMap<FString, FVariant> pDict);

	/*��������Ŀ���¼�*/
	virtual void triggerReceiverSkillEvent(CS3Entity* caster, CS3Entity* receiver, ENUM_SKILL_EVENT eventType, int32 triggerID, TMap<FString, FVariant> pDict);

	/*�ж��Ƿ���˲������*/
	virtual bool isInstantSkill();
private:

};

