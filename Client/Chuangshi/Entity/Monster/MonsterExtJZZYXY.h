#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtJZZYXY.h
* ����˵����
* �ļ����ߣ�qiurunan
* Ŀǰά����qiurunan
* ����ʱ�䣺2020-03-11
*/

/**
* ������Ӱ(��������)
*/
class CHUANGSHI_API MonsterExtJZZYXY : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtJZZYXY();
	~MonsterExtJZZYXY();

	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
