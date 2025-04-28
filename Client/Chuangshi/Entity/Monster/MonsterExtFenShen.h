#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MonsterExtFenShen.h
* ����˵����
* �ļ����ߣ�QRN
* Ŀǰά����QRN
* ����ʱ�䣺2020-09-07
*/

/**
* ����
*/
class CHUANGSHI_API MonsterExtFenShen : public Monster
{
	KBE_DECLARE_ENTITY_MAP()
	DEF_INTERFACE_CONTENT()
	typedef Monster Supper;
public:
	MonsterExtFenShen();
	~MonsterExtFenShen();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
