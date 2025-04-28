// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MoveScriptBase.h"


/*
* �ļ����ƣ�MoveScriptRandomWalk.h
* ����˵�����ͻ��˹�������ƶ��� ����ƶ�
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2019-11-9
*/

class MoveScriptRandomWalk : public MoveScriptBase {
	typedef MoveScriptBase Super;
public:
	MoveScriptRandomWalk(APawn* InPawn, FVector _OriginalPos, float _RandomRange, float _AcceptanceRadius);
	virtual void DoMove() override;
	virtual void OnMoveOver() override;
	virtual void MoveReachCheck() override;
	FVector GetGoalPos();

private:
	FVector OriginalPos;
	FVector GoalPos;
	float RandomRange;
	
};