#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtFirstTongStarcraftBoss.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-07-30
*/

/**
*CST-7904 ������Ե�һ�� Boss��
*/
class MonsterExtFirstTongStarcraftBoss : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtFirstTongStarcraftBoss();
	~MonsterExtFirstTongStarcraftBoss();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

