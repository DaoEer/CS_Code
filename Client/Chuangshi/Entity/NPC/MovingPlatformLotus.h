#pragma once
#include "KBEngine.h"
#include "Entity/NPC/MovingPlatform.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MovingPlatformLotus.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-03-29
*/

/*
*��Ҷ�ƶ�ƽ̨
*/
class MovingPlatformLotus : public MovingPlatform
{
	KBE_DECLARE_ENTITY_MAP();
	typedef MovingPlatform Supper;
	DEF_INTERFACE_CONTENT()
public:
	MovingPlatformLotus();
	~MovingPlatformLotus();


protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

