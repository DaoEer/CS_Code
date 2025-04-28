// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "KBEngine.h"
#include "../FilterActorComponent.h"
#include "GameData/PlayerControllerData.h"
#include "Actor/ServerCharacter.h"
#include "AIController.h"
#include "Util/MoveScripts/MoveScriptBase.h"
#include "CMonsterPosSyncComponent.generated.h"

/*
* �ļ����ƣ�CMonsterPosSyncComponent.h
* ����˵�����ͻ��˹���λ��ͬ���������Ҫ�����������ͬ�����ﵱǰ�ƶ�λ�ã�
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2019-11-8
*/


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CHUANGSHI_API UCMonsterPosSyncComponent : public UFilterActorComponent
{
	GENERATED_BODY()

public:
	UCMonsterPosSyncComponent();
	~UCMonsterPosSyncComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	KBEngine::Entity* GetMEntity();

public:
	void ResetMoveScript();
	void StartRandomWalk(FVector OriginalPos, float RandomRange, float AcceptanceRadius = 50.0f);
	void ChaseActor(AActor* GoalActor, float AcceptanceRadius = 50.0f);
	void OnMoveOver();

private:
	MoveScriptBase* MoveScriptBasePtr;
};



