// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtSGMZ.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-09-18
*/

/**
* �Ϲ�����BOSS
*/
class CHUANGSHI_API MonsterExtSGMZ : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtSGMZ();
	~MonsterExtSGMZ();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};