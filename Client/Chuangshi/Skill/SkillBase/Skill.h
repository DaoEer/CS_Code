#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "SkillTargetObjImpl.h"
#include "RequireDefine.h"
#include "ObjectCondition.h"
#include "HitDefine.h"
#include "ObjectDefine.h"
#include "EventDefine.h"
#include "GameData/GameDeFine.h"
#include "GameData/Skill/SkillData.h"
#include "GameData/Skill/SkillTableData.h"
#include "GameData/Skill/HoldEffectDataType.h"
#include "Skill/Effect/HoldEffect/HoldEffect.h"
#include "Skill.generated.h"

/*
* �ļ����ƣ�Skill.h
* ����˵����������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

UCLASS(BlueprintType)
class CHUANGSHI_API USkill :public UCS3Object
{
	GENERATED_BODY()
public:
	USkill();
	~USkill();

public:
	/*��ʼ����������*/
	virtual void init(FString SkillId, const FSKILL_TABLE_DATA* dictDat);

	/*��鼼���Ƿ����ʹ��*/
	virtual int32 useableCheck(CS3Entity* caster, USkillTargetObjImpl* target);

	/*ʩ�ż���*/
	virtual int32 useSkill(CS3Entity* caster, USkillTargetObjImpl* target);

	/*ͨ������ʹ�ü���*/
	virtual void use(CS3Entity* caster, USkillTargetObjImpl* target);

	/*ʩ�ż���*/
	virtual void cast(CS3Entity* caster, USkillTargetObjImpl* target);
	
	/*���ܿ�ʼ*/
	virtual void onSkillBegin(CS3Entity* caster, USkillTargetObjImpl* target);

	/*���ܴ��*/
	virtual void onSkillHit(INT32 casterID, USkillTargetObjImpl* target, int32 hitTime);

	/*���ִܵ�*/
	virtual void onArrive(CS3Entity* caster, USkillTargetObjImpl* target, int32 hitTime, int32 index);

	/*���س���Ч��*/
	virtual void addHoldEffect(CS3Entity* caster);

	/*���ܽ���*/
	virtual void onSkillEnd(CS3Entity* caster, USkillTargetObjImpl* target, bool castResult);

	/*�Ƴ�����Ч��*/
	virtual void removeHoldEffect(CS3Entity* caster);

	/*�ܷ��ж�*/
	virtual bool canInterrupt(CS3Entity* caster, int32 reason);

	/*�ж�*/
	virtual void interrupt(CS3Entity* caster, int32 reason, USkillTargetObjImpl* target = nullptr);

	/*�����жϵ�һЩ�߼�*/
	virtual void interruptSkill(CS3Entity* caster, int32 reason);
	 
	/*ע���ж��¼�*/
	virtual void registerSkillEvent(CS3Entity* caster, USkillTargetObjImpl* target);

	/*ȡ���ж��¼�*/
	virtual void unRegisterSkillEvent(CS3Entity* caster);

	/*���������¼�*/
	virtual void triggerSkillEvent(CS3Entity* caster, ENUM_SKILL_EVENT eventType, int32 triggerID, TMap<FString, FVariant> pDict);

	/*��������Ŀ���¼�*/
	virtual void triggerReceiverSkillEvent(CS3Entity* caster, CS3Entity* receiver, ENUM_SKILL_EVENT eventType, int32 triggerID, TMap<FString, FVariant> pDict);

	/*У�鼼���Ƿ����ʩչ��*/
	virtual int32 castValidCheck(CS3Entity* caster, CS3Entity* target);

	/*���ʩ��Ŀ���Ƿ�������������*/
	virtual int32 targetValidCheck(CS3Entity* caster, USkillTargetObjImpl* target);

	/*�Ƿ���˲������*/
	virtual bool isInstantSkill();

	/*�Ƿ��Ǳ�������*/
	bool isPassiveSkill();

	/*ʩ���߼����Ƿ�����ȴ��*/
	bool isCasterCooldown(CS3Entity* caster);

	/*����Ŀ���Ƿ�����ȴ��*/
	bool isTargetCooldown(USkillTargetObjImpl* target);

	/*���ʩ���������Ƿ�*/
	int32 checkCasterRequire(CS3Entity* caster);

	/*��⼼��Ŀ�������Ƿ�*/
	int32 checkTargetRequire(USkillTargetObjImpl* target);

	/*����ʩ��������*/
	void doCasterRequire(CS3Entity* caster);

	/*������Ŀ������*/
	void doTargetRequire(USkillTargetObjImpl* target);

	/*��ȡʩ��Ŀ������*/
	ENUM_CAST_TARGET_TYPE getTargetType();

	/*ȡ�÷���ʩ��Ŀ�����*/
	UTargetBase *getCastObject();

	/*��ü���ID*/
	int32 getID();

	ACTION_FLAG getCasterActForbid();

	/*��ô��*/
	USkillHitDefine * getHit(int32 hitTime, int32 index);

	/*���ʩ������*/
	float getCastRangeMax();

	/*��ȡ������ʱ��*/
	float getSkillTotalTime();

	/*���似��Ŀ��*/
	USkillTargetObjImpl* adaptiveTarget(CS3Entity* caster, USkillTargetObjImpl* target);
	
	/*��ýű�����*/
	FString getScriptType();

	/*	�����ȡԲ�ڵ�λ��   pos ΪԲ��,radius Ϊ�뾶*/
	FVector getPositionByCircular(FVector pos, float radius);
protected:
	bool _isPassiveSkill = false; //�Ƿ񱻶�����
	int32 _id = 0;  //����ID
	FString _name = ""; //��������
	bool _isInstantSkill = false;
	int32 _level = 0;
	ACTION_FLAG _casterActForbid = ACTION_FLAG::ACTION_FORBID_NONE;
	ACTION_FLAG _targetActForbid = ACTION_FLAG::ACTION_FORBID_NONE;
	ENUM_CAST_TARGET_TYPE _targetType = ENUM_CAST_TARGET_TYPE::TargetNothing;
	bool _isTurnToTarget = false;
	ENUM_CAST_COLLISION_TYPE _collisionType = ENUM_CAST_COLLISION_TYPE::COLLISION_DEFAULT;
	float _castRangeMax = 0.0;
	float _reTargetRadius = 0.0;
	UPROPERTY()
	TArray<UHoldEffect*> _holdEffectList; //��Ҫʵ����
	UPROPERTY()
	TMap<int32, float> _casterCoolDown; //ʩ���߼�����ȴ
	UPROPERTY()
	TMap<int32, float> _targetCoolDown; //�����߼�����ȴ
	UPROPERTY()
	URequireDefine* _casterRequire; //ʩ����ʩ������
	UPROPERTY()
	URequireDefine* _targetRequire; //������ʩ������
	UPROPERTY()
	UObjectCondition * _casterCondition;
	UPROPERTY()
	UObjectCondition * _targetCondition;
	UPROPERTY()
	UTargetBase* _castObject;
	UPROPERTY()
	USkillHitData* _hitData;
	UPROPERTY()
	UEventDefine* _interruptEvent;
	UPROPERTY()
	UReceiverEventDefine* _receiverInterruptEvent;
	UPROPERTY()
	TArray<FString> _casterActionID;
	UPROPERTY()
	TArray<FString> _casterActionBeginTime;
	UPROPERTY()
	TArray<FString> _targetActionID;
	UPROPERTY()
	TArray<FString> _targetActionBeginTime;
};
