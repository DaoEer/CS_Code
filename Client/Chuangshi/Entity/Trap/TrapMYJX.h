#pragma once

#include "KBEngine.h"
#include "Entity/Trap/Trap.h"

/*
* �ļ����ƣ�TrapMYJX.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-04-09
*/

/**
CST-6526 ڤ���� �����������
*/
class TrapMYJX : public Trap
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Trap Supper;

public:
	TrapMYJX();
	~TrapMYJX();

};
