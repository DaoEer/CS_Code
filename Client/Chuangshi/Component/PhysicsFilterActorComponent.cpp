
#include "PhysicsFilterActorComponent.h"
#include "Actor/Monster/MonsterCharacter.h"
#include "Actor/ServerCharacter.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "Util/CS3Debug.h"
CONTROL_COMPILE_OPTIMIZE_START

#pragma region UPhysicsFilterActorComponent
UPhysicsFilterActorComponent::UPhysicsFilterActorComponent()
{
	IsIgnoreServerPos = false;
	DestPos = FVector::ZeroVector;
	Velocity = 10.f;
}

void UPhysicsFilterActorComponent::SimulateMovement(float DeltaTime)
{
	AServerCharacter* ServerActor = Cast<AServerCharacter>(GetOwner());
	if (IsValid(ServerActor))
	{
		if (FMath::IsNearlyZero(Velocity))
		{
			ServerActor->ResetFilter();
			return;
		}

		Entity* SelfEntity = ServerActor->GetSelfEntity();

		if (SelfEntity == nullptr)
		{
			return;
		}

		float MoveLength;
		float FrameDistance = DeltaTime * Velocity * 100.f;
		float RemainMoveDistance = FrameDistance;
		float DefaultMaxDistance = 60;//�������Ϊ60��Ӧ��1���Ľ�����ֱ��Ϊ68��60��֤���ԽӴ���
		float TargetDistance = GetDestDistance();//��Ŀ���ľ���

		if (TargetDistance <= 1.0f)
		{
			ServerActor->ResetFilter();//�����ƶ�
			return;
		}
		if (FrameDistance < DefaultMaxDistance)
		{
			MoveLength = FMath::Min(FrameDistance, TargetDistance);
			ServerActor->SetCharacterMovePosition(MoveLength, DestPos, false);
			TargetDistance = GetDestDistance();// ���»�ȡ����Ϊλ���Ѿ�����
			if (TargetDistance <= 1.0f)
			{
				ServerActor->ResetFilter();//�����ƶ�
				return;
			}
		}
		else
		{
			//һ֡�ƶ��ľ������ֶ��ƶ���Ϊ����ײ���
			while (RemainMoveDistance - DefaultMaxDistance > 0)
			{
				MoveLength = FMath::Min(TargetDistance, DefaultMaxDistance);
				ServerActor->SetCharacterMovePosition(MoveLength, DestPos, false);
				RemainMoveDistance -= MoveLength;
				TargetDistance = GetDestDistance();// ���»�ȡ����Ϊλ���Ѿ�����
				if (TargetDistance <= 1.0f) 
				{
					ServerActor->ResetFilter();//�����ƶ�
					return;
				}
			}
			ServerActor->SetCharacterMovePosition(FMath::Min(TargetDistance, RemainMoveDistance), DestPos, false);
			if (GetDestDistance() <= 1.0f) // ���»�ȡ����Ϊλ���Ѿ�����
			{
				ServerActor->ResetFilter();//�����ƶ�
				return;
			}
		}
	}
}

void UPhysicsFilterActorComponent::InitData(const float& MoveSpeed, const FVector& DstPos)
{
	DestPos = DstPos;
	SetActiveComponentTick(true);
	Velocity = MoveSpeed;
}

void UPhysicsFilterActorComponent::OnUpdateVolatileData(const FVector& position, const FVector& direction, int32 parentID)
{
	//����λ��ֻ�ĳ���λ�������Tick��ģ��ģ�
	AServerCharacter* Owner = Cast<AServerCharacter>(GetOwner());
	if (!IsValid(Owner)) return;
	FVector newPos;
	FVector newDir;
	if (GetPositionAndDirection(FVector::ZeroVector, direction, parentID, newPos, newDir))
	{
		SafeMove(Owner->GetActorLocation(), newDir, false);
	}
}

float UPhysicsFilterActorComponent::GetDestDistance()
{
	AServerCharacter* ServerActor = Cast<AServerCharacter>(GetOwner());
	if (!IsValid(ServerActor)) return 0.0f;
	Entity* SelfEntity = ServerActor->GetSelfEntity();
	if (SelfEntity == nullptr) return 0.0f;
	float TargetDistance;//��Ŀ���ľ���
	if (SelfEntity->Parent())
	{
		TargetDistance = FVector::Distance(DestPos, SelfEntity->Parent()->PositionWorldToLocal(ServerActor->GetActorLocation()));
	}
	else
	{
		TargetDistance = FVector::Distance(DestPos, ServerActor->GetActorLocation());
	}
	return TargetDistance;
}
#pragma endregion

#pragma region UCurveFilterActorComponent
UCurveFilterActorComponent::UCurveFilterActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetActiveComponentTick(false);
}

void UCurveFilterActorComponent::SimulateMovement(float DeltaTime)
{
	AMonsterCharacter* MonsterActor = Cast<AMonsterCharacter>(GetOwner());
	if (!IsValid(MonsterActor))
	{
		CS3_Warning(TEXT("-->Null Pointer error:UCurveFilterActorComponent::TickComponent : MonsterActor!"));
		return;
	}

	FVector ZDir = FVector(0.0f, 0.0f, 1.0f);
	MoveTime += DeltaTime;
	FVector SrcPos = MonsterActor->GetActorLocation();
	//�������˶��������׶��ȼ��٣�����׶��ȼ��٣�ˮƽ��������
	if (MoveTime >= NeedTime)
	{
		MonsterActor->SetActorLocation(DstPosition);
		MonsterActor->SetActorRotation(FQuat::MakeFromEuler(DstDirection));
		ClearMoveData();
		MonsterActor->ResetFilter();

		MonsterActor->MonsterCharacterJumpEnd(true);

	}
	else if (MoveTime <= ZUpTime)
	{
		FVector MovePos = SrcPos + XMoveDir * DeltaTime + ZDir * ((ZUpTime - MoveTime - 0.5f*DeltaTime)*ZGravity*DeltaTime);
		MonsterActor->SetActorLocation(MovePos);
	}
	else
	{
		FVector MovePos = SrcPos + XMoveDir * DeltaTime - ZDir * ((MoveTime - ZUpTime - 0.5f*DeltaTime)*ZGravity*DeltaTime);
		MonsterActor->SetActorLocation(MovePos);
	}
}

void UCurveFilterActorComponent::SetDirection(const FVector& direction, int32 parentID)
{
	//FQuat Direction = FQuat::MakeFromEuler(direction);
	//GetOwner()->SetActorRotation(Direction);
	FVector newPos;
	FVector newDir;
	if (GetPositionAndDirection(FVector::ZeroVector, direction, parentID, newPos, newDir))
	{
		DstDirection = newDir;
	}
}

void UCurveFilterActorComponent::InitData(float Gravity, float UpTime, float XSpeed, FVector DstPos)
{
	ZUpTime = UpTime;
	FVector SrcPos = GetOwner()->GetActorLocation();
	FVector Dir = DstPos - SrcPos;
	FVector XDir = FVector(Dir.X, Dir.Y, 0.0f);
	float XMoveSpeed = XSpeed;
	if (Dir.Z > 1.0f)	//Ŀ��������ʼ��(CST-1999),�� ��㼸�����
	{
		if (0.5f*Gravity*ZUpTime*ZUpTime > Dir.Z)
		{
			ZGravity = Gravity;
			NeedTime = sqrtf((ZUpTime*ZUpTime) - (2.0f*Dir.Z / ZGravity)) + ZUpTime;
			XMoveSpeed = XDir.Size() / NeedTime;
		}
		else
		{
			ZGravity = (2.0f*Dir.Z) / (ZUpTime*ZUpTime) + 2000.0f;
			NeedTime = sqrtf((ZUpTime*ZUpTime) - (2.0f*Dir.Z / ZGravity)) + ZUpTime;
			XMoveSpeed = XDir.Size() / NeedTime;
		}
	}
	else
	{
		NeedTime = XDir.Size() / XMoveSpeed;
		//�������������ٶȺ㶨��Զ����ˮƽ�ٶȺ㶨
		if (NeedTime <= 2.0f*ZUpTime)
		{
			ZGravity = Gravity;
			NeedTime = sqrtf((ZUpTime*ZUpTime) + (2.0f*abs(Dir.Z) / ZGravity)) + ZUpTime;
			XMoveSpeed = XDir.Size() / NeedTime;
		}
		else
		{
			ZGravity = 2.0f*abs(Dir.Z) / ((NeedTime*NeedTime) - (2.0f*NeedTime*ZUpTime));
		}
	}
	XDir.Normalize();
	XMoveDir = XDir * XMoveSpeed;
	MoveTime = 0.0f;
	DstPosition = DstPos;
	FRotator ScrRotator = UGolbalBPFunctionLibrary::GetLookAtRotator(SrcPos, DstPosition);
	DstDirection = ScrRotator.Vector();
	GetOwner()->SetActorRotation(ScrRotator);
}

void UCurveFilterActorComponent::ClearMoveData()
{
	ZUpTime = 0.0f;
	ZGravity = 0.0f;
	MoveTime = 0.0f;
	NeedTime = 0.0f;
	XMoveDir = FVector::ZeroVector;
	DstPosition = FVector::ZeroVector;
	DstDirection = FVector::ZeroVector;
}
#pragma endregion

#pragma region UHitBackMoveFilterActorComponent
UHitBackMoveFilterActorComponent::UHitBackMoveFilterActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	Dir = FQuat::Identity;
	DestPos = FVector::ZeroVector;
	Velocity = 10.f;
}

void UHitBackMoveFilterActorComponent::SimulateMovement(float DeltaTime)
{
	AServerCharacter* ServerActor = Cast<AServerCharacter>(GetOwner());
	if (IsValid(ServerActor))
	{
		float Distance = DeltaTime * Velocity * 100.f;
		FVector CurrPos = ServerActor->GetActorLocation();
		FVector2D dir2D = FVector2D(DestPos - CurrPos);
		FVector dir3D = DestPos - CurrPos;
		dir2D.Normalize();//2D����ͬ��XY��3Dͬ��Z
		dir3D.Normalize();
		FVector MoveDir = FVector(Distance * dir2D, Distance * dir3D.Z);

		if ((DestPos - CurrPos).Size2D() <= Distance)
		{
			ServerActor->ResetFilter();
			SetActiveComponentTick(false);
		}
		else
		{
			FVector MovePos = CurrPos + MoveDir;
			ServerActor->SetActorLocation(MovePos,true);
		}
	}
}

void UHitBackMoveFilterActorComponent::SetDirection(const FVector& direction, int32 parentID)
{
	AServerCharacter* Owner = Cast<AServerCharacter>(GetOwner());
	if (!IsValid(Owner)) return;
	FVector newPos;
	FVector newDir;
	if (GetPositionAndDirection(FVector::ZeroVector, direction, parentID, newPos, newDir))
	{
		SafeMove(Owner->GetActorLocation(), newDir, false);
	}
}

void UHitBackMoveFilterActorComponent::InitData(float InMoveSpeed, const FVector& InDestination, const FVector& InStartPos, const FVector& InDestPos)
{
	Velocity = InMoveSpeed;
	Destination = InDestination;
	StartPos = InStartPos;
	DestPos = InDestPos;
}
#pragma endregion
CONTROL_COMPILE_OPTIMIZE_END