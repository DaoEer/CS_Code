#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtShowTopCountDown.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-4-23
*/

/**
* ͷ����ʾ����ʱ��
*/
class CHUANGSHI_API MonsterExtShowTopCountDown : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtShowTopCountDown();
	~MonsterExtShowTopCountDown();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
