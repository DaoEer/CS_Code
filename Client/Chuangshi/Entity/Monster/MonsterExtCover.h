// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtCover.h
* ����˵����
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020-5-14
*/

/**
*  �ֻ��ؾ������� ����
*/
class CHUANGSHI_API MonsterExtCover : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtCover();
	~MonsterExtCover();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
