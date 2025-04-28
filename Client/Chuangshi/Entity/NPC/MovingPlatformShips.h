// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/NPC/MovingPlatform.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MovingPlatformShips.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-10-08
*/

/**
* ���۶ɽ� -- �ƶ�ƽ̨
*/
class CHUANGSHI_API MovingPlatformShips : public MovingPlatform
{
	KBE_DECLARE_ENTITY_MAP();

	typedef MovingPlatform Supper;
	DEF_INTERFACE_CONTENT()
public:
	MovingPlatformShips();
	~MovingPlatformShips();


protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��


};