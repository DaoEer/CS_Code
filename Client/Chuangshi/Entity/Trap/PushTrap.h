#pragma once

#include "KBEngine.h"
#include "Entity/Trap/Trap.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�PushTrap.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-10-25
*/

/**
����������
*/
class PushTrap : public Trap
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Trap Supper;
	DEF_INTERFACE_CONTENT()
public:
	PushTrap();
	~PushTrap();

public:
	virtual UClass* GetEntityModelClassAsset() override;

};
