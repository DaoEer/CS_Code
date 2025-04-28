#pragma once

#include "KBEngine.h"
#include "Entity/Trap/Trap.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MoveTrapByTrigger.h
* ����˵����
* �ļ����ߣ�zhutianyang
* Ŀǰά����zhutianyang
* ����ʱ�䣺2017-10-17
*/

/**
�ƶ�������
*/
class MoveTrapByTrigger : public Trap
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Trap Supper;
	DEF_INTERFACE_CONTENT()
public:
	MoveTrapByTrigger();
	~MoveTrapByTrigger();


public:

	virtual UClass* GetEntityModelClassAsset() override;
};
