#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/Skill/SkillTableData.h"
#include "SkillTargetObjImpl.h"
#include "ObjectCondition.generated.h"

/*
* �ļ����ƣ�ObjectCondition.h
* ����˵����ʩ����/����������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API UConditionBase :public UCS3Object
{
	GENERATED_BODY()
public:
	UConditionBase();
	~UConditionBase();
public:
	virtual void init(FSKILL_USE_CONDITION dictDat );
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);
};

/*Ŀ�����͡���ϵ*/
UCLASS(BlueprintType)
class CHUANGSHI_API UConditionTypeRelation :public UConditionBase
{
	GENERATED_BODY()
public:
	UConditionTypeRelation();
	~UConditionTypeRelation();
public:
	virtual void init(FSKILL_USE_CONDITION dictDat);
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);

private:
	TArray<FString> entityTypes;
	TArray<int32> relationTypes;
};

/*�Ƿ���ĳ״̬*/
UCLASS(BlueprintType)
class CHUANGSHI_API UConditionState :public UConditionBase
{
	GENERATED_BODY()
public:
	UConditionState();
	~UConditionState();

public:
	virtual void init(FSKILL_USE_CONDITION dictDat);
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);

private:
	TArray<int32> stateList;
	int32 isThisState;
};

/*ָ��ID��Buff�ĸ���*/
UCLASS(BlueprintType)
class CHUANGSHI_API UConditionBuffCount :public UConditionBase
{
	GENERATED_BODY()
public:
	UConditionBuffCount();
	~UConditionBuffCount();

public:
	virtual void init(FSKILL_USE_CONDITION dictDat);
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);

private:
	TArray<int32> _buffIdList;
	int32 _operation = 0;
	float _scale = 0.0;
};

/*ָ��ID��Buff�Ĳ���*/
UCLASS(BlueprintType)
class CHUANGSHI_API UConditionBuffLayer :public UConditionBase
{
	GENERATED_BODY()
public:
	UConditionBuffLayer();
	~UConditionBuffLayer();

public:
	virtual void init(FSKILL_USE_CONDITION dictDat);
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);

private:
	int32 _buffID = 0;
	int32 _operation = 0;
	float _scale = 0.0;
};

/*�жԹ�ϵ*/
UCLASS(BlueprintType)
class CHUANGSHI_API UConditionEnemy :public UConditionBase
{
	GENERATED_BODY()
public:
	UConditionEnemy();
	~UConditionEnemy();

public:
	virtual void init(FSKILL_USE_CONDITION dictDat);
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);

private:
	TArray<int32> _assemble;
	int32 _operation;
};

/*�Ƿ�ָ����ID*/
UCLASS(BlueprintType)
class CHUANGSHI_API UConditionScriptID :public UConditionBase
{
	GENERATED_BODY()
public:
	UConditionScriptID();
	~UConditionScriptID();

public:
	virtual void init(FSKILL_USE_CONDITION dictDat);
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);

private:
	TArray<int32> ScriptIDList;
	int32 _isThisType = 0;
	int32 needRole = 0;
};

/*Ч��״̬Ҫ��*/
UCLASS(BlueprintType)
class CHUANGSHI_API UConditionEffectState :public UConditionBase
{
	GENERATED_BODY()
public:
	UConditionEffectState();
	~UConditionEffectState();

public:
	virtual void init(FSKILL_USE_CONDITION dictDat);
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);

private:
	TArray<int32> effectStateList;
	int32 isThisState;
};



UCLASS(BlueprintType)
class CHUANGSHI_API UObjectCondition :public UCS3Object
{
	GENERATED_BODY()
public:
	UObjectCondition();
	~UObjectCondition();

public:
	virtual void init(TArray<FSKILL_USE_CONDITION> Conditions);
	void add(FSKILL_USE_CONDITION Condition);
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);
	bool isHasConditions(); 

protected:
	UPROPERTY()
	TArray<UConditionBase *> _conditions;  //����ʵ�б�
};


/*buff�滻Ч������*/
UCLASS(BlueprintType)
class CHUANGSHI_API UBuffReplaceCondition :public UObjectCondition
{
	GENERATED_BODY()
public:
	UBuffReplaceCondition();
	~UBuffReplaceCondition();

public:
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);
private:

};

/*buff����Ч������*/
UCLASS(BlueprintType)
class UBuffExtraCondition :public UObjectCondition
{
	GENERATED_BODY()
public:
	UBuffExtraCondition();
	~UBuffExtraCondition();

public:
	virtual int32 valid(CS3Entity* caster, CS3Entity* target, bool isCastValidCheck);
private:

};


