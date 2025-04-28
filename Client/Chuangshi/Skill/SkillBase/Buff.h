#pragma once
#include "CoreMinimal.h"
#include "HitDefine.h"
#include "ObjectCondition.h"
#include "EventDefine.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/CS3Object.h"
#include "GameData/Skill/BuffDataType.h"
#include "GameData/Skill/BuffData.h"
#include "GameData/Skill/BuffTableData.h"
#include "Skill/Effect/EffectSkillBase.h"
#include "Skill/Effect/HoldEffect/HoldEffect.h"

#include "Buff.generated.h"


UCLASS(BlueprintType)
class CHUANGSHI_API UBuff :public UCS3Object
{
	GENERATED_BODY()
public:
	UBuff();
	~UBuff();

public:
	/*��ʼ��buff����*/
	virtual void init(FString BuffID, const FBUFF_TABLE_DATA* dictDat);

	/*���ڸ�Ŀ��ʩ��һ��buff�����е�buff�Ľ��ն�����ͨ���˽ӿڣ�
		�˽ӿڱ����жϽ������Ƿ�ΪrealEntity*/
	virtual bool receive(CS3Entity* caster , CS3Entity* receiver);

	/*ͨ�������ߡ��滻�ȵȵȵ����أ�����Ҫ��buff*/
	virtual bool receiveSuccess(CS3Entity* caster, CS3Entity* receiver);

	/*��Ӽ��*/
	virtual bool addBuffCheck(CS3Entity* caster, CS3Entity* receiver);

	/*Ч����ʼ*/
	virtual void doBegin(CS3Entity* receiver, UBuffDataType* buffData);

	/*�������¼���buff*/
	virtual void doReload(CS3Entity* receiver, UBuffDataType* buffData);

	/*Ч������*/
	virtual void doEnd(CS3Entity* receiver, UBuffDataType* buffData, BUFF_END_RESON reason);

	/*���Buff����*/
	virtual void doClear(CS3Entity* receiver, UBuffDataType* buffData, BUFF_END_RESON reason);

	/*���س���Ч��*/
	virtual void addHoldEffect(CS3Entity* receiver, UBuffDataType* buffData ,bool isReloadBuff = false);

	/*���س���Ч��*/
	virtual void removeHoldEffect(CS3Entity* receiver, UBuffDataType* buffData);

	/*���س���Ч��*/
	virtual void onClientActorCreate(CS3Entity* receiver, UBuffDataType* buffData);

	/*�ж�*/
	virtual	void doInterrupt(CS3Entity* receiver, UBuffDataType* buffData);

	/*��������*/
	virtual	void doLoop(CS3Entity* receiver, UBuffDataType* buffData);

	/*��ô��*/
	virtual UBuffHitDefine* getHit(FString attrName, int32 index);

	/*���ڴ��*/
	virtual	void doLoopHit(CS3Entity* receiver, UBuffDataType* buffData);

	/*��ʼ���*/
	virtual	void doBeginHit(CS3Entity* receiver, UBuffDataType* buffData);

	/*�������*/
	virtual	void doEndHit(CS3Entity* receiver, UBuffDataType* buffData);

	/*�жϴ��*/
	virtual void doInterruptHit(CS3Entity* receiver, UBuffDataType* buffData);

	/*����*/
	virtual	void doStack(CS3Entity* receiver, UBuffDataType* buffData);

	/*ע���¼�*/
	virtual	void registerEvent(CS3Entity* receiver, UBuffDataType* buffData);

	/*ɾ���¼�*/
	virtual	void unRegisterEvent(CS3Entity* receiver, UBuffDataType* buffData);

	/*����������buff�¼�*/
	virtual void triggerBuffEvent(CS3Entity* receiver, ENUM_SKILL_EVENT eventType, int32 triggerID, UBuffDataType * buffData, TMap<FString, FVariant> pDict);

	/*����ʩ����buff�¼�*/
	virtual void triggerCasterBuffEvent(CS3Entity* receiver, ENUM_SKILL_EVENT eventType, int32 triggerID, UBuffDataType * buffData, TMap<FString, FVariant> pDict);

	/*�����µ�buff����*/
	virtual UBuffDataType* getNewBuffData(CS3Entity* caster, CS3Entity* receiver);

	/*��ȡbuffʣ��ʱ��*/
	float getBuffRemainTime(UBuffDataType* buffData);

	/*���ݳ���ʱ��������ʱ��*/
	int64 calculateEndTime(float holdTime);

	/*����Ƿ��ѳ�ʱ*/
	virtual bool isTimeout(UBuffDataType* buffData);

	/*��ýű�����*/
	FString getScriptType();

	/*���ID*/
	int32 getID();

	/*���Buff����*/
	FString getBuffName();

	/*��ȡ����*/
	ACTION_FLAG getActForbid();

	/*��ȡ��������*/
	ENUM_BUFF_SAVE_TYPE getSaveType();

	/*��ȡ����ʱ��*/
	float getHoldTime();

	/*��ȡ����ʱ��*/
	float getLoopTime();

	/*�Ƿ����ĳЧ��*/
	bool isHoldEffect(ENUM_HOLD_EFFECT_TYPE effectName);

protected:
	bool isInterruptBuff;
	FString _buffName;
	FString _className;
	int32 _id;
	float _holdTime;
	float _loopTime;
	FString _buffEffect;
	FString _buffSound;
	TArray<FString> _buffAction;
	TArray<FString> _buffActionBeginTime;
	TArray<ENUM_HOLD_EFFECT_TYPE> _holdEffectNames;	///<����Ч������
	ACTION_FLAG _actForbid;
	ENUM_BUFF_SAVE_TYPE _saveType;		///<���߱�������
	UPROPERTY()
	UBuffReplaceCondition * _replaceCondition;  ///<�û�����
	UPROPERTY()
	TArray<UEffectSkillBase*> _replaceEffectList; ///<�û�Ч���б�
	UPROPERTY()
	UBuffExtraCondition * _extraCondition;		///<��������
	UPROPERTY()
	TArray<UEffectSkillBase*> _extraEffectList; ///<����Ч���б�
	UPROPERTY()
	TArray<UHoldEffect*> _holdEffectList;	///<����Ч���б�
	UPROPERTY()
	UReceiverEventDefine* _targetInterruptEvent;	///<�������ж��¼�
	UPROPERTY()
	UEventDefine* _casterInterruptEvent;			///<ʩ�����ж��¼�
};


