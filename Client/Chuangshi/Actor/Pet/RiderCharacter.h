#pragma once

#include "Actor/GameCharacter.h"
#include "RiderCharacter.generated.h"

/*
* �ļ����ƣ�RiderCharacter.h
* ����˵����
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2017-08-15
*/

/**
 * ��ʿ����
 */
UCLASS(BlueprintType)
class CHUANGSHI_API ARiderCharacter : public AGameCharacter
{
	GENERATED_BODY()
public:
	ARiderCharacter();
	virtual void OnCreateModelOver() override;
	virtual void BeginPlay()override;

	virtual void SetInitAction() override;///<��дSetInitAction
	void ApplayModelByPartsMap(TMap<MODEL_PART_TYPE, FString>& NewPartMap);
	void ChangeActorPart(MODEL_PART_TYPE pos, FString PartID);
	void UseRideAnimData(TSoftClassPtr<UAnimInstance> AnimationPath, TSoftObjectPtr<UDataTable> ActionConfigPath);
	void SetModelData(TSharedPtr<FMODEL_DATA> ModelData);
	void SetPlayerCharacter(AGameCharacter* InPlayerCharacter);

protected:
	virtual void InitBaseComponent() override;

	void OnNotifyActionChangeFinish(FACTION_DATA ActionData);

	UPROPERTY()
		AGameCharacter* GameCharacter;//���
};
