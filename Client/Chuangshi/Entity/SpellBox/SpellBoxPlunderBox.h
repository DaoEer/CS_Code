#pragma once

#include "KBEngine.h"
#include "Entity/SpellBox/SpellBox.h"

/*
* �ļ����ƣ�SpellBoxPlunderBox.h
* ����˵����
* �ļ����ߣ�zhutianyang
* Ŀǰά����zhutianyang
* ����ʱ�䣺2020-9-08
*/

/**
* ����Ӷ�ս ����
*/
class SpellBoxPlunderBox : public SpellBox
{
	KBE_DECLARE_ENTITY_MAP();

	typedef SpellBox Supper;

public:
	SpellBoxPlunderBox();
	~SpellBoxPlunderBox();

protected:
	virtual void OnEnterWorld() override;      ///< ��Entity��������ʱ���˷���������
	virtual void OnLeaveWorld() override;      ///< ��Entity�뿪���磨������ʱ��ʱ���˷���������
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
