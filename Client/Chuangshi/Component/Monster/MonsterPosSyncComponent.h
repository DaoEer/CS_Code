// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "KBEngine.h"
#include "../FilterActorComponent.h"
#include "GameData/PlayerControllerData.h"
#include "MonsterPosSyncComponent.generated.h"


UENUM(BlueprintType)
enum class MONSTER_MOVE_TYPE : uint8
{
	None = 0,    ///<���ƶ�
	Wander = 1,	///<�ε�
	Chase = 2,	///<׷��
	HitBack = 3,///<�����ƶ�
	GoBack = 4, ///<����
};
/*
* �ļ����ƣ�MonsterPosSyncComponent.h
* ����˵��������ͬ���ƶ�λ���������Ҫ�����������ͬ�����ﵱǰ�ƶ�λ�ã�
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-1-19
*/

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CHUANGSHI_API UMonsterPosSyncComponent : public UFilterActorComponent
{
	GENERATED_BODY()

public:
	UMonsterPosSyncComponent();
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

};
