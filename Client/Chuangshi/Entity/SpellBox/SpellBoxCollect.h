#pragma once

#include "KBEngine.h"
#include "Entity/SpellBox/SpellBox.h"
/*
* �ļ����ƣ�SpellBoxCollect.h
* ����˵�����ɼ�spellbox
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020-04-02
*/

class SpellBoxCollect : public SpellBox
{
	KBE_DECLARE_ENTITY_MAP();

	typedef SpellBox Supper;
public:
	SpellBoxCollect();
	~SpellBoxCollect();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
