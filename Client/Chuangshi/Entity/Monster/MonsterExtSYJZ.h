#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtSYJZ.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-07-24
*/

/**
* ��Դ����(�ɵ������:�������)
*/
class CHUANGSHI_API MonsterExtSYJZ : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtSYJZ();
	~MonsterExtSYJZ();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
