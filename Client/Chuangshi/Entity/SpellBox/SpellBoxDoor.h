#pragma once

#include "KBEngine.h"
#include "Entity/SpellBox/SpellBoxSpecial.h"

/*
* �ļ����ƣ�SpellBoxDoor.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-09-27
*/

/**
* ��Χ��⽻����SpellBox
*/
class SpellBoxDoor : public SpellBoxSpecial
{
	KBE_DECLARE_ENTITY_MAP();

	typedef SpellBoxSpecial Supper;

public:
	SpellBoxDoor();
	~SpellBoxDoor();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};