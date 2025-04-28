#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtXinMo.h
* ����˵����
* �ļ����ߣ�hezhiming
* Ŀǰά����hezhiming
* ����ʱ�䣺2017-06-06
*/

/**
* ��ħMonster�����������ۺͼ���
*/
class CHUANGSHI_API MonsterExtXinMo : public Monster
{
	KBE_DECLARE_ENTITY_MAP();
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtXinMo();
	~MonsterExtXinMo();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
