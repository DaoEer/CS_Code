#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtArmorLock.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-10-19
*/

class CHUANGSHI_API MonsterExtArmorLock : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtArmorLock();
	virtual ~MonsterExtArmorLock();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

