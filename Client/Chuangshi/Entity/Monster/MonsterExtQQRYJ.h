// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtQQRYJ.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-08-26
*/

/**
* ��ȡ���Ҿ� ---����ƶ���
*/
class CHUANGSHI_API MonsterExtQQRYJ : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtQQRYJ();
	~MonsterExtQQRYJ();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};