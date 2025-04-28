#pragma once
#include "CoreMinimal.h"
#include "Skill/SkillBase/Skill.h"
#include "CombatSkillClient.generated.h"

/*
* �ļ����ƣ�CombatSkillClient.h
* ����˵�����ͻ�����������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-11
*/


UCLASS(BlueprintType)
class UCombatSkillClient :public USkill
{
	GENERATED_BODY()
public:
	UCombatSkillClient();
	~UCombatSkillClient();
public:
	/*��ʼ����������*/
	virtual void init(FString SkillId, const FSKILL_TABLE_DATA* dictDat);

	/*���ܿ�ʼ*/
	virtual void onSkillBegin(CS3Entity* caster, USkillTargetObjImpl* target);

	/*���ܽ���*/
	virtual void onSkillEnd(CS3Entity* caster, USkillTargetObjImpl* target, bool castResult);
protected:
	bool _isShowIntonateUI = false; //�Ƿ���ʾ����������
	FString _intonateName = ""; //��������
	FString _iconName = "";  //ͼ��
};

