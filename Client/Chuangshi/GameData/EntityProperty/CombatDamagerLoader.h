#pragma once
#include "CoreMinimal.h"
#include "CombatDamager.h"
#include "GameData/CS3Object.h"
#include "CombatDamagerLoader.generated.h"

/*
* �ļ����ƣ�CombatDamagerLoader.h
* ����˵������׼�˺�ֵ
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2020-8-22

*/

USTRUCT(BlueprintType)
struct CHUANGSHI_API FCOMBAT_DAMAGER_DATA_PROFESSION
{
	GENERATED_BODY();
public:
	UPROPERTY()
		TMap<int32, FCOMBAT_DAMAGER_DATA> value;
};

UCLASS(BlueprintType)
class CHUANGSHI_API UCombatDamagerLoader :public UCS3Object
{
	GENERATED_BODY()
public:
	~UCombatDamagerLoader();
	/*���/��������*/
	static UCombatDamagerLoader* GetInstance();

	void loadAllData();

	FCOMBAT_DAMAGER_DATA GetCombatDamagerData(int32 Level, int32 Profession);

	
private:
	UCombatDamagerLoader();

	static UCombatDamagerLoader* Instance;
private:
	UPROPERTY()
	TMap<int32, FCOMBAT_DAMAGER_DATA_PROFESSION> CombatDamagerDataDic;

};

UCombatDamagerLoader* UCombatDamagerLoader::Instance = nullptr;