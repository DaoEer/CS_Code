// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Component/Role/ForceComponent.h"
#include "OtherDirForceComponent.generated.h"

/*
* �ļ����ƣ�OtherDirForceComponent.h
* ����˵����
* �ļ����ߣ�yanghan
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-12-07
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UOtherDirForceComponent : public UForceComponent
{
	GENERATED_BODY()
public:
	UOtherDirForceComponent():OtherCharacter(nullptr){}

	//����������Ŀ��
	void SetOtherCharacter(ACharacter* OtherActor);

protected:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	UPROPERTY()
	class ACharacter* OtherCharacter;
	
	
};
