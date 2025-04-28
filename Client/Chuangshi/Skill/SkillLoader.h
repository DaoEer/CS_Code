#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "Skill/SkillBase/Skill.h"
#include "SkillLoader.generated.h"

/*
* �ļ����ƣ�SkillLoader.h
* ����˵��������ʵ�������ļ�
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

UCLASS(BlueprintType)
class CHUANGSHI_API USkillLoader :public UCS3Object
{
	GENERATED_BODY()
public:
	~USkillLoader();
	/*���/��������*/
	static USkillLoader* GetInstance();

	void loadAllSkill();
	USkill* CreateSkill(FString SkillID, const FSKILL_TABLE_DATA* SkillData);
	USkill* getSkillByID(int32 SkillID);
	
private:
	USkillLoader();


private:
	UPROPERTY()
	TMap<int32, USkill*> _skills;

};

