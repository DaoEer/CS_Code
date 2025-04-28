#pragma once
#include "CoreMinimal.h"
#include "Skill/Skill/CombatSkillClient.h"
#include "SkillClientCharge.generated.h"

/*
* �ļ����ƣ�SkillClientCharge.h
* ����˵�����ͻ��˹����漼��
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-11
*/

UCLASS(BlueprintType)
class CHUANGSHI_API USkillClientCharge :public UCombatSkillClient
{
	GENERATED_BODY()
public:
	USkillClientCharge();
	~USkillClientCharge();

public:
	/*��ʼ����������*/
	virtual void init(FString SkillId, const FSKILL_TABLE_DATA* dictDat);

	/*ʩ�ż���*/
	virtual void cast(CS3Entity* caster, USkillTargetObjImpl* target);

	/*���ܽ���*/
	virtual void onSkillEnd(CS3Entity* caster, USkillTargetObjImpl* target, bool castResult);

private:
	float casterMoveSpeed = 0.0;     //����ٶ�
	float casterMoveDistance = 0.0;  //��̾���
};

