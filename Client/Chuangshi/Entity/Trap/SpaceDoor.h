#pragma once

#include "KBEngine.h"
#include "Entity/Trap/Trap.h"

/*
* �ļ����ƣ�SpaceDoor
* ����˵����
* �ļ����ߣ�chenweilan
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-11-02
*/

/**
*���ͼ������
*/
class SpaceDoor : public Trap
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Trap Supper;

public:
	SpaceDoor();
	~SpaceDoor();

};
