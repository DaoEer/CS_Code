// Fill out your copyright notice in the Description page of Project Settings.

#include "PlaneTriggerManager.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "Interface/Role/RoleQuestInterface.h"
#include "Actor/ServerCharacter.h"
#include"Chuangshi.h"
#include "Manager/CfgManager.h"


CONTROL_COMPILE_OPTIMIZE_START

UPlaneTriggerManager* UPlaneTriggerManager::GetInstance()
{
	cs3_checkNoReentry();

	return NewObject<UPlaneTriggerManager>();
}
void UPlaneTriggerManager::InitTriggerData(const FString& PlaneName)
{
	if (TriggerDatas.Contains(PlaneName))return;					// �Ѽ���

	UCfgManager* CfgManager = UUECS3GameInstance::Instance->CfgManager;
	const UConfigTable* ConfigTable = CfgManager->GetTableByType(CSV_CONFIG_TYPE_ENUM::CSV_CONFIG_TYPE_PLANE_TRIGGER);
	if (!ConfigTable)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UPlaneTriggerManager::InitTriggerData : ConfigTable!"));
		return;
	}
	
	const FPLANE_TRIGGER_DATA* configData = ConfigTable->GetRow<FPLANE_TRIGGER_DATA>(PlaneName);
	if (!configData)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UPlaneTriggerManager::InitTriggerData : configData!"));
		return;
	}
	
	FPlaneTriggerCondition fCondition = FPlaneTriggerCondition();
	
	///����������������
	fCondition.Level = configData->Level;
	fCondition.Camp = configData->Camp;
	fCondition.isAreaTrigger = configData->isAreaTrigger;
		
	///������������
	const FString FirstSplitIns = FString(TEXT("|"));
	const FString SecondSplitIns = FString(TEXT(";"));
	const FString ThirdSplitIns = FString(TEXT(":"));

	TArray<FString> FSplitArray = UGolbalBPFunctionLibrary::SplitString(configData->QuestCondition, true, FirstSplitIns);
	for (FString FSplitStr : FSplitArray)
	{
		///һ������Ľ���
		FPlaneTriggerQuestCondition oneQuestCon = FPlaneTriggerQuestCondition();

		TArray<FString> SSplitArray = UGolbalBPFunctionLibrary::SplitString(FSplitStr, true, SecondSplitIns);

		FString QRightST, QLeftST;
		if (SSplitArray.Num() < 1)
		{
			return;
		}
		SSplitArray[0].Split(ThirdSplitIns, &QLeftST, &QRightST);
		SSplitArray.RemoveAt(0);

		oneQuestCon.QuestID = FSTRING_TO_INT(QLeftST);
		oneQuestCon.QuestState = FSTRING_TO_INT(QRightST);

		///��������Ŀ��״̬
		for (FString SSplitStr : SSplitArray)
		{
			SSplitStr.Split(ThirdSplitIns, &QLeftST, &QRightST);
			oneQuestCon.TaskStates.Add(FSTRING_TO_INT(QLeftST), FSTRING_TO_INT(QRightST));
		}
		fCondition.QuestCondition.Add(oneQuestCon);
	}
	TriggerDatas.Add(PlaneName, fCondition);

}


bool UPlaneTriggerManager::CanEnterPlane(const FString& PlaneName)
{
	// ���û������Ĭ�� ���ܽ���λ��
	if (!TriggerDatas.Contains(PlaneName))return false;
	const FPlaneTriggerCondition fCondition = TriggerDatas[PlaneName];

	// ��������߶Ի��ķ�ʽ����
	if (!fCondition.isAreaTrigger)return false;

	AServerCharacter* Player = UGolbalBPFunctionLibrary::GetCS3PlayerCharacter();
	if (!Player)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UPlaneTriggerManager::CanEnterPlane : Player!"));
		return false;
	}
	
	int32 PlayerCamp = Player->GetFinalCamp();
	if (Player->GetSelfEntity() == nullptr)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UPlaneTriggerManager::CanEnterPlane : Player->GetSelfEntity()!"));
		return false;
	}
	int16 PlayerLevel = UGolbalBPFunctionLibrary::GetIntPropertyValue(Player->GetSelfEntity()->ID(), TEXT("level"));
	if ((fCondition.Camp && PlayerCamp != fCondition.Camp) || PlayerLevel < fCondition.Level) 
	{
		return false;
	}

	URoleQuestInterface* RoleQuestInterface = Cast<URoleQuestInterface>(UGolbalBPFunctionLibrary::GetInterfaceByName(TEXT("RoleQuestInterface")));
	if (!RoleQuestInterface)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UPlaneTriggerManager::CanEnterPlane : RoleQuestInterface!"));
		return false;
	}

	bool __passCheck;
	for (FPlaneTriggerQuestCondition oneQuestCon : fCondition.QuestCondition)
	{
		__passCheck = true;
		
		///����״̬���
		if (!RoleQuestInterface->IsQuestStatus(oneQuestCon.QuestID, oneQuestCon.QuestState))
		{
			__passCheck = false;
		}

		///����Ŀ��״̬���
		for (auto i = oneQuestCon.TaskStates.CreateIterator(); i; ++i)
		{
			int32 taskID = i.Key();
			int32 taskState = i.Value();
			if (!RoleQuestInterface->IsTaskStatus(oneQuestCon.QuestID, taskID, taskState))
			{
				__passCheck = false;
				break;
			}
		}

		if (__passCheck)return true;///��һ������״̬�����˾Ϳɽ���λ��
	}

	return false;

}

CONTROL_COMPILE_OPTIMIZE_END
