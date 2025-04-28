#include "MovingPlatformVehicle.h"
#include "Util/CS3Debug.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "Actor/Scene/MovingPlatformVehicleCharacter.h"
#include "GameDevelop/CS3PlayerController.h"

CONTROL_COMPILE_OPTIMIZE_START

DEF_INTERFACE_BEGIN(MovingPlatformVehicle, Supper)
DEF_INTERFACE_END()

KBE_BEGIN_ENTITY_METHOD_MAP(MovingPlatformVehicle, Supper)
KBE_END_ENTITY_METHOD_MAP()

KBE_BEGIN_ENTITY_PROPERTY_MAP(MovingPlatformVehicle, Supper)
KBE_END_ENTITY_PROPERTY_MAP()


MovingPlatformVehicle::MovingPlatformVehicle()
{
	_fActorName = FString("MovingPlatformVehicle");
	isOnGround_ = false;
}

MovingPlatformVehicle::~MovingPlatformVehicle()
{

}

void MovingPlatformVehicle::OnLeaveWorld()
{
	//��ֹͣ������֪ͨ����leaveWorld(�Է�������beforeDestroy��ͻ���Entity�Ѿ�������û֪ͨ��)
	//������������⡣�����˿ͻ����ƶ�ƽ̨����Ҳ���������ԼӸ��ж�,ֻ֪ͨ�������ƶ�ƽ̨����ҿͻ���
	if (ControlID != 0 && IsValid(Actor()))
	{
		AMovingPlatformVehicleCharacter* BindActor = Cast<AMovingPlatformVehicleCharacter>(Actor());
		if (IsValid(BindActor))
		{
			ACS3PlayerController* PlayerController = UGolbalBPFunctionLibrary::GetCS3PlayerController();
			if (UGolbalBPFunctionLibrary::GetPlayerID() == ControlID && IsValid(PlayerController) && PlayerController->GetPawn() == BindActor)
			{
				OnStopControl();
			}
		}
	}
	Supper::OnLeaveWorld();//�������ź��棬�ȵ���������ģ���֪ͨ�������Actor
}

void MovingPlatformVehicle::OnStartControl(int32 InDriverID)
{
	ControlID = InDriverID;
	if (IsValid(Actor()))
	{
		AMovingPlatformVehicleCharacter* BindActor = Cast<AMovingPlatformVehicleCharacter>(Actor());
		if (IsValid(BindActor))
		{
			BindActor->SwitchControl(true);
		}
	}
}

void MovingPlatformVehicle::OnStopControl()
{
	if (ControlID == 0) return;
	ControlID = 0;
	if (IsValid(Actor()))
	{
		AMovingPlatformVehicleCharacter* BindActor = Cast<AMovingPlatformVehicleCharacter>(Actor());
		if (IsValid(BindActor))
		{
			BindActor->SwitchControl(false);
		}
	}
}

UClass* MovingPlatformVehicle::GetEntityModelClassAsset()
{
	return UGolbalBPFunctionLibrary::GetUClassByStr(TEXT("MovingPlatformVehicleCharacter"));
}

CONTROL_COMPILE_OPTIMIZE_END
