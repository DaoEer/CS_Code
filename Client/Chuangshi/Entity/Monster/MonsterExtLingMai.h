#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtLingMai.h
* ����˵����
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2018-03-20
*/

/**
* ����ս��BOSS
*/
class CHUANGSHI_API MonsterExtLingMai :	public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()

	typedef Monster Supper;
public:
	MonsterExtLingMai();
	~MonsterExtLingMai();

	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

