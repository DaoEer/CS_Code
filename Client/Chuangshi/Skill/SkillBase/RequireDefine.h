#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/Skill/SkillTableData.h"
#include "RequireDefine.generated.h"

/**
*
* ����������
*
*/

class USkill;
/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API URequire :public UCS3Object
{
	GENERATED_BODY()
public:
	URequire();
	~URequire();
public:
	/*���ݼ���*/
	virtual void load(FSKILL_REQUIRE Args);

	/**
	*Define method
	*У������Ƿ���������
	*@prama caster �������ĵĶ���
	*@prama skillInstance ����ʵ��
	*return ������Ϣ
	*/
	virtual int32 validObject(CS3Entity* caster, USkill* SkillInstance);

	/**
	*Define method
	*֧��������
	*@prama caster �������ĵĶ���
	*@prama skillInstance ����ʵ��
	*return ��
	*/
	virtual void pay(CS3Entity* caster, USkill* SkillInstance);

	/**
	*
	*��ȡ������
	*@prama caster �������ĵĶ���
	*@prama skillInstance ����ʵ��
	*return ������Ϣ
	*/
	virtual int32 getPay(CS3Entity* caster, USkill* skillInstance);

protected:
	int32 _value;
	float _percent;
};

/*����(MP)����*/
UCLASS(BlueprintType)
class CHUANGSHI_API URequireMp :public URequire
{
	GENERATED_BODY()
public:
	URequireMp();
	~URequireMp();
public:
	
	virtual void load(FSKILL_REQUIRE Args);

	virtual int32 validObject(CS3Entity* caster, USkill* SkillInstance);

	virtual void pay(CS3Entity* caster, USkill* SkillInstance);

	virtual int32 getPay(CS3Entity* caster, USkill* skillInstance);
};

/*Ѫ��(HP)����*/
UCLASS(BlueprintType)
class CHUANGSHI_API URequireHp :public URequire
{
	GENERATED_BODY()
public:
	URequireHp();
	~URequireHp();
public:
	virtual void load(FSKILL_REQUIRE Args);

	virtual int32 validObject(CS3Entity* caster, USkill* SkillInstance);

	virtual void pay(CS3Entity* caster, USkill* SkillInstance);

	virtual int32 getPay(CS3Entity* caster, USkill* skillInstance);
};

/*�������*/
UCLASS(BlueprintType)
class CHUANGSHI_API URequireGangQi :public URequire
{
	GENERATED_BODY()
public:
	URequireGangQi();
	~URequireGangQi();

public:
	virtual void load(FSKILL_REQUIRE Args);

	virtual int32 validObject(CS3Entity* caster, USkill* SkillInstance);

	virtual void pay(CS3Entity* caster, USkill* SkillInstance);

	virtual int32 getPay(CS3Entity* caster, USkill* skillInstance);
};

/*��Ʒ����*/
UCLASS(BlueprintType)
class CHUANGSHI_API URequireCostItem :public URequire
{
	GENERATED_BODY()
public:
	URequireCostItem();
	~URequireCostItem();

public:
	virtual void load(FSKILL_REQUIRE Args);

	virtual int32 validObject(CS3Entity* caster, USkill* SkillInstance);

	virtual void pay(CS3Entity* caster, USkill* SkillInstance);

	virtual int32 getPay(CS3Entity* caster, USkill* skillInstance);

private:
	int32 _itemID;
	int32 _amount;
};



UCLASS(BlueprintType)
class CHUANGSHI_API URequireDefine : public UCS3Object
{
	GENERATED_BODY()
public:
	URequireDefine();
	~URequireDefine();
public:
	/*���ݼ���*/
	void load(TArray<FSKILL_REQUIRE> Args);

	/*У������Ƿ���������*/
	int32 validObject(CS3Entity* caster, USkill* SkillInstance);
	/*֧��*/
	void pay(CS3Entity* caster, USkill* SkillInstance);

private:
	
	UPROPERTY()
	TArray<URequire*> _requires; //����ʵ���б�
};