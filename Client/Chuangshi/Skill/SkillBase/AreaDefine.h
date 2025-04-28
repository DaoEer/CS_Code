#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "CS3Base/CS3Entity.h"
#include "GameData/GameDeFine.h"
#include "GameData/Skill/SkillTableData.h"
#include "SkillTargetObjImpl.h"
#include "AreaDefine.generated.h"

/*
* �ļ����ƣ�AreaDefine.h
* ����˵����������������
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API UArea :public UCS3Object
{
	GENERATED_BODY()
public:
	UArea();
	~UArea();
public:
	/*���ݼ���*/
	virtual void load(FSKILL_HIT_AREA dictDat);

	/**
	*Define method
	*��ü���λ��
	*@prama caster �������ĵĶ���
	*@prama target ����Ŀ��
	*@prama receiverList �������б�
	*
	*return ��ɸѡ����������б�
	*/
	virtual TArray<CS3Entity*> getObjectList(CS3Entity* caster, USkillTargetObjImpl* target);

	/*��ȡ����*/
	virtual FVector GetPosition(CS3Entity* caster, USkillTargetObjImpl* target);
	/*��ȡ����*/
	virtual FVector GetDirection(CS3Entity* caster, USkillTargetObjImpl* target);

	/*ɸѡ�������� �� ����������֮��ĸ߶� */
	TArray<CS3Entity*> filterHeight(FVector position, TArray<CS3Entity*> receivers);

	/*����ƫ����*/
	FVector calculateOffset(FVector position, FVector direction);

	/*����ƫ�ƽǶ�*/
	float calculateYaw(float yaw);

	/*ɸѡԲ�η�Χ*/
	TArray<CS3Entity*> filterCircular(TArray<CS3Entity*> receivers, FVector centerPos, float radius);
protected:
	int32 unitReference;	//��λλ�û�׼
	int32 direReference;	//��λ�����׼
	float maxHeight;	//AOE���ܼ���һ���߶ȵļ��
	float height; //�����߶�
	float offsetFront;	//��ǰƫ����
	float offsetLeft;	//����ƫ����
	float offsetUp;		//����ƫ����
	int32 offsetyaw;	//ƫ�ƽǶ�
};


/*�޷�Χ(�մ��)*/
UCLASS(BlueprintType)
class CHUANGSHI_API UNoRange :public UArea
{
	GENERATED_BODY()
public:
	UNoRange();
	~UNoRange();

public:
	virtual void load(FSKILL_HIT_AREA dictDat);
	virtual TArray<CS3Entity*> getObjectList(CS3Entity* caster, USkillTargetObjImpl* target);
};

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API USingle :public UArea
{
	GENERATED_BODY()
public:
	USingle();
	~USingle();
public:
	virtual void load(FSKILL_HIT_AREA dictDat);
	virtual TArray<CS3Entity*> getObjectList(CS3Entity* caster, USkillTargetObjImpl* target);
};


/*����״*/
UCLASS(BlueprintType)
class CHUANGSHI_API USphere :public UArea
{
	GENERATED_BODY()
public:
	USphere();
	~USphere();

public:
	virtual void load(FSKILL_HIT_AREA dictDat);
	virtual TArray<CS3Entity*> getObjectList(CS3Entity* caster, USkillTargetObjImpl* target);

private:
	float radius;
};

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API URectangle :public UArea
{
	GENERATED_BODY()
public:
	URectangle();
	~URectangle();

public:
	virtual void load(FSKILL_HIT_AREA dictDat);
	virtual TArray<CS3Entity*> getObjectList(CS3Entity* caster, USkillTargetObjImpl* target);
	bool inArea(FVector dstPos, FVector srcPos, float yaw);

private:
	float length = 0.0;	 //��
	float width = 0.0;  //��
};

/*Բ����*/
UCLASS(BlueprintType)
class CHUANGSHI_API UCircular :public UArea
{
	GENERATED_BODY()
public:
	UCircular();
	~UCircular();

public:
	virtual void load(FSKILL_HIT_AREA dictDat);
	virtual TArray<CS3Entity*> getObjectList(CS3Entity* caster, USkillTargetObjImpl* target);

private:
	float radius = 0.0;
};

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API USector :public UArea
{
	GENERATED_BODY()
public:
	USector();
	~USector();

public:
	virtual void load(FSKILL_HIT_AREA dictDat);
	virtual TArray<CS3Entity*> getObjectList(CS3Entity* caster, USkillTargetObjImpl* target);
	bool inArea(FVector dstPos, FVector srcPos, float yaw);

private:
	float radius = 0.0; //�뾶
	float angle = 0.0; //�н�
};

/*����*/
UCLASS(BlueprintType)
class CHUANGSHI_API UAnnulus :public UArea
{
	GENERATED_BODY()
public:
	UAnnulus();
	~UAnnulus();

public:
	virtual void load(FSKILL_HIT_AREA dictDat);
	virtual TArray<CS3Entity*> getObjectList(CS3Entity* caster, USkillTargetObjImpl* target);

private:
	float outerDiameter = 0.0;  //�⾶
	float innerDiameter = 0.0; //�ھ�
};



UArea* NewAreaInstance(FSKILL_HIT_AREA dictData);