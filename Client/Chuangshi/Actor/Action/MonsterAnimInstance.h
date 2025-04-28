#pragma once
#include "BaseAnimInstance.h"
#include "MonsterAnimInstance.generated.h"

/*
* �ļ����ƣ�MonsterAnimInstance.h
* ����˵����
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2017-02-23
*/
UCLASS(Blueprintable, hideCategories = MonsterAnimInstance, BlueprintType, meta = (BlueprintThreadSafe), Within = SkeletalMeshComponent)
class CHUANGSHI_API UMonsterAnimInstance : public UBaseAnimInstance
{
	GENERATED_BODY()
public:
	UMonsterAnimInstance();
	~UMonsterAnimInstance();
protected:
	virtual bool IsInWater()override;
	virtual void UpdateMoveDirection()override;
private:

};

