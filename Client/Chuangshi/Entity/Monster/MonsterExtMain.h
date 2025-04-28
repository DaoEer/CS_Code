#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtMain.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2020/8/12
*/

/**
* ���Ϲ������
*/
class CHUANGSHI_API MonsterExtMain : public Monster
{

	KBE_DECLARE_ENTITY_MAP();
	typedef Monster Supper;
public:
	MonsterExtMain();
	 ~MonsterExtMain();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
