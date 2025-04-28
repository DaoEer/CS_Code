// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Particle/FlyEffectEmitter.h"
#include "IceBirdEffectEmitter.generated.h"

/*
* �ļ����ƣ�IceBirdEffectEmitter.h
* ����˵����
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-10-27
*/

UCLASS(abstract)
class CHUANGSHI_API AIceBirdEffectEmitter : public AFlyEffectEmitter
{
	GENERATED_BODY()

protected:

	/*Begin AEffectEmitter Interface*/

	///��ʼ������
	virtual void InitFromConfig();

	/*End AEffectEmitter Interface*/

	/*Begin AFlyEffectEmitter Interface*/

	///��д�ڶ��׶��ƶ�
	virtual void SecondMove(float DeltaTime) override;

	///��õڶ��׶��˶��ĽǶ�
	virtual void GetSecondMoveRotation(FRotator& OutRotation) override;

	///׼��������һ�׶ν׶�
	virtual void EnterNextMove() override;

	/*End AFlyEffectEmitter Interface*/
};
