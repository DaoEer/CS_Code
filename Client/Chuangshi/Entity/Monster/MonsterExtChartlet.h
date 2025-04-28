#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtChartlet.h
* ����˵����
* �ļ����ߣ�zhutianyang
* Ŀǰά����zhutianyang
* ����ʱ�䣺2018-03-20
*/

/**
* ������ͼ
*/
class CHUANGSHI_API MonsterExtChartlet :	public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtChartlet();
	~MonsterExtChartlet();

	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

