// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/NPC/MovingPlatform.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MovingPlatformShade.h
* ����˵����
* �ļ����ߣ�chengdongyong
* Ŀǰά����chengdongyong
* ����ʱ�䣺2018-02-06
*/

/**
* �ƶ�ƽ̨
*/
class CHUANGSHI_API MovingPlatformShade : public MovingPlatform
{
	KBE_DECLARE_ENTITY_MAP();

	typedef MovingPlatform Supper;
	DEF_INTERFACE_CONTENT()
public:
	MovingPlatformShade();
	~MovingPlatformShade();


protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��


};