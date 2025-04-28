#pragma once
#include "CoreMinimal.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/CS3Object.h"
#include "GameData/Skill/SkillTableData.h"
#include "HitTypeDefine.generated.h"

/*
* �ļ����ƣ�HitTypeDefine.h
* ����˵�����������Ͷ���
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API UHitBase :public UCS3Object
{
	GENERATED_BODY()
public:
	UHitBase();
	~UHitBase();

public:
	/*
	*Define method
	*�ж��Ƿ�����
	*/
	SKILL_HIT_TYPE isHit(CS3Entity* caster, CS3Entity* receiver);
};

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API UHitDirect : public UHitBase
{
	GENERATED_BODY()
public:
	UHitDirect();
	~UHitDirect();

public:
	/*
	*Define method
	*�ж��Ƿ�����
	*/
	SKILL_HIT_TYPE isHit(CS3Entity* caster, CS3Entity* receiver);
};
UCLASS(BlueprintType)
class CHUANGSHI_API UHitDodge : public UHitBase
{
	GENERATED_BODY()
public:
	UHitDodge();
	~UHitDodge();

public:
	/*
	*Define method
	*�ж��Ƿ�����
	*/
	SKILL_HIT_TYPE isHit(CS3Entity* caster, CS3Entity* receiver);
};

UCLASS(BlueprintType)
class CHUANGSHI_API UHitTypeDefine:public UCS3Object
{
	GENERATED_BODY()
public:
	~UHitTypeDefine();
	/*����*/
	static UHitTypeDefine* GetInstance();
	SKILL_HIT_TYPE isHit(ENUM_HIT_TYPE type, CS3Entity* caster, CS3Entity* receiver);
private:
	UHitTypeDefine();

	static UHitTypeDefine* Instance;
};

UHitTypeDefine* UHitTypeDefine::Instance = nullptr;