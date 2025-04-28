// Fill out your copyright notice in the Description page of Project Settings.


#include "DumbFilterActorComponent.h"
#include "Actor/ServerCharacter.h"
#include "Actor/Monster/MonsterCharacter.h"
#include "CS3Base/GameObject.h"

void UDumbFilterActorComponent::SimulateMovement(float DeltaTime)
{
	AServerCharacter* Owner = Cast<AServerCharacter>(GetOwner());
	if (!IsValid(Owner)) return;
	KBEngine::Entity *entity = Owner->GetSelfEntity();
	if (!entity) return;
	FVector ActorPos = Owner->GetActorLocation();
	FVector ActorDir = Owner->GetActorRotation().Euler();
	bool isNotDirChange = abs(entity->Direction().X - ActorDir.X) < 0.01 && abs(entity->Direction().Y - ActorDir.Y) < 0.01 && abs(entity->Direction().Z - ActorDir.Z) < 0.01;
	bool isNotPosChange = abs(entity->Position().X - ActorPos.X) < 1 && abs(entity->Position().Y - ActorPos.Y) < 1;
	if (isNotDirChange && isNotPosChange)
	{
		SetActiveComponentTick(false);
		return;
	}

	SafeMove(entity->Position(), entity->Direction(), true);
	SetActiveComponentTick(false);
}

void UDumbFilterActorComponent::OnUpdateVolatileData(const FVector& position, const FVector& direction, int32 parentID)
{
	//����������������ƶ���entity��λ�ƣ�����������ƶ���Entity��������������������
	SetActiveComponentTick(true);
}

void UDumbFilterActorComponent::SetPosition(const FVector& position, int32 parentID)
{
	SetActiveComponentTick(true);
}

void UDumbFilterActorComponent::SetDirection(const FVector& direction, int32 parentID)
{
	SetActiveComponentTick(true);
}

void UDumbFilterActorComponent::OnUpdateVolatileDataByParent(const FVector& position, const FVector& direction, int32 parentID)
{
	AServerCharacter* Owner = Cast<AServerCharacter>(GetOwner());
	if (!IsValid(Owner)) return;
	GameObject* entity = (GameObject*)(Owner->GetSelfEntity());
	if (entity == nullptr) return;
	if (entity->IsPlayer()) return;//��������ƶ�ƽ̨�ϵ�λ�ø���������õ�
	FVector newPos;
	FVector newDir;
	if (GetPositionAndDirection(position, direction, parentID, newPos, newDir))
	{
		SafeMove(newPos, newDir, false);//��������ֱ������
	}
}