// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/NPC/NPCTrainSoldierGround.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�NPCSeniorTrainSoldierGround.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-05-15
*/

/**
* �߼�������
*/
class CHUANGSHI_API NPCSeniorTrainSoldierGround : public NPCTrainSoldierGround
{
	KBE_DECLARE_ENTITY_MAP();

	typedef NPCTrainSoldierGround Supper;
	DEF_INTERFACE_CONTENT()
public:
	NPCSeniorTrainSoldierGround();
	~NPCSeniorTrainSoldierGround();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};