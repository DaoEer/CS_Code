#pragma once
#include "KBEngine.h"
#include "Entity/NPC/MovingPlatform.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�MovingPlatformVehicle.h
* ����˵�������˿��ƶ����
* �ļ����ߣ�liyuxia
* Ŀǰά����liyuxia
* ���� 2020/9/8
*/

class CHUANGSHI_API MovingPlatformVehicle : public MovingPlatform
{
	KBE_DECLARE_ENTITY_MAP();

	typedef MovingPlatform Supper;
	DEF_INTERFACE_CONTENT()
public:
	MovingPlatformVehicle();
	~MovingPlatformVehicle();
	virtual void OnLeaveWorld() override;
	void OnStartControl(int32 InDriverID);
	void OnStopControl();
protected:
	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
private:
	int32 ControlID;
};