// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Actor/NPCBaseCharacter.h"
#include "GhostReceiverCharacter.generated.h"

/*
* �ļ����ƣ�GhostReceiverCharacter.h
* ����˵����
* �ļ����ߣ�chengdongyong
* Ŀǰά����chengdongyong
* ����ʱ�䣺2017-08-10
*/
UCLASS(BlueprintType)
class CHUANGSHI_API AGhostReceiverCharacter : public ANPCBaseCharacter
{
	GENERATED_BODY()
	
public:
	AGhostReceiverCharacter();
	
protected:
	virtual void InitBaseComponent() override;///<��дInitBaseComponent
	
};
