#pragma once

#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterGhostEye.h
* ����˵������֮ͫ��
* �ļ����ߣ�liyuxia
* Ŀǰά����liyuxia
* ����ʱ�䣺2020/4/2
*/

/**
* ����
*/
class CHUANGSHI_API MonsterGhostEye : public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterGhostEye();
	~MonsterGhostEye();

protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};
