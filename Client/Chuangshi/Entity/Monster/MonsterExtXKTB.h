#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtXKTB.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2020-04-10
*/

/**
* ���̽��
*/
class CHUANGSHI_API MonsterExtXKTB : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtXKTB();
	~MonsterExtXKTB();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

