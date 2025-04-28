// Fill out your copyright notice in the Description page of Project Settings.


#include "SECondition18.h"
#include "GameData/Area/SpaceEventCircleArea.h"
#include "GameData/Area/SpaceEventSquareArea.h"
#include "Manager/MapManager.h"
#include "GameDevelop/CS3GameInstance.h"
#include "util/ConvertUtil.h"

/**
@ Param1: Բ����1���������2
@ Param2: Բ�����е㣻��������ά�����б������Ÿ���
@ Param3: Բ����뾶���������zֵ����
@ Param4: �������zֵ����
*/
void USECondition18::InitParams(FString _SpaceScriptID, INT32 _EventType, INT32 _EventID, FString _Param1, FString _Param2, FString _Param3, FString _Param4)
{
	Supper::InitParams(_SpaceScriptID, _EventType, _EventID, _Param1, _Param2, _Param3, _Param4);
	UUECS3GameInstance::Instance->MapManager->AddSpaceEventArea(_SpaceScriptID, EventType, EventID, FSTRING_TO_INT(_Param1), _Param2, _Param3, _Param4);
}

bool USECondition18::CheckCondition(KBEngine::Entity* _entity, TMap<FString, FString> Params)
{
	FString _EventType = *Params.Find(TEXT("eventType"));
	FString _EventID = *Params.Find(TEXT("eventID"));
	if ((FSTRING_TO_INT(_EventType) == EventType) && (FSTRING_TO_INT(_EventID) == EventID))
	{
		return true;
	}

	return false;
}