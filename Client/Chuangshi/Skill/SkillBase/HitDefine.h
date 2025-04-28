#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/GameDeFine.h"
#include "GameData/Skill/SkillTableData.h"
#include "GameData/Skill/BuffTableData.h"
#include "SkillTargetObjImpl.h"
#include "Skill/Effect/EffectSkillBase.h"
#include "AreaDefine.h"
#include "ObjectCondition.h"
#include "FilterCondition.h"
#include "HitDefine.generated.h"

/*
* �ļ����ƣ�HitDefine.h
* ����˵�����������ö�����
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

class USkill;
class UBuff;

UCLASS(BlueprintType)
class CHUANGSHI_API UHitDefine:public UCS3Object
{
	GENERATED_BODY()
public:
	UHitDefine();
	~UHitDefine();
public:
	/*��ʼ������*/
	virtual void init(FSKILL_HIT dictDat, USkill* skill);

	/*���ܴ��Ч��*/
	virtual void receive(USkill* skill, CS3Entity* caster, CS3Entity* receiver);

	/*�ж�Ŀ���Ƿ���Ч*/
	virtual int32 validReceiver(CS3Entity* caster, CS3Entity* receiver);

	/*ɸѡ�����кϷ���*/
	virtual TArray<CS3Entity*> filterReceiver(USkill* skill, CS3Entity* caster, USkillTargetObjImpl* target, TArray<CS3Entity*> receivers);

	/*ȡ�����еķ���������������Entity�б�*/
	virtual TArray<CS3Entity*> getReceivers(USkill* skill, CS3Entity* caster, USkillTargetObjImpl* target);


	virtual TArray<UEffectSkillBase*> getEffectList();


protected:
	ENUM_HIT_TYPE _hitType;

	UPROPERTY()
	UArea* _hitArea; //�����Χ

	UPROPERTY()
	UObjectCondition* _receiverCondition; //����������

	UPROPERTY()
	UFilterCondition* _fliterCondition;  //������ɸѡ����

	UPROPERTY()
	TArray<UEffectSkillBase*>_effectList; //���Ч���б�
};


UCLASS(BlueprintType)
class CHUANGSHI_API USkillHitDefine :public UHitDefine
{
	GENERATED_BODY()
public:
	USkillHitDefine();
	~USkillHitDefine();

public:
	/*��ʼ������*/
	virtual void init(FSKILL_HIT dictDat, USkill* skill);

	/*��ʼ���*/
	void onHit(USkill* skill, CS3Entity* caster, USkillTargetObjImpl* target, int32 index);

	/*�������*/
	void onHitArrive(USkill* skill, CS3Entity* caster, USkillTargetObjImpl* target, int32 index);

private:
	UPROPERTY()
	int32 _hitTime;
};

UCLASS(BlueprintType)
class CHUANGSHI_API UBuffHitDefine :public UCS3Object
{
	GENERATED_BODY()
public:
	UBuffHitDefine();
	~UBuffHitDefine();

public:
	/*��ʼ������*/
	void init(FBUFF_HIT dictDat, UBuff * buff);

	/*���ܴ��Ч��*/
	void receive(UBuff * buff, CS3Entity* caster, CS3Entity* receiver);

	/*�ж�Ŀ���Ƿ���Ч*/
	int32 validReceiver(CS3Entity* caster, CS3Entity* receiver);

	/*ɸѡ�����кϷ���*/
	TArray<CS3Entity*> filterReceiver(UBuff * buff, CS3Entity* caster, USkillTargetObjImpl* target, TArray<CS3Entity*> receivers);

	/*ȡ�����еķ���������������Entity�б�*/
	TArray<CS3Entity*> getReceivers(UBuff * buff, CS3Entity* caster, USkillTargetObjImpl* target);

	TArray<UEffectSkillBase*> getEffectList();

	/*�������*/
	void onHitArrive(UBuff* buff, CS3Entity* caster, USkillTargetObjImpl* target, FString attrName, int32 index);


private:
	ENUM_HIT_TYPE _hitType;

	UPROPERTY()
		UArea* _hitArea; //�����Χ

	UPROPERTY()
		UObjectCondition* _receiverCondition; //����������

	UPROPERTY()
		UFilterCondition* _fliterCondition;  //������ɸѡ����

	UPROPERTY()
		TArray<UEffectSkillBase*>_effectList; //���Ч���б�
};



USTRUCT(BlueprintType)
struct CHUANGSHI_API FSKILL_HIT_DATAS
{
	GENERATED_BODY();
public:
	UPROPERTY()
	TArray< USkillHitDefine* > SkillHitDefines;
};


UCLASS(BlueprintType)
class CHUANGSHI_API USkillHitData :public UCS3Object
{
	GENERATED_BODY()
public:
	USkillHitData();
	~USkillHitData();
public:
	/*��ʼ������*/
	void init(TArray<FSKILL_HIT> hitList, USkill* skill);

	/*��ʼ*/
	void begin(USkill* skill, CS3Entity* caster, USkillTargetObjImpl* target);

	/*��ʼĳһʱ�̵Ĵ��*/
	void onHit(USkill* skill, CS3Entity* caster, USkillTargetObjImpl* target, int32 hitTime);

	/*�������*/
	void onHitArrive(USkill* skill, CS3Entity* caster, USkillTargetObjImpl* target, int32 hitTime, int32 index);

	USkillHitDefine* getHit(int32 hitTime, int32 index);
	float getTotalTime();
	TMap<int32, FSKILL_HIT_DATAS> getHitData();



private:
	UPROPERTY()
		TMap<int32, FSKILL_HIT_DATAS> _data;
};


UCLASS(BlueprintType)
class CHUANGSHI_API UBuffHitData :public UCS3Object
{
	GENERATED_BODY()
public:
	UBuffHitData();
	~UBuffHitData();

public:
	/*��ʼ������*/
	void init(TArray<FBUFF_HIT> hitList, UBuff* buff);

	UBuffHitDefine* getHit(int32 index);

	void onHit(UBuff* buff, CS3Entity* caster, USkillTargetObjImpl* target, FString attrName);
private:
	UPROPERTY()
	TArray< UBuffHitDefine* > _data;
};