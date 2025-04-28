// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Scene/MovingPlatformCharacter.h"
#include "Component/CS3CameraComponent.h"
#include "MovingPlatformShipsCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API AMovingPlatformShipsCharacter : public AMovingPlatformCharacter
{
	GENERATED_BODY()
public:
	AMovingPlatformShipsCharacter();///<���캯��
	virtual void BeginPlay()override;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponentEX* SpringArmCompent;///<��ͷҡ��

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCS3CameraComponent* CameraComponent;///<��ͷ���
};
