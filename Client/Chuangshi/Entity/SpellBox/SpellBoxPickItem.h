#pragma once

#include "KBEngine.h"
#include "Entity/SpellBox/SpellBox.h"

/*
* �ļ����ƣ�SpellBoxPickItem.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-10-26
*/

/**
* ��������������ѡ����Ʒ
*/
class SpellBoxPickItem : public SpellBox
{
	KBE_DECLARE_ENTITY_MAP();

	typedef SpellBox Supper;

public:
	SpellBoxPickItem();
	~SpellBoxPickItem();

protected:
	virtual void OnEnterWorld() override;      ///< ��Entity��������ʱ���˷���������
	virtual void OnLeaveWorld() override;      ///< ��Entity�뿪���磨������ʱ��ʱ���˷���������
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
