#pragma once

#include "KBEngine.h"
#include "Entity/Trap/TrapBattleFlag.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�TrapBarracks.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-02-28
*/

/**
��Ӫ
*/
class TrapBarracks : public TrapBattleFlag
{
	KBE_DECLARE_ENTITY_MAP();

	typedef TrapBattleFlag Supper;
	DEF_INTERFACE_CONTENT()
public:
	TrapBarracks();
	~TrapBarracks();
public:
	virtual UClass* GetEntityModelClassAsset() override;

};
