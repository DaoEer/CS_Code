#pragma once
#include "CoreMinimal.h"
#include "Skill/Buff/BuffClientHit.h"
#include "BuffClientLoop.generated.h"


/*
* �ļ����ƣ�BuffClientLoop.h
* ����˵�����ͻ�������buff
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-26
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UBuffClientLoop :public UBuffClientHit
{
	GENERATED_BODY()
public:
	UBuffClientLoop();
	~UBuffClientLoop();

public:
	/*��ʼ��buff����*/
	virtual void init(FString BuffID, const FBUFF_TABLE_DATA* dictDat);

	/*Ч����ʼ*/
	virtual void doBegin(CS3Entity* receiver, UBuffDataType* buffData);

	/*�������¼���buff*/
	virtual void doReload(CS3Entity* receiver, UBuffDataType* buffData);

	/*Ч������*/
	virtual void doEnd(CS3Entity* receiver, UBuffDataType* buffData, BUFF_END_RESON reason);

	/*���ڴ��*/
	virtual	void doLoopHit(CS3Entity* receiver, UBuffDataType* buffData);

	/*��ô��*/
	virtual UBuffHitDefine* getHit(FString attrName, int32 index);

	/*���loop Timer*/
	void addBuffLoopTimer(CS3Entity* receiver, UBuffDataType* buffData);

protected:
	UPROPERTY()
	UBuffHitData* _loopHitList;
};



