#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtRefreshTime.h
* ����˵����
* �ļ����ߣ�lintongbin
* Ŀǰά����lintongbin
* ����ʱ�䣺2019-7-23
*/

class CHUANGSHI_API MonsterExtRefreshTime : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	typedef Monster Supper;
public:
	MonsterExtRefreshTime();
	virtual ~MonsterExtRefreshTime();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

