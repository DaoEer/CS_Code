// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Particle/FlyEffectEmitter.h"
#include "SpiralEffectEmitter.generated.h"

/*
* �ļ����ƣ�SpiralEffectEmitter.h
* ����˵����
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-04-08
*/

DECLARE_STATS_GROUP(TEXT("ASpiralEffectEmitter"), STATGROUP_ASpiralEffectEmitter, STATCAT_Advanced);

UCLASS(abstract)
class CHUANGSHI_API ASpiralEffectEmitter : public AFlyEffectEmitter
{
	GENERATED_BODY()
	
private:

	//����
	float Rate;

	//�������X
	float RelPosX;

	//�������Y
	float RelPosY;

	//�������Z
	float RelPosZ;

	//����
	float Distance;

	//���Ŀ��Z�Ƕ�
	float RelRotZ;

	//���Ŀ��XY�Ƕ�
	float RelRotXY;

	//ƫ���ٶ�Z
	float SpeedZ;

	//��ǰƫ��Z
	float CurAngleZ;

	//��ʼ����XY
	float BeginAngleXY;

	//��������XY
	float EndAngleXY;

	//�����ٶ�XY
	float SpeedXY;

	//��ǰ����XY
	float CurAngleXY;

	//��ʼ�뾶
	float BeginRadius = 0.0f;

	//�����뾶
	float EndRadius;

	//�����ٶ�
	float RadiusSpeed;

	//��ǰ�뾶
	float CurrentRadius;

	//���ƫ��
	FVector RelOffset;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	
	///��ʼ��λ��
	virtual void InitEmitterTransform() override;
	
private:
	///׼������
	UFUNCTION(BlueprintCallable, Category = "SpiralEffect")
	void PrepareTheData(float DeltaTime);
	
	///����ʱ��
	void UpdateTime(float DeltaTime);

	///�����������ͽǶ��Լ�����
	void UpdateRelInfo();

	//�����˶�����
	UFUNCTION(BlueprintCallable, Category = "SpiralEffect")
	void Calculation();

	//����λ�����
	void CalculationAngle();

	//����뾶���
	void CalculationRadius();

	//����λ�����
	FVector CalculationPosition();

	//������ת���
	FRotator CalculationRotation();
};
