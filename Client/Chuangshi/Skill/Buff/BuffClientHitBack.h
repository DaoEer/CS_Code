#pragma once
#include "CoreMinimal.h"
#include "Skill/Buff/BuffClientHit.h"
#include "BuffClientHitBack.generated.h"


/*
* �ļ����ƣ�BuffClientHitBack.h
* ����˵�����ܻ�����buff���ܻ���������Ч����Ч,����λ�ƣ�
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-26
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UBuffClientHitBack :public UBuffClientHit
{
	GENERATED_BODY()
public:
	UBuffClientHitBack();
	~UBuffClientHitBack();
public:
	/*��ʼ��buff����*/
	virtual void init(FString BuffID, const FBUFF_TABLE_DATA* dictDat);

	/*���ڸ�Ŀ��ʩ��һ��buff�����е�buff�Ľ��ն�����ͨ���˽ӿڣ�
		�˽ӿڱ����жϽ������Ƿ�ΪrealEntity*/
	virtual bool receive(CS3Entity* caster, CS3Entity* receiver);

	/*ͨ�������ߡ��滻�ȵȵȵ����أ�����Ҫ��buff*/
	virtual bool receiveSuccess(CS3Entity* caster, CS3Entity* receiver);

	/*��Ӽ��*/
	virtual bool addBuffCheck(CS3Entity* caster, CS3Entity* receiver);

	/*Ч����ʼ*/
	virtual void doBegin(CS3Entity* receiver, UBuffDataType* buffData);

	/*Ч������*/
	virtual void doEnd(CS3Entity* receiver, UBuffDataType* buffData, BUFF_END_RESON reason);

	/*����*/
	void doHitBack(CS3Entity* receiver, UBuffDataType* buffData);

	/*����*/
	void endHitBack(CS3Entity* receiver, UBuffDataType* buffData);
private:
	FString _actionID = "";
	float _moveTime = 0.0f;
	float _distMin = 0.0f;
	float _distMax = 0.0f;
	float _actionBeginTime = 0.0f;
	FString _endActionID = "";
	TArray<FString> _getUpActionID;
	TArray<FString> _getUpActionBeginTime;
	float _getUpActionDelayTime = 0.0f;
	BUFF_HIT_DIRECTION _directionType = BUFF_HIT_DIRECTION::BUFF_HIT_TYPE_CASTER_DIRECTION;
	BUFF_HIT_TYPE _hitBackType = BUFF_HIT_TYPE::BUFF_HIT_TYPE_CASTER_FORWARD;

};




