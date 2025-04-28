// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/MonsterExtBattery.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtBatteryRocket.h
* ����˵����
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020-2-19
*/

/**
*  ��̨
*/
class CHUANGSHI_API MonsterExtBatteryRocket : public MonsterExtBattery
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef MonsterExtBattery Supper;
public:
	MonsterExtBatteryRocket();
	~MonsterExtBatteryRocket();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
