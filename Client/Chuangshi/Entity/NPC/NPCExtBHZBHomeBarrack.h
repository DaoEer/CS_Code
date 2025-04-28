// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/NPC/NPC.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�NPCExtBHZBHomeBarrack.h
* ����˵����������Դ�Ӫ
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-07-30
*/

/**
* ������Դ�Ӫ
*/
class CHUANGSHI_API NPCExtBHZBHomeBarrack : public NPC
{
	KBE_DECLARE_ENTITY_MAP();

	typedef NPC Supper;
	DEF_INTERFACE_CONTENT()
public:
	NPCExtBHZBHomeBarrack();
	~NPCExtBHZBHomeBarrack();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};