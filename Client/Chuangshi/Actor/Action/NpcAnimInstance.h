#pragma once
#include "BaseAnimInstance.h"
#include "NpcAnimInstance.generated.h"
/*
* �ļ����ƣ�NpcAnimInstance.h
* ����˵����
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2017-02-23
*/
UCLASS(Blueprintable, hideCategories = NpcAnimInstance, BlueprintType, meta = (BlueprintThreadSafe), Within = SkeletalMeshComponent)
class CHUANGSHI_API UNpcAnimInstance : public UBaseAnimInstance
{
	GENERATED_BODY()
public:
	UNpcAnimInstance();
	~UNpcAnimInstance();
protected:
	virtual bool IsInWater()override;
private:

};

