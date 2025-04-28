#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtJZZYDB.h
* ����˵����
* �ļ����ߣ�qiurunan
* Ŀǰά����qiurunan
* ����ʱ�䣺2020-03-11
*/

/**
* ���Եذ�(��������)
*/
class CHUANGSHI_API MonsterExtJZZYDB : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtJZZYDB();
	~MonsterExtJZZYDB();

	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};