#pragma once
#include "KBEngine.h"
#include "Entity/NPC/NPC.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�NPCExtMove.h
* ����˵����
* �ļ����ߣ�gaoruilian
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-09-27
*/

class NPCExtMove : public NPC
{
	typedef NPC Supper;
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
public:
	NPCExtMove();
	~NPCExtMove();


protected:

	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};