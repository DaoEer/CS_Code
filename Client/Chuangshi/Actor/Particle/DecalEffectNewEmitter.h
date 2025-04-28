// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Particle/EffectEmitter.h"
#include "DecalEffectNewEmitter.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API ADecalEffectNewEmitter : public AEffectEmitter
{
	GENERATED_BODY()
	
public:
	///��д�����٣��£��������
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	///��д���������£��������
	virtual void StartPlay() override;

};
