#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtClickAndInteractive.h
* ����˵�����������ȿ���˫���ֿ���F�����Ĺ���
* �ļ����ߣ�liyuxia
* Ŀǰά����liyuxia
* ����ʱ�䣺2020-5-26
*/

class CHUANGSHI_API MonsterExtClickAndInteractive : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtClickAndInteractive();
	~MonsterExtClickAndInteractive();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};