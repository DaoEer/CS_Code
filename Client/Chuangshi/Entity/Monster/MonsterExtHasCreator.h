#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtHasCreator.h
* ����˵����ר����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-12-13
*/
class CHUANGSHI_API MonsterExtHasCreator : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	typedef Monster Supper;
public:
	MonsterExtHasCreator();
	~MonsterExtHasCreator();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
