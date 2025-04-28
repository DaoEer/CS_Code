// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MoveScriptBase.h"
#include "GameFramework/Actor.h"


/*
* �ļ����ƣ�MoveScriptChaseActor.h
* ����˵�����ͻ��˹�������ƶ��� ׷��Actor
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2019-11-9
*/

class MoveScriptChaseActor : public MoveScriptBase {
	typedef MoveScriptBase Super;

public:
	MoveScriptChaseActor(APawn* InPawn, AActor* _GoalActor, float _AcceptianRadius);
	virtual void DoMove() override;
	virtual void OnMoveOver() override;
	virtual void MoveReachCheck() override;
	AActor* GetGoalActor();
	FVector GetGoalPos();

private:
	AActor* GoalActor;
};