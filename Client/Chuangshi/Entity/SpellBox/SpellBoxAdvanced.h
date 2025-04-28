#pragma once

#include "KBEngine.h"
#include "Entity/SpellBox/SpellBox.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�SpellBoxAdvanced.h
* ����˵����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2018-05-16
*/

/**
* �߼�SpellBox
*/
class SpellBoxAdvanced : public SpellBox
{
	KBE_DECLARE_ENTITY_MAP();

	typedef SpellBox Supper;
DEF_INTERFACE_CONTENT()
public:
	SpellBoxAdvanced();
	~SpellBoxAdvanced();
    
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
