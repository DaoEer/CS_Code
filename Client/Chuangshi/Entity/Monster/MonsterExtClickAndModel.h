// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtClickAndModel.h
* ����˵����
* �ļ����ߣ�chengdongyong
* Ŀǰά����chengdongyong
* ����ʱ�䣺2017-10-25
*/


/**
* �ɵ������
*/
class CHUANGSHI_API MonsterExtClickAndModel : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtClickAndModel();
	~MonsterExtClickAndModel();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};