#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterLunHuiMiJin.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-12-24
*/

/**
* �Ϲ�����ƥ�����
*/
class CHUANGSHI_API MonsterLunHuiMiJin : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterLunHuiMiJin();
	~MonsterLunHuiMiJin();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

