#pragma once

#include "KBEngine.h"
#include "Entity/SpellBox/SpellBox.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�SpellBoxSpecial.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-03-30
*/

/**
* ���ͼ�����ⳡ�����
*/
class SpellBoxSpecial : public SpellBox
{
	KBE_DECLARE_ENTITY_MAP();

	typedef SpellBox Supper;
	DEF_INTERFACE_CONTENT()
public:
	SpellBoxSpecial();
	~SpellBoxSpecial();
};
