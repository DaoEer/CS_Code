#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"
/*
* �ļ����ƣ�MonsterExtRotat.h
* ����˵����
* �ļ����ߣ�lintongbin
* Ŀǰά����lintongbin
* ����ʱ�䣺2020-1-13
*/

/**
* ��ת����
*/
class CHUANGSHI_API MonsterExtRHB : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtRHB();
	~MonsterExtRHB();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
