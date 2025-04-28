// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"

/*
* �ļ����ƣ�MoveScriptBase.h
* ����˵�����ͻ��˹�������ƶ��� ����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2019-11-9
*/


class MoveScriptBase {
public:
	MoveScriptBase(APawn* InPawn, float _AcceptanceRaius);
	virtual ~MoveScriptBase() {};
	virtual void DoMove();
	virtual void MoveReachCheck();
	virtual void OnMoveOver();

	APawn* GetOwner();
	bool IsMoveOver();

protected:
	float AcceptanceRadius = 50.0;
	float MoveSpeed;
	bool bIsMoveOver = false;
private:
	APawn* Owner;
};

