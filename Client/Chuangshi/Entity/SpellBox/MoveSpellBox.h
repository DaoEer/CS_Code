#pragma once

#include "KBEngine.h"
#include "Entity/SpellBox/SpellBox.h"

/*
* �ļ����ƣ�MoveSpellBox.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-09-01
*/

/**
* ���ƶ��������
*/
class MoveSpellBox : public SpellBox
{
	KBE_DECLARE_ENTITY_MAP();

	typedef SpellBox Supper;

public:
	MoveSpellBox();
	~MoveSpellBox();
};
