// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterJuMa.h
* ����˵����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2020/3/24
*/

/**
* ����
*/
class CHUANGSHI_API MonsterJuMa : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterJuMa();
	~MonsterJuMa();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
