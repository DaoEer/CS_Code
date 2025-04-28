#pragma once

#include "KBEngine.h"
#include "Entity/Role/CS3Role.h"
#include "CS3Base/InterfaceDef.h"


class CHUANGSHI_API CS3PlayRole : public CS3Role
{
	KBE_DECLARE_ENTITY_MAP()
		DEF_INTERFACE_CONTENT()
		typedef CS3Role Supper;
public:
	CS3PlayRole();
	~CS3PlayRole();
	virtual void OnLeaveScenes() override;
protected:
	virtual void __init__() override;
	virtual void OnDestroy() override;
	virtual void OnEnterWorld() override;     ///< ��Entity��������ʱ���˷���������
	virtual void OnLeaveWorld() override;     ///< ��Entity�뿪���磨������ʱ��ʱ���˷���������
	
private:
	bool bIsLeavingWorld = false; ///<�Ƿ������뿪����(��Ҫ����������뿪����ʱ�ײ� �����OnLeaveScenes������OnLeaveScenes�������н��entity��Actor�������ᵼ�����̲���ȷ����ǰ��ʱ����ʹ�øñ���������OnLeaveScenes�Ƿ���Ҫִ��UnBindActorToEntity)
};