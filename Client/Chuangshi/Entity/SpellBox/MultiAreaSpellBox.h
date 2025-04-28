#pragma once

#include "KBEngine.h"
#include "Entity/NPCBaseObject.h"

/*
* �ļ����ƣ�MultiAreaSpellBox.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-10-18
*/

/**
* �����򴥷�Entity
*/
class MultiAreaSpellBox : public NPCBaseObject
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef NPCBaseObject Supper;

public:
	MultiAreaSpellBox();
	~MultiAreaSpellBox();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
