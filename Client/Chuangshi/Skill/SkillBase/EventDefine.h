#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/GameDeFine.h"
#include "GameData/Skill/BuffDataType.h"
#include "GameData/Skill/SkillTableData.h"
#include "SkillTargetObjImpl.h"
#include "EventDefine.generated.h"

/*
* �ļ����ƣ�EventDefine.h
* ����˵���������¼���
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

class USkill;
/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API UBaseEvent :public UCS3Object
{
	GENERATED_BODY()
public:
	UBaseEvent();
	~UBaseEvent();
public:
	virtual void init(FSKILL_EVENT args);
	virtual bool canTriggerEvent(TMap<FString, FVariant> pDict);

protected:
	ENUM_SKILL_EVENT eventType;
};

/*�����¼�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UOnDieEvent :public UBaseEvent
{
	GENERATED_BODY()
public:
	UOnDieEvent();
	~UOnDieEvent();
public:
	virtual void init(FSKILL_EVENT args);
	virtual bool canTriggerEvent(TMap<FString, FVariant> pDict);

private:
	ACTION_FLAG _actForbid = ACTION_FLAG::ACTION_FORBID_NONE;
	int32 _type = NULL;
};

/*����״̬���͸ı�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UStateChangeEvent :public UBaseEvent
{
	GENERATED_BODY()
public:
	UStateChangeEvent();
	~UStateChangeEvent();
public:
	virtual void init(FSKILL_EVENT args);
	virtual bool canTriggerEvent(TMap<FString, FVariant> pDict);

private:
	int32 _oldState = NULL;
	int32 _newState = NULL;;
};

/*���ܿ���״̬�ı�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UActWorldChangeEvent :public UBaseEvent
{
	GENERATED_BODY()
public:
	UActWorldChangeEvent();
	~UActWorldChangeEvent();

public:
	virtual void init(FSKILL_EVENT args);
	virtual bool canTriggerEvent(TMap<FString, FVariant> pDict);
private:
	ACTION_FLAG _actWord = ACTION_FLAG::ACTION_FORBID_NONE;
	bool _disable = NULL;
};

/*���ܿ���״̬�ı�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UEffectStateChangeEvent :public UBaseEvent
{
	GENERATED_BODY()
public:
	UEffectStateChangeEvent();
	~UEffectStateChangeEvent();

public:
	virtual void init(FSKILL_EVENT args);
	virtual bool canTriggerEvent(TMap<FString, FVariant> pDict);

private:
	EFFECT_STATE _effectState = EFFECT_STATE::EFFECT_STATE_NULL;
	bool _disable = NULL;
};


/*�Զ����¼�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UCustomEvent :public UBaseEvent
{
	GENERATED_BODY()
public:
	UCustomEvent();
	~UCustomEvent();

public:
	virtual void init(FSKILL_EVENT args);
	virtual bool canTriggerEvent(TMap<FString, FVariant> pDict);

private:
	int32 _id = NULL;
	ACTION_FLAG _actWord = ACTION_FLAG::ACTION_FORBID_NONE;
};

/*���������¼�*/
UCLASS(BlueprintType)
class CHUANGSHI_API USkillEvent :public UBaseEvent
{
	GENERATED_BODY()
public:
	USkillEvent();
	~USkillEvent();

public:
	virtual void init(FSKILL_EVENT args);
	virtual bool canTriggerEvent(TMap<FString, FVariant> pDict);

protected:
	ACTION_FLAG _actForbid = ACTION_FLAG::ACTION_FORBID_NONE;
	int32 _type = NULL;
	int32 _skillID = NULL;
};

/*�����¼�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UCureEvent :public USkillEvent
{
	GENERATED_BODY()
public:
	UCureEvent();
	~UCureEvent();

private:

};
/*�˺��¼�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UHurtEvent :public UBaseEvent
{
	GENERATED_BODY()
public:
	UHurtEvent();
	~UHurtEvent();

public:
	virtual void init(FSKILL_EVENT args);
	virtual bool canTriggerEvent(TMap<FString, FVariant> pDict);

private:
	ACTION_FLAG _actForbid = ACTION_FLAG::ACTION_FORBID_NONE;
	int32 _type = NULL;
	TArray<FString> _conditions;
};


/*�����������¼�*/
UCLASS(BlueprintType)
class CHUANGSHI_API USkillProcessEvent :public USkillEvent
{
	GENERATED_BODY()
public:
	USkillProcessEvent();
	~USkillProcessEvent();

private:

};

/*buff�������¼�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UBuffProcessEvent :public UBaseEvent
{
	GENERATED_BODY()
public:
	UBuffProcessEvent();
	~UBuffProcessEvent();

public:
	virtual void init(FSKILL_EVENT args);
	virtual bool canTriggerEvent(TMap<FString, FVariant> pDict);

protected:
	ACTION_FLAG _actForbid = ACTION_FLAG::ACTION_FORBID_NONE;
	int32 _type = NULL;
	int32 _buffID = NULL;
};



USTRUCT(BlueprintType)
struct CHUANGSHI_API FEVENT_DATAS
{
	GENERATED_BODY();
public:
	UPROPERTY()
	TArray<UBaseEvent*> EventList;
};

/*ʩ�����¼�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UEventDefine :public UCS3Object
{
	GENERATED_BODY()
public:
	UEventDefine();
	~UEventDefine();
public:
	/*��������*/
	void init(TArray<FSKILL_EVENT> datas);

	/*�����¼�ʵ��*/
	UBaseEvent* CreateEventInstance(FSKILL_EVENT data);

	/*ע�Ἴ���¼�*/
	void registerEvent(USkill* skill, CS3Entity* caster);

	/*ɾ�������¼�*/
	void unRegisterEvent(USkill* skill, CS3Entity* caster);

	/*ע��Buff�¼�*/
	void registerBuffEvent(UBuffDataType * buffData, CS3Entity* caster, CS3Entity* receiver);

	/*�h��Buff�¼�*/
	void unRegisterBuffEvent(UBuffDataType * buffData, CS3Entity* caster, CS3Entity* receiver);

	/*�ж����ܴ����¼�*/
	bool canTriggerEvent(ENUM_SKILL_EVENT eventType, TMap<FString, FVariant> pDict);

private:
	UPROPERTY()
	TMap<ENUM_SKILL_EVENT, FEVENT_DATAS> _eventList;
};


/*����Ŀ���¼�*/
UCLASS(BlueprintType)
class CHUANGSHI_API UReceiverEventDefine :public UCS3Object
{
	GENERATED_BODY()
public:
	UReceiverEventDefine();
	~UReceiverEventDefine();

public:
	void init(TArray<FSKILL_EVENT> datas);

	/*�����¼�ʵ��*/
	UBaseEvent* CreateEventInstance(FSKILL_EVENT data);

	/*ע�Ἴ���¼� */
	void registerEvent(USkill* skill, CS3Entity* caster, USkillTargetObjImpl* target);

	/*ע��Buff�¼�*/
	void registerBuffEvent(UBuffDataType * buffData, CS3Entity* receiver);

	/*�h��Buff�¼�*/
	void unRegisterBuffEvent(UBuffDataType * buffData, CS3Entity* receiver);

	/*�ж����ܴ����¼�*/
	bool canTriggerEvent(ENUM_SKILL_EVENT eventType, TMap<FString, FVariant> pDict);
private:
	UPROPERTY()
	TMap<ENUM_SKILL_EVENT, FEVENT_DATAS> _receiverEventList;
};