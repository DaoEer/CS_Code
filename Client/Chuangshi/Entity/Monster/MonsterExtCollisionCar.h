// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/MonsterExtAttackCityLadder.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtCollisionCar.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-3-8
*/

/**
*  ײ��
*/
class CHUANGSHI_API MonsterExtCollisionCar : public MonsterExtAttackCityLadder
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef MonsterExtAttackCityLadder Supper;
public:
	MonsterExtCollisionCar();
	~MonsterExtCollisionCar();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
