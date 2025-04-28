// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Particles/Emitter.h"
#include "SequencerEmitter.generated.h"

/*
* �ļ����ƣ�SequencerEmitter.h
* ����˵����
* �ļ����ߣ�jiangyupeng
* Ŀǰά����zhangfudong
* ����ʱ�䣺2017-10-27
*/
UCLASS(BlueprintType)
class CHUANGSHI_API ASequencerEmitter : public AEmitter
{
	GENERATED_BODY()
	
public:	
	
	UFUNCTION(BlueprintCallable, Category = "CustomParticle")
	void SetWarmupTime(float Value);

protected:
	// ������ʱ��
	float DeltaTime;
	
};
