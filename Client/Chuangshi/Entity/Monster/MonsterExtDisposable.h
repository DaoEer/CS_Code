#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtDisposable.h
* ����˵����һ���Ե���ӹ���
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2020-11-10
*/

class CHUANGSHI_API MonsterExtDisposable : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtDisposable();
	~MonsterExtDisposable();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
