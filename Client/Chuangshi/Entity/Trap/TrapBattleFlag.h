#pragma once

#include "KBEngine.h"
#include "Entity/Trap/Trap.h"

/*
* �ļ����ƣ�TrapBattleFlag.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-02-26
*/

/**
������ս��
*/
class TrapBattleFlag : public Trap
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Trap Supper;

public:
	TrapBattleFlag();
	~TrapBattleFlag();
public:
	virtual UClass* GetEntityModelClassAsset() override;

};
