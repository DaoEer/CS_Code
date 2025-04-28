// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "WindComponent.generated.h"

/*
* �ļ����ƣ�WindComponent.h
* ����˵����
* �ļ����ߣ�yanghan
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-09-23
*/

UCLASS(BlueprintType)
class CHUANGSHI_API AWindComponent : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWindComponent();

/**
*��ʼ����
*
*@param _WindSpeed ����
*@param _WindDirection ��ķ���
*
*@return ��
*/
void BeginWind(float _WindSpeed,FVector _WindDirection);
void StopWind();

public:
	UPROPERTY()
	class UCapsuleComponent* CapsuleComponent;

protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool IsWindCanMove;
	float WindSpeed;
	FVector WindDirection;
	
};
