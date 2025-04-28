#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtPart.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2020-8-12
*/

/**
* ���Ϲ������
*/
class CHUANGSHI_API MonsterExtPart : public Monster
{

	KBE_DECLARE_ENTITY_MAP();
	typedef Monster Supper;
public:
	MonsterExtPart();
	 ~MonsterExtPart();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
