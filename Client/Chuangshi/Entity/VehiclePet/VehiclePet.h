#pragma once


#include "KBEngine.h"
#include "Entity/NPCBaseObject.h"
#include "CS3Base/InterfaceDef.h"

/*
* �ļ����ƣ�VehiclePet.h
* ����˵����
* �ļ����ߣ�chengdongyong
* Ŀǰά����chengdongyong
* ����ʱ�䣺2017-07-11
*/

/*
* ������
*/

class VehiclePet : public NPCBaseObject
{
	KBE_DECLARE_ENTITY_MAP();

	typedef NPCBaseObject Supper;
	DEF_INTERFACE_CONTENT()
public:
	VehiclePet();
	~VehiclePet();

public:
	
	/**
	*��������
	*
	*
	*@return ��
	*/
	virtual void DoCreateCharacter() override;

	virtual bool IsState(ENTITY_STATE EntityState) override;///<Entity״̬
protected:
	//virtual void OnUpdateVolatileData() override; ///<ͬ��λ�ó�����Ϣ

	virtual UClass* GetEntityModelClassAsset() override;///< ��ȡEntityģ��
};