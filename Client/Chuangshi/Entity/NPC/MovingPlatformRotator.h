#pragma once
#include "KBEngine.h"
#include "Entity/NPC/MovingPlatform.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MovingPlatformRotator.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-10-15
*/

/*
��ת�����ƶ�ƽ̨
*/
class MovingPlatformRotator : public MovingPlatform
{
	KBE_DECLARE_ENTITY_MAP();
	typedef MovingPlatform Supper;
	DEF_INTERFACE_CONTENT()
public:
	MovingPlatformRotator();
	~MovingPlatformRotator();


protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};

