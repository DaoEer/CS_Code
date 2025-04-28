
#pragma once

#include "KBEngine.h"
#include "Entity/NPC/NPC.h"


/*
* �ļ����ƣ�NPCExtCaveHouse.h
* ����˵�����ֻ��ؾ�����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2020-03-19
*/

/**
* �������JIRA��CST-5774
*/

class CHUANGSHI_API NPCExtCaveHouse :public NPC
{
	KBE_DECLARE_ENTITY_MAP();

	typedef NPC Supper;

	DEF_INTERFACE_CONTENT()
public:
	NPCExtCaveHouse();
	~NPCExtCaveHouse();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
