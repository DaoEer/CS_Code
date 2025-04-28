// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "KBEngine.h"
#include "../FilterActorComponent.h"
#include "GameData/PlayerControllerData.h"
#include "MonsterFollowComponent.generated.h"

UENUM(BlueprintType)
enum class MONSTER_FOLLOW_MOVE_TYPE : uint8
{
	None = 0,    ///<���ƶ�
	Moving = 1,	 ///<�ƶ�
	StopMove = 2,///�ƶ���Ŀ���ֹͣ
};

/**
* �ļ����ƣ�UMonsterFollowComponent.h
* ����˵���������������ƶ�λ�����
* �ļ����ߣ�qiurunan
* Ŀǰά����qiurunan
* ����ʱ�䣺2019-10-31
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CHUANGSHI_API UMonsterFollowComponent : public UFilterActorComponent
{
	GENERATED_BODY()
	
public:
	UMonsterFollowComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetMonsterMoveType(MONSTER_FOLLOW_MOVE_TYPE MonsterMoveType);

	void ClearTraceData();

	FVector GetMovePosition();

	void StartMoveTargetPostion();

	MONSTER_FOLLOW_MOVE_TYPE GetCurMonsterMoveType();

	///�ƶ���Ϣ
	void MoveTargetPostion(const FVector& TargetPostion, float NearbyRange = 0.0f, FTraceCallback TraceCallback = FTraceCallback(), bool IsStopMove = true, FTraceCallback TraceStopMoveCallback = FTraceCallback());

private:
	KBEngine::Entity* GetMEntity();

public:
	///׷����Ϣ
	FTRACE_TARGET_INFO TraceTargetInfo;

private:
	///��ǰ�ƶ�ģʽ
	MONSTER_FOLLOW_MOVE_TYPE CurrMoveType = MONSTER_FOLLOW_MOVE_TYPE::None;
	///����ϴ�����
	FVector RoleLastPosition;
	///Ŀ������
	FVector NextMovePosition;
};
