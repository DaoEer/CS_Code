// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"
/*
* �ļ����ƣ�MonsterExtShareHP.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2017-09-13
*/

/**
* Ѫ�������
*/
class CHUANGSHI_API MonsterExtShareHP : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtShareHP();
	~MonsterExtShareHP();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};