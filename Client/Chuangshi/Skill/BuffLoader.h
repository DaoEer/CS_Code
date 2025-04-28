#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "Skill/SkillBase/buff.h"
#include "BuffLoader.generated.h"


/*
* �ļ����ƣ�BuffLoader.h
* ����˵����buffʵ�������ļ�
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-20
*/

UCLASS(BlueprintType)
class UBuffLoader :public UCS3Object
{
	GENERATED_BODY()
public:
	~UBuffLoader();

public:
	/*���/��������*/
	static UBuffLoader* GetInstance();

	void loadAllBuff();

	UBuff* CreateBuff(FString BuffID, const FBUFF_TABLE_DATA * buffDat);

	UBuff* getBuffByID(int32 BuffID);

private:
	UBuffLoader();


private:
	UPROPERTY()
	TMap<int32, UBuff*> _buffs;
};


