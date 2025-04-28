#pragma once
#include "CoreMinimal.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/CS3Object.h"
#include "SkillTargetObjImpl.h"
#include "GameData/Skill/SkillTableData.h"
#include "ObjectDefine.generated.h"

/*
* �ļ����ƣ�ObjectDefine.h
* ����˵����ʩ��Ŀ��ķ�װ
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API UTargetBase :public UCS3Object
{
	GENERATED_BODY()
public:
	UTargetBase();
	~UTargetBase();
public:
	/*��ʼ������*/
	virtual void init(const FSKILL_TABLE_DATA* dictDat);
	/*�������*/
	virtual ENUM_CAST_TARGET_TYPE GetType();
	/*�ж��Ƿ����ʩ��*/
	virtual int32 CastValid(CS3Entity* caster, USkillTargetObjImpl* target);

protected:
	/*ʩ��������*/
	float CastRangeMax;
	/*����ʩչ��ʽ*/
	ENUM_CAST_TARGET_TYPE type;

};



/*��ʩ��λ�úͶ���*/
UCLASS(BlueprintType)
class CHUANGSHI_API UTargetNothing :public UTargetBase
{
	GENERATED_BODY()
public:
	UTargetNothing();
	~UTargetNothing();

public:
	/*��ʼ������*/
	virtual void init(const FSKILL_TABLE_DATA* dictDat);
	/*�������*/
	virtual ENUM_CAST_TARGET_TYPE GetType();
	/*�ж��Ƿ����ʩ��*/
	virtual int32 CastValid(CS3Entity* caster, USkillTargetObjImpl* target);


}; 

/*ʩ��Ŀ��Ϊλ��*/
UCLASS(BlueprintType)
class CHUANGSHI_API UTargetPosition : public UTargetBase
{
	GENERATED_BODY()
public:
	UTargetPosition();
	~UTargetPosition();
public:
	virtual void init(const FSKILL_TABLE_DATA* dictDat);
	virtual ENUM_CAST_TARGET_TYPE GetType();
	virtual int32 CastValid(CS3Entity* caster, USkillTargetObjImpl* target);


};

/*ʩ��Ŀ��Ϊ������Entity*/
UCLASS(BlueprintType)
class CHUANGSHI_API UTargetLock : public UTargetBase
{
	GENERATED_BODY()
public:
	UTargetLock();
	~UTargetLock();

public:
	virtual void init(const FSKILL_TABLE_DATA* dictDat);
	virtual ENUM_CAST_TARGET_TYPE GetType();
	virtual int32 CastValid(CS3Entity* caster, USkillTargetObjImpl* target);

};

/*����ʵ��*/
UTargetBase * ObjectDefineNewInstance(ENUM_CAST_TARGET_TYPE type);