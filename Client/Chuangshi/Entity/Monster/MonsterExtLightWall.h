#pragma once
#include "KBEngine.h"
#include "Entity/Monster/Monster.h"

/*
* �ļ����ƣ�MonsterExtLightWall.h
* ����˵����
* �ļ����ߣ�zhutianyang
* Ŀǰά����zhutianyang
* ����ʱ�䣺2018-03-07
*/

/**
* ��ǽ��CST-3248
*/
class CHUANGSHI_API MonsterExtLightWall :	public Monster
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Monster Supper;
public:
	MonsterExtLightWall();
	~MonsterExtLightWall();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

