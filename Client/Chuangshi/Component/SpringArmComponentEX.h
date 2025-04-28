// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "SpringArmComponentEX.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = Camera, meta = (BlueprintSpawnableComponent), hideCategories = (Mobility))
class CHUANGSHI_API USpringArmComponentEX : public USpringArmComponent
{
	GENERATED_BODY()
	
protected:

	// �����˫����ײ
	/** Updates the desired arm location, calling BlendLocations to do the actual blending if a trace is done */
	void UpdateDesiredArmLocation(bool bDoTrace, bool bDoLocationLag, bool bDoRotationLag, float DeltaTime) override;
};
