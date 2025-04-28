#include "JumpAirDownState.h"
#include "Actor/Player/PlayerCharacter.h"
#include "Component/Role/JumpComponent.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "GameData/GameDeFine.h"
#include "GameDevelop/CS3PlayerController.h"
JumpAirDownState::JumpAirDownState()
{

}

JumpAirDownState::~JumpAirDownState()
{

}

void JumpAirDownState::Enter()
{
	APlayerCharacter* CurrentPlayerCharacter = Cast<APlayerCharacter>(CurrentEntity->Actor());
	if (CurrentPlayerCharacter && CurrentPlayerCharacter->JumpComponent)
	{
		CurrentPlayerCharacter->JumpComponent->UpdateJumpState(JUMP_SHOW_STATE::JUMP_SHOW_STATE_AIR_DOWN);
		
		// �ڽ���ģʽ�½����Զ���������
		ACS3PlayerController* PlayerController = UGolbalBPFunctionLibrary::GetCS3PlayerController();
		if (IsValid(PlayerController) && IsValid(PlayerController->GetAtkStateMar()) &&
			!PlayerController->GetAtkStateMar()->IsHaveState(EATTACT_STATE::BEHAVIOR_FALL))
		{
			CurrentPlayerCharacter->SetBaseGravityScale(2.0f);
		}

		if (CurrentPlayerCharacter->GetBaseAnimInstance())
		{
			CurrentPlayerCharacter->GetBaseAnimInstance()->PlayFallingAction();
		}
	}
}

void JumpAirDownState::Exit()
{
}
