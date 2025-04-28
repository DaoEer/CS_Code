// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/NPC/MovingPlatform.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MovingPlatformTrigger.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2018-01-18
*/

/**
* �ƶ�ƽ̨
*/
class CHUANGSHI_API MovingPlatformTrigger : public MovingPlatform
{
	KBE_DECLARE_ENTITY_MAP();

	typedef MovingPlatform Supper;
	DEF_INTERFACE_CONTENT()
public:
	MovingPlatformTrigger();
	~MovingPlatformTrigger();


protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��


};