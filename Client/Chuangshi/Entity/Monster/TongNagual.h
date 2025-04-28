// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"
/*
* �ļ����ƣ�TongNagual.h
* ����˵����
* �ļ����ߣ�chengdongyong
* Ŀǰά����chengdongyong
* ����ʱ�䣺2018-03-16
*/

/**
*  �������
*/
class CHUANGSHI_API TongNagual : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	TongNagual();
	~TongNagual();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
