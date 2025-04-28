// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/NPC/NPC.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�NPCTrainSoldierGround.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-04-16
*/

/**
* ������
*/
class CHUANGSHI_API NPCTrainSoldierGround : public NPC
{
	KBE_DECLARE_ENTITY_MAP();

	typedef NPC Supper;
	DEF_INTERFACE_CONTENT()
public:
	NPCTrainSoldierGround();
	~NPCTrainSoldierGround();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};