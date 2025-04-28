// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/NPC/NPC.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�NPCExtPoint.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-05-20
*/

/**
* ������Ծݵ�
*/
class CHUANGSHI_API NPCExtPoint : public NPC
{
	KBE_DECLARE_ENTITY_MAP();

	typedef NPC Supper;
	DEF_INTERFACE_CONTENT()
public:
	NPCExtPoint();
	~NPCExtPoint();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};