#pragma once
#include "CoreMinimal.h"
#include "GameData/Skill/SkillTableData.h"
#include "Skill/SkillBase/Skill.h"
#include "Skill/Effect/EffectSkillBase.h"
#include "EffectLoader.generated.h"

/*
* �ļ����ƣ�EffectLoader.h
* ����˵����Ч��ʵ�������ļ�
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-10-29
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UEffectLoader :public UCS3Object
{
	GENERATED_BODY()
public:
	~UEffectLoader();
	/*���/��������*/
	static UEffectLoader* GetInstance();

	UEffectSkillBase* createEffect(FHIT_EFFECT effectData, USkill* skill);

	UHoldEffect* createHoldEffect(FHOLD_EFFECT effectData, USkill* skill);


private:
	UEffectLoader();

};

