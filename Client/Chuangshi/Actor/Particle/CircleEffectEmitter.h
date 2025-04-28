// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Particle/EffectEmitter.h"
#include "DelegateCombinations.h"
#include "CircleEffectEmitter.generated.h"

/*
* �ļ����ƣ�CircleEffectEmitter.h
* ����˵���������λ������ӵ�Ч�������ƵĻ����������Ŷ����������
* �ļ����ߣ�liyuxia
* Ŀǰά����liyuxia
* ����ʱ�䣺2020-5-21
*/

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCircleEffectOnStopMove);

UCLASS()
class CHUANGSHI_API ACircleEffectEmitter : public AEffectEmitter
{
	GENERATED_BODY()

public:
	ACircleEffectEmitter();
	
	//virtual void Tick(float DeltaSeconds) override;
	///��ʼ������
	virtual void InitFromConfig();
	void SetCircleEffectParameter(bool InIsMove, float InStartSpawnNum, float InStartRadius, float InTotalTime, float InIntervalTime);
private:
	void Move();
	void StopMove();
public:
	///��Чֹͣ�˶�֪ͨ
	UPROPERTY(BlueprintAssignable)
		FCircleEffectOnStopMove OnCircleEffectStopMove;
private:
	float StartSpawnNum;
	float StartRadius;
	float TotalTime;
	float IntervalTime;
	float Radius;
	FTimerHandle timerHandle;
};
