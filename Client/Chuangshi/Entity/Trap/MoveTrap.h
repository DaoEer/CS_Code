#pragma once

#include "KBEngine.h"
#include "Entity/Trap/Trap.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MoveTrap.h
* ����˵����
* �ļ����ߣ�wuxiaoou
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-07-07
*/

/**
�ƶ�������
*/
class MoveTrap : public Trap
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Trap Supper;
	DEF_INTERFACE_CONTENT()
public:
	MoveTrap();
	~MoveTrap();


};
