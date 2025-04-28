// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Particle/EffectEmitter.h"
#include "NavigationEmitter.generated.h"

class USplineComponent;
/*
* �ļ����ƣ�NavigationEmitter.h
* ����˵����
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-09-26
*/
/**
 * 
 */
UCLASS(abstract)
class CHUANGSHI_API ANavigationEmitter : public AEffectEmitter
{
	GENERATED_BODY()

public:
	ANavigationEmitter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:

	// ��ʼ���������ӹ켣
	void InitNavigationTrace();

	// �������
	void CalculateScale();

	// �����ٶ�
	void UpdateMoveSpeed(float DeltaSeconds);

private:

	// �������ܾ���������߹켣�ܾ���ı���
	float Scale;

	// ��ǰ����(��)
	float Distance;

	// ����������������빫��
	float OtherDistance;

	// ������
	TArray<FVector> NavLocationList;

	// �Ƿ��������ٶ�
	bool bNormalSpeed = false;

	// �Ƿ���������
	bool bSpiralRising = false;

	// �����תƵ��
	int RandFrequency = 5;

	// �����ת��ʱ��
	float RandTime = 0.0f;

	// ��ת�ٶ�
	float SpiralSpeed = 100.f;

	// �����������ٶ��£������ǰ���ľ���
	float ForwardDiatance;

	// ��������������
	float AdjustScale = 0.f;

	// ���ڼ���״̬
	bool bSpeedUp = false;

public:
	///�����켣
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USplineComponent* NavigationTrace;

	///�����켣
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USplineComponent* SpiralTrace;

	///�����켣
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USplineComponent* RisingTrace;
};
