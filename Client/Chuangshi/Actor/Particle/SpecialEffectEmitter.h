// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Particle/FlyEffectEmitter.h"
#include "SpecialEffectEmitter.generated.h"

/*
* �ļ����ƣ�SpecialEffectEmitter.h
* ����˵����
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-03-09
*/

UCLASS(abstract)
class CHUANGSHI_API ASpecialEffectEmitter : public AFlyEffectEmitter
{
	GENERATED_BODY()

public:
	ASpecialEffectEmitter();

public:
	///��һ�׶�·��
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USplineComponent *FirstStageSpline;

	///�����׶�·��1
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USplineComponent *ThirdStageSplineOne;

	///�����׶�·��2
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USplineComponent *ThirdStageSplineTwo;

protected:
	///Ŀ��ͷ������ĸ߶�
	UPROPERTY(BlueprintReadOnly)
		float SourceHeight = 0.f;

	///��ʼ������ͷ���ľ���
	UPROPERTY(BlueprintReadOnly)
		float TargetHeight = 0.f;

	///�ɵ���ߵĸ߶����ߵľ���ռ��
	UPROPERTY(BlueprintReadOnly)
		float PercentOfRisingDistance = 0.35f;

	///�˶�����
	UPROPERTY(BlueprintReadOnly)
		float Distance = 1;

	///��һ�׶�����������ǰ�ľ���İٷֱ�
	UPROPERTY(BlueprintReadOnly)
		float ForwardDistance;

	///��ǰ�����׶�����
	UPROPERTY(BlueprintReadOnly)
		USplineComponent* CurrentThirdStageSpline = nullptr;

	///��һ��Ŀ���������λ��
	UPROPERTY(BlueprintReadOnly)
		FTransform FirstTargetTransform;

	///�ڶ���Ŀ���������λ��
	UPROPERTY(BlueprintReadOnly)
		FTransform SecondTargetTransform;
public:
	virtual void Tick(float DeltaTime) override;

protected:
	///��ʼ��λ��
	virtual void InitEmitterTransform() override;

	///������һ�׶�
	virtual void EnterNextMove() override;

private:
	/*�ڲ����ú���*/
	
	//���õ�һ�׶�����
	void SetFirstStageSpline();

	//���õ����׶�����
	void SetThirdStageSpline();

	//���ص��������ߵ�λ��
	const FVector GetThirdStageSplineLocation();

	//���õ��������ߵķ���
	void SetThirdStageSplineRotation();

	//��һ�׶��ƶ�
	void FirstStageMove(float DeltaTime);

	//�ڶ��׶��ƶ�
	void SecondStageMove(float DeltaTime);

	//�����׶��ƶ�
	void ThirdStageMove(float DeltaTime);
};
