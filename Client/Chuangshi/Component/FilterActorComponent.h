// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/ActorComponent.h"
#include "KBEngine.h"
#include "FilterActorComponent.generated.h"

/*
* �ļ����ƣ�FilterActorComponent.h
* ����˵����
* �ļ����ߣ�liushuang
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2016-08-29
*/

//class UAvatarActorComponent;

DECLARE_STATS_GROUP(TEXT("CS3EntityActorSynchLocation"), STATGROUP_CS3EntityActorSynchLocation, STATCAT_Advanced);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CHUANGSHI_API UFilterActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFilterActorComponent();
	//~ Begin UActorComponent Interface.
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//~ End UActorComponent Interface.

	virtual void OnUpdateVolatileData(const FVector& position, const FVector& direction, int32 parentID) { }
	virtual void OnUpdateVolatileDataByParent(const FVector& position, const FVector& direction, int32 parentID) { }
	virtual void SetPosition(const FVector& position, int32 parentID) { }
	virtual void SetDirection(const FVector& direction, int32 parentID) { }
	virtual void InitFilter(bool IsActiveTickEnabled = true);
	virtual void OnGotParentEntity(KBEngine::Entity* parentEnt) { }
	virtual void OnLoseParentEntity() { }

	void SetActiveComponentTick(bool bNewActive);
	bool GetPositionAndDirection(const FVector& position, const FVector& direction, int32 parentID, FVector& OutPosition, FVector& OutDirection);
protected:
	virtual void SimulateMovement(float DeltaTime) { }
	virtual void SpeedChangedNotify(float speed) { }
	bool SafeMove(const FVector& position, const FVector& direction, bool bCheckGround = false);

private:
	bool bEnableEntityServerPos = true;///<�Ƿ���λ��ͬ��(����ָ̨���õ�)
};
