#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtWXHJ.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-07-08
*/

/**
* ���л���
*/
class CHUANGSHI_API MonsterExtWXHJ : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtWXHJ();
	~MonsterExtWXHJ();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

