#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtCanPush.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2019-10-08
*/

/**
* ���ƶ�����
*/
class CHUANGSHI_API MonsterExtCanPush : public Monster
{

	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtCanPush();
	 ~MonsterExtCanPush();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
