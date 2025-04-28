// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"
/*
* �ļ����ƣ�MonsterExtInteractive.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-05-10
*/

/**
* �ɵ������
*/
class CHUANGSHI_API MonsterExtInteractive : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtInteractive();
	~MonsterExtInteractive();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};