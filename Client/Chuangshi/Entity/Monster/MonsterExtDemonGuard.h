#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtLightWall.h
* ����˵����
* �ļ����ߣ�zhutianyang
* Ŀǰά����zhutianyang
* ����ʱ�䣺2018-03-07
*/

/**
* ��ǽ��CST-3248
*/
class CHUANGSHI_API MonsterExtDemonGuard :	public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtDemonGuard();
	~MonsterExtDemonGuard();
};

