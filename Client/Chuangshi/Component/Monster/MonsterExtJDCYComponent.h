// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "KBEngine.h"
#include "../FilterActorComponent.h"
#include "Component/Monster/MonsterPosSyncComponent.h"
#include "GameData/PlayerControllerData.h"
#include "MonsterExtJDCYComponent.generated.h"


/*
* �ļ����ƣ�MonsterExtJDCYComponent.h
* ����˵�������ز�ҩ����ͬ���ƶ�λ���������Ҫ�����������ͬ�����ﵱǰ�ƶ�λ�ã�
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2020-8-5
*/


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CHUANGSHI_API UMonsterExtJDCYComponent : public UFilterActorComponent
{
	GENERATED_BODY()

public:
	UMonsterExtJDCYComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	MONSTER_MOVE_TYPE GetCurMonsterMoveType();
	MONSTER_MOVE_TYPE GetLastMonsterMoveType();
	void SetMonsterMoveType(MONSTER_MOVE_TYPE MonsterMoveType);
	/*׷��*/
	void ChaseTarget();

	/*����*/
	void AttackTarget();

	/*�������Ŀ��*/
	int32 GetTargetID();

	/*�ε�*/
	void StartWander();
	/*�����ƶ�*/
	void BeHitBack();

	/*����*/
	void GoBack();

private:
	bool bEnableTick = false;
	void TraceTargetActor(const AActor* TargetActor, float NearbyRange = 0.0f, FTraceCallback TraceCallback = FTraceCallback(), bool IsStopMove = true, FTraceCallback TraceStopMoveCallback = FTraceCallback());
	//���λ���ƶ�
	void WanderTargetPostion(const FVector& TargetPostion, float NearbyRange = 0.0f, FTraceCallback TraceCallback = FTraceCallback(), bool IsStopMove = true, FTraceCallback TraceStopMoveCallback = FTraceCallback());
	//����
	void BackTargetPostion(const FVector& TargetPostion, float NearbyRange = 0.0f, FTraceCallback TraceCallback = FTraceCallback(), bool IsStopMove = true, FTraceCallback TraceStopMoveCallback = FTraceCallback());
	//����׷������
	void ClearTraceData();
public:
	MONSTER_MOVE_TYPE LastMoveType = MONSTER_MOVE_TYPE::None;
	MONSTER_MOVE_TYPE CurrMoveType = MONSTER_MOVE_TYPE::None;
	///׷����Ϣ
	FTRACE_TARGET_INFO TraceTargetInfo;
private:
	KBEngine::Entity* GetMEntity();
	float OldBlendMoveDirection;
	FVector WanderPosition = FVector::ZeroVector;

};
