// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/NPC/MovingPlatformShade.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MovingPlatformRamp.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-05-30
*/

/**
* �ƶ�ƽ̨
*/
class CHUANGSHI_API MovingPlatformRamp : public MovingPlatformShade
{
	KBE_DECLARE_ENTITY_MAP();

	typedef MovingPlatformShade Supper;
	DEF_INTERFACE_CONTENT()
public:
	MovingPlatformRamp();
	~MovingPlatformRamp();


protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��


};