#pragma once
#include "KBEngine.h"
#include "Entity/NPC/NPC.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�NPCTorture.h
* ����˵�������ʸ�������NPC
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-07-16
*/

class NPCTorture : public NPC
{
	KBE_DECLARE_ENTITY_MAP();

	typedef NPC Supper;
	DEF_INTERFACE_CONTENT()
public:
	NPCTorture();
	~NPCTorture();


protected:

	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};