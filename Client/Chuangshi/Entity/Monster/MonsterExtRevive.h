#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"
/*
* �ļ����ƣ�MonsterExtRevive.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-03-22
*/

/**
*����֣���һ��ʱ���ڿ��ܻḴ��
*/
class MonsterExtRevive : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtRevive();
	~MonsterExtRevive();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

