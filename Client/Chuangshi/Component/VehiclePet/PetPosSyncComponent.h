// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "KBEngine.h"
#include "Components/ActorComponent.h"
#include "PetPosSyncComponent.generated.h"

/*
* �ļ����ƣ�PetPosSyncComponent.h
* ����˵��������ͬ���ƶ�λ���������Ҫ�����������ͬ�����ǵ�ǰ�ƶ�λ�ã�
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-12-17
*/

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CHUANGSHI_API UPetPosSyncComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPetPosSyncComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	KBEngine::Entity* GetMEntity();
	float OldBlendMoveDirection;

};
