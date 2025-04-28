#pragma once

#include "KBEngine.h"
#include "Entity/SpellBox/SpellBoxSpecial.h"

/*
* �ļ����ƣ�SpellBoxHit.h
* ����˵����
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-09-20
*/

/**
* ײ��������SpellBox
*/
class SpellBoxHit : public SpellBoxSpecial
{
	KBE_DECLARE_ENTITY_MAP();

	typedef SpellBoxSpecial Supper;

public:
	SpellBoxHit();
	~SpellBoxHit();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};