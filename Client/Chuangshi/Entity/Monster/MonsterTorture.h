#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterTorture.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-07-31
*/

/**
* ���ʸ���ר�ù���
*/
class CHUANGSHI_API MonsterTorture : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterTorture();
	~MonsterTorture();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
