#pragma once
#include "BaseAnimInstance.h"
#include "EffectAnimInstance.generated.h"

/*
* �ļ����ƣ�EffectAnimInstance.h
* ����˵����
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2017-08-04
*/
UCLASS(Blueprintable, hideCategories = EffectAnimInstance, BlueprintType, meta = (BlueprintThreadSafe), Within = SkeletalMeshComponent)
class CHUANGSHI_API UEffectAnimInstance : public UBaseAnimInstance
{
	GENERATED_BODY()
public:
	UEffectAnimInstance();
	~UEffectAnimInstance();

protected:

private:

};

