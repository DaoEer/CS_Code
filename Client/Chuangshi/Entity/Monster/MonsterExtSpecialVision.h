#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtSpecialVision.h
* ����˵����
* �ļ����ߣ�lintongbin
* Ŀǰά����lintongbin
* ����ʱ�䣺2019-12-23
*/

/**
* 
*/
class CHUANGSHI_API MonsterExtSpecialVision : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtSpecialVision();
	~MonsterExtSpecialVision();
};

