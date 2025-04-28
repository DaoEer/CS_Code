// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Particle/EffectEmitter.h"
#include "ShelterEffectEmitter.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API AShelterEffectEmitter : public AEffectEmitter
{
	GENERATED_BODY()
public:
	///��д��������ײ�����������
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	///��д��������ײ�����������
	virtual void StartPlay() override;

	virtual void Tick(float DeltaSeconds);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ShelterRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ShelterBoundID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ShelterIsBound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector ShelterLoc;

	AEffectEmitter* ShelterEmitter;
private:

	ACharacter* Firsttarget;
	ACharacter* Sceondtarget;
};
