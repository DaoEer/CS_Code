#include "SystemSwitchData.h"

#include "Util/ConvertUtil.h"
#include "GameDevelop/CS3GameInstance.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "Manager/QuestManager.h"
#include "Manager/SystemSwitchManager.h"
#include "Manager/TutorialManager.h"
#include "CS3Base/UIManager.h"
#include "Guis/ActivityFunctionBarWidget.h"
#include "Util/CS3Debug.h"

CONTROL_COMPILE_OPTIMIZE_START

bool USystemOpenLevelCND::CheckOpenCondition(const FSystemOpenCNDParam& CndParams)
{
	int32 PlayerLevel = UGolbalBPFunctionLibrary::GetIntPropertyValue(UGolbalBPFunctionLibrary::GetPlayerID(), TEXT("level"));
	if (PlayerLevel >= FSTRING_TO_INT(CndParams.Param1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool USystemOpenQuestCND::CheckOpenCondition(const FSystemOpenCNDParam& CndParams)
{
	int32 QuestID = FSTRING_TO_INT(CndParams.Param1);
	int32 QuestIDStatus = FSTRING_TO_INT(CndParams.Param2);
	return UGolbalBPFunctionLibrary::QuestManager()->IsQuestStatus(QuestID, QuestIDStatus);
}

bool USystemOpenQuestTaskCND::CheckOpenCondition(const FSystemOpenCNDParam& CndParams)
{
	int32 QuestID = FSTRING_TO_INT(CndParams.Param1);
	//���ж������Ƿ��ѽ��ܣ���Ϊ����Ŀ��ֻ��δ��ɺ�����ɵ�״̬��û�н�û�ӵ�״̬��δ��δ���Ҳ���ж�Ϊtrue
	if (UGolbalBPFunctionLibrary::QuestManager()->IsQuestStatus(QuestID, (int32)QUEST_STATE::QUEST_IS_DONE)
		|| UGolbalBPFunctionLibrary::QuestManager()->IsQuestStatus(QuestID, (int32)QUEST_STATE::QUEST_NOT_DONE))
	{
		int32 TaskID = FSTRING_TO_INT(CndParams.Param2);
		int32 TaskIDStatus = FSTRING_TO_INT(CndParams.Param3);
		return UGolbalBPFunctionLibrary::QuestManager()->IsTaskStatus(QuestID, TaskID, TaskIDStatus);
	}
	return false;
}

bool USystemOpenSpaceCND::CheckOpenCondition(const FSystemOpenCNDParam& CndParams)
{
	if (CndParams.Param1.Equals(TEXT("")))
	{
		return true;
	}
	const FString SpaceScriptID = UGolbalBPFunctionLibrary::GetSpaceData(FString(TEXT("SPACE_SCRIPT_ID")));
	TArray<FString> Maps = UGolbalBPFunctionLibrary::SplitString(CndParams.Param1, false, "|");
	if (Maps.Contains(SpaceScriptID))
	{
		return true;
	}
	return false;
}

bool USystemCloseLevelCND::CheckCloseCondition(const FSystemCloseCNDParam& CndParams)
{
	int32 PlayerLevel = UGolbalBPFunctionLibrary::GetIntPropertyValue(UGolbalBPFunctionLibrary::GetPlayerID(), TEXT("level"));
	if (PlayerLevel >= FSTRING_TO_INT(CndParams.Param1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool USystemCloseQuestCND::CheckCloseCondition(const FSystemCloseCNDParam& CndParams)
{
	int32 QuestID = FSTRING_TO_INT(CndParams.Param1);
	int32 QuestIDStatus = FSTRING_TO_INT(CndParams.Param2);
	return UGolbalBPFunctionLibrary::QuestManager()->IsQuestStatus(QuestID, QuestIDStatus);
}

bool FSystemOpenCondition::CheckOpenCondition()
{
	if (!CndParams.Script.IsEmpty())
	{
		UClass* ScriptClass = UUECS3GameInstance::Instance->SystemSwitchManager->GetClassByScript(CndParams.Script);
		if (ScriptClass)
		{
			CndObj = NewObject<USystemOpenBaseCND>(GetTransientPackage(), ScriptClass);
			return CndObj->CheckOpenCondition(CndParams);
		}
	}
	return false;
}

bool FSystemCloseCondition::CheckCloseCondition()
{
	if (!CndParams.Script.IsEmpty())
	{
		UClass* ScriptClass = UUECS3GameInstance::Instance->SystemSwitchManager->GetClassByScript(CndParams.Script);
		if (ScriptClass)
		{
			CndObj = NewObject<USystemCloseBaseCND>(GetTransientPackage(), ScriptClass);
			return CndObj->CheckCloseCondition(CndParams);
		}
	}
	return false;
}

void USystemSwitchLightACT::DoOpenAction(const FSystemSwitchACTParam& ActParams)
{
	//��ť�ɵ��
	UWidget* LocalWidget = UGolbalBPFunctionLibrary::TutorialManager()->GetWidgetFromWidgetPath(ActParams.UIType, ActParams.UILinkTarget);
	if (LocalWidget)
	{
		LocalWidget->SetIsEnabled(true);
	}
}

void USystemSwitchLightACT::DoCloseAction(const FSystemSwitchACTParam& ActParams)
{
	//��ť�ɵ��
	UWidget* LocalWidget = UGolbalBPFunctionLibrary::TutorialManager()->GetWidgetFromWidgetPath(ActParams.UIType, ActParams.UILinkTarget);
	if (LocalWidget)
	{
		LocalWidget->SetIsEnabled(false);
	}
}

void USystemSwitchEffectACT::DoOpenAction(const FSystemSwitchACTParam& ActParams)
{
	UActivityFunctionBarWidget* FunctionBarWidget = Cast<UActivityFunctionBarWidget>(UGolbalBPFunctionLibrary::GUIManager()->GetWindow(TEXT("ActivityFunctionBar")));
	if (FunctionBarWidget)
	{
		FunctionBarWidget->AddActivitySystem(ActParams.BtnTag);
	}
}

void USystemSwitchEffectACT::DoCloseAction(const FSystemSwitchACTParam& ActParams)
{
	UActivityFunctionBarWidget* FunctionBarWidget = Cast<UActivityFunctionBarWidget>(UGolbalBPFunctionLibrary::GUIManager()->GetWindow(TEXT("ActivityFunctionBar")));
	if (FunctionBarWidget)
	{
		FunctionBarWidget->RemoveActivitySystem(ActParams.BtnTag);
	}
}

void FSystemSwitchAction::DoOpenAction()
{
	if (!ActParams.Script.IsEmpty())
	{
		UClass* ScriptClass = UUECS3GameInstance::Instance->SystemSwitchManager->GetClassByScript(ActParams.Script);
		if (ScriptClass)
		{
			ActObj = NewObject<USystemSwitchBaseACT>(GetTransientPackage(), ScriptClass);
			ActObj->DoOpenAction(ActParams);
		}
	}
}

void FSystemSwitchAction::DoCloseAction()
{
	if (!ActParams.Script.IsEmpty())
	{
		UClass* ScriptClass = UUECS3GameInstance::Instance->SystemSwitchManager->GetClassByScript(ActParams.Script);
		if (ScriptClass)
		{
			ActObj = NewObject<USystemSwitchBaseACT>(GetTransientPackage(), ScriptClass);
			ActObj->DoCloseAction(ActParams);
		}
	}
}

void FSystemSwitchData::DoAction()
{
	//�п�����Ϊ����ʾ����Ч��
	if (OpenAction.Num() > 0)
	{
		//���Ͽ������� && �����Ϲر�����
		if (CheckOpenCondition() && !CheckCloseCondition())
		{
			OpenAction[0].DoOpenAction();
		}
		//���Ϲر�����,��ȡ������Ч��
		else if (CheckCloseCondition())
		{
			OpenAction[0].DoCloseAction();
		}
		//�����Ͽ�����������ȡ������Ч��
		else if (!CheckOpenCondition())
		{
			OpenAction[0].DoCloseAction();
		}
	}
}

CONTROL_COMPILE_OPTIMIZE_END