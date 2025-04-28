#pragma once

#include "KBEngine.h"
#include "Entity/SpellBox/SpellBox.h"
#include "CS3Base/InterfaceDef.h"
/*
* �ļ����ƣ�SpellBoxLingTian.h
* ����˵��������spellbox
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2020-04-23
*/

class SpellBoxLingTian : public SpellBox
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef SpellBox Supper;
public:
	SpellBoxLingTian();
	~SpellBoxLingTian();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
