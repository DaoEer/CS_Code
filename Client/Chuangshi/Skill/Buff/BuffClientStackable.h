#pragma once
#include "CoreMinimal.h"
#include "Skill/Buff/BuffClientLoop.h"
#include "BuffClientStackable.generated.h"


/*
* �ļ����ƣ�BuffClientStackable.h
* ����˵�����ɵ��ӵĳ���buff
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-26
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UBuffClientStackable :public UBuffClientLoop
{
	GENERATED_BODY()
public:
	UBuffClientStackable();
	~UBuffClientStackable();

public:
	/*��ʼ��buff����*/
	virtual void init(FString BuffID, const FBUFF_TABLE_DATA* dictDat);

	/*ͨ�������ߡ��滻�ȵȵȵ����أ�����Ҫ��buff*/
	virtual bool receiveSuccess(CS3Entity* caster, CS3Entity* receiver);

	/*���س���Ч��*/
	virtual void addHoldEffect(CS3Entity* receiver, UBuffDataType* buffData, bool isReloadBuff = false);

	/*���س���Ч��*/
	virtual void removeHoldEffect(CS3Entity* receiver, UBuffDataType* buffData);

	/*����*/
	virtual	void doStack(CS3Entity* receiver, UBuffDataType* buffData);

protected:
	int32 maxStackLayer = 1;
};

