#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtJingShiDongKu.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-12-20
*/

/**
* ��ʯ���߸���ר�ù���
*/
class CHUANGSHI_API MonsterExtJingShiDongKu : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtJingShiDongKu();
	~MonsterExtJingShiDongKu();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
