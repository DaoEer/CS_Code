#include "JSZZCircleArea.h"
#include "Actor/ServerCharacter.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "Interface/Role/RoleSpaceContentInterface.h"
#include "Util/CS3Debug.h"


UJSZZCircleArea::UJSZZCircleArea()
{
}

UJSZZCircleArea::~UJSZZCircleArea()
{
}

void UJSZZCircleArea::InitParams(const FString SpaceScriptID, const FVector position, const float range)
{
	Point = position;
	Range = range * 100.0;
	ScriptID = SpaceScriptID;
}
bool UJSZZCircleArea::IsPlayerIn()
{
	AServerCharacter* PlayerActor = UGolbalBPFunctionLibrary::GetCS3PlayerCharacter();
	if (!PlayerActor)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UActivityCircleArea::IsPlayerIn : PlayerActor!"));
		return false;
	}
	//��ȡ��ǰLevel
	const FString level = UGolbalBPFunctionLibrary::GetSpaceData(FString(TEXT("SPACE_SCRIPT_ID")));
	if (!level.Equals(ScriptID))return false;

	FVector PlayerPosition = PlayerActor->GetActorLocation();
	// ���������֮��ľ���
	int Distance = FVector::Dist(Point, PlayerPosition);
	if (Distance > Range)return false;

	return true;
}

void UJSZZCircleArea::OnEnter(const FString SpaceScriptID)
{
	URoleSpaceContentInterface* RoleSpaceContentInterface = Cast<URoleSpaceContentInterface>(UGolbalBPFunctionLibrary::GetInterfaceByName(TEXT("RoleSpaceContentInterface"), 0));
	if (RoleSpaceContentInterface)
	{
		RoleSpaceContentInterface->OnEnterJSZZCircleArea();
	}
}

void UJSZZCircleArea::OnLeave(const FString SpaceScriptID)
{
	URoleSpaceContentInterface* RoleSpaceContentInterface = Cast<URoleSpaceContentInterface>(UGolbalBPFunctionLibrary::GetInterfaceByName(TEXT("RoleSpaceContentInterface"), 0));
	if (RoleSpaceContentInterface)
	{
		RoleSpaceContentInterface->OnLeaveJSZZCircleArea();
	}
}