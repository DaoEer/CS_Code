#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtYCJMDBoss.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-9-5
*/

/**
* CST-8727 �´�������Boss
*/
class CHUANGSHI_API MonsterExtYCJMDBoss : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtYCJMDBoss();
	~MonsterExtYCJMDBoss();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
