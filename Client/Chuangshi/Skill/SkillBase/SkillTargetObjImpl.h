#pragma once
#include "CoreMinimal.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/GameDeFine.h"
#include "GameData/CS3Object.h"
#include "SkillTargetObjImpl.generated.h"


/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API USkillTargetObjImpl :public UCS3Object
{
	GENERATED_BODY()
public:
	USkillTargetObjImpl();
	~USkillTargetObjImpl();
	virtual SKILL_TARGET_TYPE getType();
	virtual CS3Entity* getObject();
	virtual FVector getObjectPosition();
	virtual void onSkillBegin(CS3Entity* caster);

protected:
	SKILL_TARGET_TYPE _type;

};

/*���ܶ���Ŀ���λ�õ�ʩ������ķ�װ*/
UCLASS(BlueprintType)
class CHUANGSHI_API USkillTargetObjNone :public USkillTargetObjImpl
{
	GENERATED_BODY()
public:
	USkillTargetObjNone();
	~USkillTargetObjNone();
public:
	virtual SKILL_TARGET_TYPE getType();
	virtual CS3Entity* getObject();
	virtual FVector getObjectPosition();
};

/*���ܶ�entity��������Ŀ��ķ�װ*/
UCLASS(BlueprintType)
class CHUANGSHI_API USkillTargetObjEntity :public USkillTargetObjImpl
{
	GENERATED_BODY()
public:
	USkillTargetObjEntity();
	~USkillTargetObjEntity();

public:
	void init(CS3Entity* entity);
	virtual SKILL_TARGET_TYPE getType();
	virtual CS3Entity* getObject();
	virtual FVector getObjectPosition();
	virtual void onSkillBegin(CS3Entity* caster);
private:
	int32 _entityID;
};

/*���ܶ�λ�õ�������Ŀ��ķ�װ*/
UCLASS(BlueprintType)
class CHUANGSHI_API USkillTargetObjPosition :public USkillTargetObjImpl
{
	GENERATED_BODY()
public:
	USkillTargetObjPosition();
	~USkillTargetObjPosition();
public:
	void init(FVector position);
	virtual SKILL_TARGET_TYPE getType();
	virtual FVector getObjectPosition();
private:
	FVector _entityPosition;
};



