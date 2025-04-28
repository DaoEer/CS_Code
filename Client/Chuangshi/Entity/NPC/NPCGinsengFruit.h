// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/NPC/NPC.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�NPCGinsengFruit.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2017-09-27
*/

/**
* �������JIRA��CST-2150 �˲ι�
* �����ѷ���
*/
class CHUANGSHI_API NPCGinsengFruit : public NPC
{
	KBE_DECLARE_ENTITY_MAP();

	typedef NPC Supper;
	DEF_INTERFACE_CONTENT()
public:
	NPCGinsengFruit();
	~NPCGinsengFruit();
	
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};