// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterBuilding.h
* ����˵����
* �ļ����ߣ�chenweilan
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-07-13
*/

/**
* �ƶ�ƽ̨
*/
class CHUANGSHI_API MonsterBuilding : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterBuilding();
	~MonsterBuilding();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};