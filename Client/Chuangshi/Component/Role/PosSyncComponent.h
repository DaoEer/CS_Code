// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "KBEngine.h"
#include "Components/ActorComponent.h"
#include "PosSyncComponent.generated.h"

/*
* �ļ����ƣ�PosSyncComponent.h
* ����˵������ɫͬ���ƶ�λ���������Ҫ�����������ͬ�����ǵ�ǰ�ƶ�λ�ã�
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2016-12-06
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHUANGSHI_API UPosSyncComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPosSyncComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void setTickDoing(bool bDoing);

	FORCEINLINE void Init(int32 EntityID)
	{
		MEntityID = EntityID;
	}

private:
	KBEngine::Entity* GetMEntity();
	int32 MEntityID = 0;
	float OldBlendMoveDirection;
	
};
