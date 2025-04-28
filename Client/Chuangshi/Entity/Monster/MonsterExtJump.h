#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtJump.h
* ����˵������Ծ����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2019-1-26
*
*/

class CHUANGSHI_API MonsterExtJump : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtJump();
	~MonsterExtJump();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
