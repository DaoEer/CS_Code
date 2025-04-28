#pragma once

#include "CoreMinimal.h"
#include "GameDeFine.h"
#include "AttCityMemberData.generated.h"


USTRUCT(BlueprintType)
struct CHUANGSHI_API FAttCityMemberData
{
	GENERATED_USTRUCT_BODY()
		FAttCityMemberData() {};
public:
	/// ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Name")
		FString Name;
	/// ������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "BelongSide")
		BELONG_SIDE BelongSide = BELONG_SIDE::BELONG_SIDE_ATTACK;
	/// ��ɱ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "KillEnemy")
		int32 KillEnemy = 0;
	/// ��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Dead")
		int32 Dead = 0;
	/// ��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Assist")
		int32 Assists = 0;
	/// ��ɱС����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "KillSoldier")
		int32 KillSoldier = 0;
	/// ����ܾ���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "TotalExploit")
	int32 TotalExploit = 0;
	/// ����ʿ����ʧ������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "OwnerSoldierDeadNum")
	int32 OwnerSoldierDeadNum = 0;
};