// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "FilterActorComponent.h"
#include "PhysicsFilterActorComponent.generated.h"

/*
* �ļ����ƣ�PhysicsFilterActorComponent.h
* ����˵����
* �ļ����ߣ�wangzheng
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-03-16
*/

/**
* һ���Զ���ı�λ�õĹ�����������ģ��ս���ܻ�����(���������ƵĹ���ģ�����)
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UPhysicsFilterActorComponent : public UFilterActorComponent
{
	GENERATED_BODY()
		typedef UFilterActorComponent Supper;

public:
	UPhysicsFilterActorComponent();

	virtual void SimulateMovement(float DeltaTime) override;
	void InitData(const float& MoveSpeed, const FVector& DstPos);

	virtual void OnUpdateVolatileData(const FVector& position, const FVector& direction, int32 parentID) override;
private:
	float GetDestDistance();//��ȡ��Ŀ���ľ���
public:
	float Velocity;
	bool IsIgnoreServerPos;
	FVector DestPos;
};


/**
* �ͻ���ģ������������ƶ�Filter(���ͻ����ƶ�)
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UCurveFilterActorComponent : public UFilterActorComponent
{
	GENERATED_BODY()
		typedef UFilterActorComponent Supper;
public:
	UCurveFilterActorComponent();

	virtual void SimulateMovement(float DeltaTime) override;
	virtual void SetDirection(const FVector& direction, int32 parentID) override;

	//�ƶ��������
	void InitData(float Gravity, float UpTime, float XSpeed, FVector DstPos);
	void ClearMoveData();

private:
	float ZUpTime;//����ʱ��
	float ZGravity;//�������ٶ�
	float MoveTime;//�ƶ�ʱ��
	float NeedTime;//�ƶ���ʱ��
	FVector XMoveDir;//ƽ���ƶ�����
	FVector DstPosition;//�ƶ�Ŀ���
	FVector DstDirection;//Ŀ�곯��

};

/**
* ���ͻ��ˣ�����ģ����˱���
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UHitBackMoveFilterActorComponent : public UFilterActorComponent
{
	GENERATED_BODY()
		typedef UFilterActorComponent Supper;

public:
	UHitBackMoveFilterActorComponent();

	virtual void SimulateMovement(float DeltaTime) override;
	virtual void SetDirection(const FVector& direction, int32 parentID) override;

	void InitData(float InMoveSpeed, const FVector& InDestination, const FVector& InStartPos, const FVector& InDestPos);

	float Velocity;			//�ٶ�
	FVector DestPos;		//Ŀ��λ�� 
	FVector Destination; 	//���˵ľ���
	FVector StartPos;      	//���˵���ʼλ�ã�������λ��
private:
	FQuat Dir;
};