#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtImpact.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-09-19
*/

/**
*ײ������
*/
class MonsterExtImpact : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtImpact();
	~MonsterExtImpact();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};