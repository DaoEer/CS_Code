// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BaseAnimInstance.h"
#include "PerformerAnimInstance.generated.h"

/*
* �ļ����ƣ�PerformerAnimInstance.h
* ����˵����
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2018-06-21
*/
UCLASS(Blueprintable, hideCategories = PerformerAnimInstance, BlueprintType, meta = (BlueprintThreadSafe), Within = SkeletalMeshComponent)
class CHUANGSHI_API UPerformerAnimInstance : public UBaseAnimInstance
{
	GENERATED_BODY()
public:
	UPerformerAnimInstance();
	~UPerformerAnimInstance();
protected:
private:
	
	
	
};
