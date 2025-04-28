
#include "ClimbLadderMoveState.h"
#include "Actor/Player/PlayerCharacter.h"
#include "Component/Role/JumpComponent.h"
#include "GameData/GameDeFine.h"
#include "CS3Base/GameObject.h"

ClimbLadderMoveState::ClimbLadderMoveState()
{

}

ClimbLadderMoveState::~ClimbLadderMoveState()
{

}

void ClimbLadderMoveState::Enter()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(CurrentEntity->Actor());
	if (IsValid(PlayerCharacter) && IsValid(PlayerCharacter->LadderCustomMovmentCpt))
	{
		PlayerCharacter->GetCharacterMovement()->SetMovementMode(MOVE_Custom, (uint8)CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_LADDER);
		PlayerCharacter->LadderCustomMovmentCpt->TempCustomMovementMode = CUSTOM_MOVEMENT_MODE_ENUM::CUSTOM_MOVEMENT_LADDER;

		if (IsValid(PlayerCharacter->GetBaseAnimInstance()))
		{
			PlayerCharacter->GetBaseAnimInstance()->PlayClimbLadderAction();
		}

		//���½�AOI����������Ҵ���������״̬�������һ��λ��
		GameObject* TempGameObject = (GameObject*)PlayerCharacter->GetSelfEntity();
		if (nullptr != TempGameObject)
		{
			FVector Pos = TempGameObject->GetServerSetPos();
			FVector NewPos = PlayerCharacter->GetModelScaleRevisePos(Pos);
			PlayerCharacter->UpdateActionPosition(NewPos);
		}
		
	}
}

void ClimbLadderMoveState::Exit()
{
}
