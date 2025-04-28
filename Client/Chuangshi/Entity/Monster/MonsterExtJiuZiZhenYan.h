#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtJiuZiZhenYan.h
* ����˵����
* �ļ����ߣ�qiurunan
* Ŀǰά����qiurunan
* ����ʱ�䣺2018-06-20
*/

/**
* �������Ը���(����)
*/
class CHUANGSHI_API MonsterExtJiuZiZhenYan : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtJiuZiZhenYan();
	~MonsterExtJiuZiZhenYan();

	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
