// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"


/*
* �ļ����ƣ�MonsterExtSFMJ.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-08-06
*/

/**
* ����ؾ� -- F����������
*/
class CHUANGSHI_API MonsterExtSFMJ : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtSFMJ();
	~MonsterExtSFMJ();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};