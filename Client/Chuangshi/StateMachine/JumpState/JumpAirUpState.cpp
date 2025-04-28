#include "JumpAirUpState.h"
#include "Actor/Player/PlayerCharacter.h"
#include "Component/Role/JumpComponent.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "GameData/GameDeFine.h"
#include "GameDevelop/CS3PlayerController.h"

JumpAirUpState::JumpAirUpState()
{

}

JumpAirUpState::~JumpAirUpState()
{

}

void JumpAirUpState::Enter()
{
	APlayerCharacter* CurrentPlayerCharacter = Cast<APlayerCharacter>(CurrentEntity->Actor());
	if (CurrentPlayerCharacter && CurrentPlayerCharacter->JumpComponent)
	{
		CurrentPlayerCharacter->JumpComponent->UpdateJumpState(JUMP_SHOW_STATE::JUMP_SHOW_STATE_AIR_UP);
		
		// �ڽ���ģʽ�½����Զ���������
		ACS3PlayerController* PlayerController = UGolbalBPFunctionLibrary::GetCS3PlayerController();
		if (IsValid(PlayerController) && IsValid(PlayerController->GetAtkStateMar()) && 
			!PlayerController->GetAtkStateMar()->IsHaveState(EATTACT_STATE::BEHAVIOR_FALL))
		{
			CurrentPlayerCharacter->SetBaseGravityScale(1.0f);
		}

		if (CurrentPlayerCharacter->GetBaseAnimInstance())
		{
			CurrentPlayerCharacter->GetBaseAnimInstance()->PlayFallingAction();
		}

		////������Լ�������ͬ����Ծ���ж�������
		//if (!CurrentPlayerCharacter->ActorIsPlayer())
		//{
		//	FName ActionId = "JumpAir_01";
		//	CurrentPlayerCharacter->PlayAction(ActionId);
		//}
	}
}

void JumpAirUpState::Exit()
{
}
