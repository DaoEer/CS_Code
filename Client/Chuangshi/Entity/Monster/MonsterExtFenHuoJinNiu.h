#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtFenHuoJinNiu.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-01-08
*/

/**
* �����񸱱� �ٻ��ţ��
*/
class CHUANGSHI_API MonsterExtFenHuoJinNiu : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtFenHuoJinNiu();
	~MonsterExtFenHuoJinNiu();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
