#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtXuanTianBaoLu.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-02-20
*/

/**
* ���챦¼���� ��ת����֧��
*/
class CHUANGSHI_API MonsterExtXuanTianBaoLu : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtXuanTianBaoLu();
	~MonsterExtXuanTianBaoLu();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��

};
