#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtJDCY.h
* ����˵�������ز�ҩ����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2020/7/4
*/

/**
* ����
*/
class CHUANGSHI_API MonsterExtJDCY : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtJDCY();
	~MonsterExtJDCY();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
