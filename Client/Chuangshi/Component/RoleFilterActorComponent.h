#pragma once
#include "AvatarFilterActorComponent.h"
#include "RoleFilterActorComponent.generated.h"

/*
* �ļ����ƣ�RoleFilterActorComponent.h
* ����˵����
* �ļ����ߣ�hezhiming
* Ŀǰά����huting
* ����ʱ�䣺2017-07-20
*/
UCLASS(BlueprintType)
class CHUANGSHI_API URoleFilterActorComponent : public UAvatarFilterActorComponent
{
	GENERATED_BODY()
		typedef UAvatarFilterActorComponent Supper;
public:
	//virtual void OnUpdateVolatileDataByParent(const FVector& position, const FVector& direction, int32 parentID) override;
	virtual void Pos(const int32 vehicleID, const FVector& position, const FVector& direction, const FVector& velocity) override;
};

