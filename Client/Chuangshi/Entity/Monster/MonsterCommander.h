// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/MonsterOptimize.h"

/*
* �ļ����ƣ�MonsterCommander.h
* ����˵����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2020-3-2
*/

/**
* ָ�ӹ�����С��
*/
class CHUANGSHI_API MonsterCommander : public MonsterOptimize
{
	KBE_DECLARE_ENTITY_MAP();

	typedef MonsterOptimize Supper;

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
