#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/Skill/SkillTableData.h"
#include "SkillTargetObjImpl.h"
#include "FilterCondition.generated.h"

/*
* �ļ����ƣ�FilterCondition.h
* ����˵����������ɸѡ����
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

class USkill;

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API UFilterBase :public UCS3Object
{
	GENERATED_BODY()
public:
	UFilterBase();
	~UFilterBase();

public:
	/*���ݼ���*/
	virtual void init(FRECEIVER_FLITER_CONDITION dictDat);

	/**
	*Define method
	*�������
	*@prama caster �������ĵĶ���
	*@prama target ����Ŀ��
	*@prama receiverList �������б�
	*
	*return ��ɸѡ����������б�
	*/
	virtual TArray<CS3Entity*> filter(CS3Entity* caster, USkillTargetObjImpl* target, TArray<CS3Entity*> receiverList);
};

/*��������������*/
UCLASS(BlueprintType)
class CHUANGSHI_API UOrderByRandom :public UFilterBase
{
	GENERATED_BODY()
public:
	UOrderByRandom();
	~UOrderByRandom();
public:
	virtual void init(FRECEIVER_FLITER_CONDITION dictDat);
	virtual TArray<CS3Entity*> filter(CS3Entity* caster, USkillTargetObjImpl* target, TArray<CS3Entity*> receiverList);
private:
	int32 _maxNumber;
};

/*��λ��������*/
UCLASS(BlueprintType)
class CHUANGSHI_API UOrderByProperty :public UFilterBase
{
	GENERATED_BODY()
public:
	UOrderByProperty();
	~UOrderByProperty();
public:
	virtual void init(FRECEIVER_FLITER_CONDITION dictDat);
	virtual TArray<CS3Entity*> filter(CS3Entity* caster, USkillTargetObjImpl* target, TArray<CS3Entity*> receiverList);
private:
	FString _property;
	int32 _operation;
	int32 _maxNumber;
};

/*ʩ���߾�������*/
UCLASS(BlueprintType)
class CHUANGSHI_API UOrderByDistanceToCaster :public UFilterBase
{
	GENERATED_BODY()
public:
	UOrderByDistanceToCaster();
	~UOrderByDistanceToCaster();
public:
	virtual void init(FRECEIVER_FLITER_CONDITION dictDat);
	virtual TArray<CS3Entity*> filter(CS3Entity* caster, USkillTargetObjImpl* target, TArray<CS3Entity*> receiverList);
private:
	FString _property;
	int32 _operation;
	int32 _maxNumber;
};


/*ʩ��Ŀ���������*/
UCLASS(BlueprintType)
class CHUANGSHI_API UOrderByDistanceToTarget :public UFilterBase
{
	GENERATED_BODY()
public:
	UOrderByDistanceToTarget();
	~UOrderByDistanceToTarget();
public:
	virtual void init(FRECEIVER_FLITER_CONDITION dictDat);
	virtual TArray<CS3Entity*> filter(CS3Entity* caster, USkillTargetObjImpl* target, TArray<CS3Entity*> receiverList);
private:
	FString _property;
	int32 _operation;
	int32 _maxNumber;
};


UCLASS(BlueprintType)
class CHUANGSHI_API UFilterCondition :public UCS3Object
{
	GENERATED_BODY()
public:
	UFilterCondition();
	~UFilterCondition();
public:
	/*���ݼ���*/
	void init(TArray<FRECEIVER_FLITER_CONDITION> conditionList);
	void add(FRECEIVER_FLITER_CONDITION Condition);
	/*�������*/
	TArray<CS3Entity*> filter(USkill* Skill, CS3Entity* caster, USkillTargetObjImpl* target, TArray<CS3Entity*> receiverList);
public:
	UPROPERTY()
		TArray <UFilterBase *> _conditions;  //����ʵ�б�
};

