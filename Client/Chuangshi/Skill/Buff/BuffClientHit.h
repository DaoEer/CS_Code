#pragma once
#pragma once
#include "CoreMinimal.h"
#include "Skill/Buff/BuffClientHold.h"
#include "BuffClientHit.generated.h"


/*
* �ļ����ƣ�BuffClientHold.h
* ����˵�����ͻ��˴��buff
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-26
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UBuffClientHit :public UBuffClientHold
{
	GENERATED_BODY()
public:
	UBuffClientHit();
	~UBuffClientHit();

public:
	/*��ʼ��buff����*/
	virtual void init(FString BuffID, const FBUFF_TABLE_DATA* dictDat);

	/*��ô��*/
	virtual UBuffHitDefine* getHit(FString attrName, int32 index);

	/*��ʼ���*/
	virtual	void doBeginHit(CS3Entity* receiver, UBuffDataType* buffData);

	/*�������*/
	virtual	void doEndHit(CS3Entity* receiver, UBuffDataType* buffData);
protected:
	UPROPERTY()
	UBuffHitData* _beginHitList;
	UPROPERTY()
	UBuffHitData* _endHitList;
};

