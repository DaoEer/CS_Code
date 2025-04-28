// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtQuest.h
* ����˵����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2018-01-18
*/

/**
* �����
*/
class CHUANGSHI_API MonsterExtQuest : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtQuest();
	~MonsterExtQuest();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
