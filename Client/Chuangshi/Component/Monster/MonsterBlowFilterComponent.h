// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/AvatarFilterActorComponent.h"
#include "MonsterBlowFilterComponent.generated.h"

/**
* �ļ����ƣ�MonsterBlowFilterComponent.h
* ����˵�������ڱ��� ���� �Ĵ���Ч��
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2019-10-12
 */
UCLASS()
class CHUANGSHI_API UMonsterBlowFilterComponent : public UAvatarFilterActorComponent
{
	GENERATED_BODY()

	typedef UAvatarFilterActorComponent Supper;

public:
	virtual void SimulateMovement(float DeltaTime) override;
	void InitData(const FVector& BlowDir_, const float& Speed);

	virtual void OnUpdateVolatileData(const FVector& position, const FVector& direction, int32 parentID) override;
	virtual void SetPosition(const FVector& position, int32 parentID) override;
	virtual void Pos(const int32 vehicleID, const FVector& position, const FVector& direction, const FVector& velocity);

	void EndBlow();

private:
	bool CanUpdatePos(const FVector& NewPos);

	FVector BlowDir;
	float BlowSpeed;

	TArray<FVector> BlowPosArr;

	bool BUndatePos;
	
};
