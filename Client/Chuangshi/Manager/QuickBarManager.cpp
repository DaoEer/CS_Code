#include "QuickBarManager.h"
#include "Interface/Role/QuickBarInterface.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "CfgManager.h"
#include "SkillManager.h"
#include "TutorialManager.h"
#include "GameDevelop/CS3GameInstance.h"
#include "Util/ConvertUtil.h"
#include "EventManager.h"
#include "GameData/ConstDataBP.h"
#include "Util/CS3Debug.h"

CONTROL_COMPILE_OPTIMIZE_START

UQuickBarManager::UQuickBarManager()
{
	
}

UQuickBarManager::~UQuickBarManager()
{

}

UQuickBarManager* UQuickBarManager::GetInstance()
{
	cs3_checkNoReentry();

	return NewObject<UQuickBarManager>();
}

void UQuickBarManager::Init()
{
	HasCD = false;
	LoadCfg();
}

void UQuickBarManager::onLeaveWorld()
{
	QbItemLists.Empty();
	RemoveStageQbItems.Empty();
	ReplaceQbItemList.Empty();
	SkillPassiveHoldEffectDatas.Empty();
	StopCdTimer();
}

FQB_ITEM UQuickBarManager::GetQBItemByIndex(const int32& Page, const int32& Index)
{
	if (QbItemLists.Contains(Page))
	{

		for (auto item : QbItemLists[Page])
		{
			if (item.SlotIndex == Index)
			{
				return item;
			}
		}
	}
	FQB_ITEM item;
	item.SlotIndex = Index;
	item.QbID = 0;
	return item;
}

int32 UQuickBarManager::GetIndexByQBID(const int32& QbID)
{
	TArray<FQB_ITEM> QbItems = GetQbItemList();
	for (auto item : QbItems)
	{
		if (item.QbID == QbID)
		{
			return item.SlotIndex;
		}
	}
	return -1;
}

bool UQuickBarManager::HasQuickItemInIndex(int32 Index)
{
	int32 SlotIndex = (CurPage * 10) + Index;
	TArray<FQB_ITEM> QbItems = GetQbItemList();
	for (auto item : QbItems)
	{
		if (item.SlotIndex == SlotIndex)
		{
			return true;
		}
	}
	return false;
}

int32 UQuickBarManager::GetQuickBarSlotIndex(int32 EmptyIndex/* = 1*/)
{
	int32 Index = -1;
	switch (CurPage)
	{
	case 0:
		Index = GetQuickBarMinIndex(CurPage, 0, 9, EmptyIndex);
		break;
	case 1:
		Index = GetQuickBarMinIndex(CurPage, 10, 19, EmptyIndex);
		break;
	case 2:
		Index = GetQuickBarMinIndex(CurPage, 20, 29, EmptyIndex);
		break;
	default:
		Index = -1;
		break;
	}
	return Index;
}

int32 UQuickBarManager::GetQuickBarMinIndex(int32 page, int32 minIndex, int32 maxIndex, int32 EmptyIndex)
{
	if (QbItemLists.Contains(page))
	{
		int32 LocalIndex = 0;
		TArray<FQB_ITEM> Item = QbItemLists[page];
		for (int i = minIndex; i <= maxIndex; i++)
		{
			int32 Sign = 0;
			for (auto Temp : Item)
			{
				if (i == Temp.SlotIndex)
				{
					Sign = 1;
					break;
				}
			}
			//��ǰiΪ�ո���
			if (Sign == 0)
			{
				//����ǵڼ����ո�����
				LocalIndex = LocalIndex + 1;
				if (LocalIndex == EmptyIndex)
				{
					return i;
				}
			}
		}
	}
	return -1;
}

TArray<FQB_ITEM> UQuickBarManager::GetQbItemList()
{
	UQuickBarInterface* QuickBarInterface = Cast<UQuickBarInterface>(UGolbalBPFunctionLibrary::GetInterfaceByName(TEXT("QuickBarInterface"), 0));
	if (IsValid(QuickBarInterface))
	{
		int32 skillPosture = QuickBarInterface->GetSkillPosture();
		int32 Page = (skillPosture ? skillPosture % 100 : 1) - 1;
		if (QbItemLists.Contains(Page))
		{
			return QbItemLists[Page];
		}
	}
	TArray<FQB_ITEM> Temp;
	return Temp;
}

int32 UQuickBarManager::GetCurPage()
{
	return CurPage;
}

void UQuickBarManager::SetQuickBarCurPage(int32 InCurPage)
{
	CurPage = InCurPage;
}

void UQuickBarManager::SetQuickBarExtCurPage1(int32 InCurPage)
{
	ExtCurPage_1 = InCurPage;
}

void UQuickBarManager::SetQuickBarExtCurPage2(int32 InCurPage)
{
	ExtCurPage_2 = InCurPage;
}

void UQuickBarManager::OnUpdateQBItem(int32 Index, int32 QbType, int32 Id, int32 BindType, int32 Page, int32 QuickID, FString PetUid)
{
	FQB_ITEM item = InitQuickItem(Index, QbType, Id, BindType, QuickID, PetUid);
	
	if (GetQBItemByIndex(Page, Index).QbID)
	{
		QbItemLists[Page].Remove(GetQBItemByIndex(Page, Index));
	}

	if (QbItemLists.Contains(Page))
	{
		QbItemLists[Page].Add(item);
	}
	else 
	{
		TArray<FQB_ITEM> TempList;
		TempList.Add(item);
		QbItemLists.Add(Page, TempList);
	}
	//ɾ���������Я����
	if (RemoveStageQbItems.Contains(item.QuickID))
	{
		RemoveStageQbItems.Remove(item.QuickID);
	}

	//���¼ӵ�SkillID����һ�ݶ�ӦSkillData���ݲ�����
	UUECS3GameInstance::Instance->SkillManager->AddTotalSkillData(item.QbID); 

	//֪ͨ����ָ�����������������ӵ����QbItem��ָ�������������ָ��
	UGolbalBPFunctionLibrary::TutorialManager()->OnAddQBItem(item.QbID);

	//��Я����
	if (item.QuickID != 0 && item.QuickType == QUICK_SKILL_TYPE::QUICK_SKILL_TYPE_STAGE)
	{
		UpdateQuickSkillHoldTime();
	}
	//֪ͨ����
	if (IsNeedUpdateQuickBar(Page))
	{
		OnUpdateQBItemUI(item);
	}
}

void UQuickBarManager::OnRemoveQBItem(int32 Page, int32 Index)
{
	FQB_ITEM QbItem = GetQBItemByIndex(Page, Index);
	int32 QbID = QbItem.QbID;
	int32 QbType = QbItem.QbType;
	int32 QuickID = QbItem.QuickID;
	if (QbID)
	{
		//ɾ��QbItemList����
		QbItemLists[Page].Remove(QbItem);

		//��ɾ����SkillID��������ϲ����ڵģ�ɾ��һ�ݶ�ӦSkillData����
		UUECS3GameInstance::Instance->SkillManager->RemoveTotalSkillData(QbID);

		//֪ͨ����ָ��������������ɾ�������QbItem��ָ�������������ָ��
		UGolbalBPFunctionLibrary::TutorialManager()->OnRemoveQBItem(QbID);

		//��Я����
		if (QuickID != 0 && QbItem.QuickType == QUICK_SKILL_TYPE::QUICK_SKILL_TYPE_STAGE)
		{
			//�ѿ�ʼ��Я����Ҫ����
			if (QbItem.CurrStage != 0)
			{
				RemoveStageQbItems.Add(QuickID, QbItem);
			}
			UpdateQuickSkillHoldTime();
		}
	}

	//֪ͨ����
	if (IsNeedUpdateQuickBar(Page) && IsValid(UUECS3GameInstance::Instance) && IsValid(UUECS3GameInstance::Instance->GEventManager))
	{
		if (Index < UUECS3GameInstance::Instance->ConstDataBP->QB_IDX_ROLE_ADDITIONAL_SHORTCUT_BAR_1)
		{
			//�������
			UUECS3GameInstance::Instance->GEventManager->OnRemoveQBItemEvent.Broadcast(Index);
		}
		else
		{
			//�������
			UUECS3GameInstance::Instance->GEventManager->OnRemoveMoreQBItemEvent.Broadcast(Index);
		}
	}
}

TArray<FQB_ITEM> UQuickBarManager::GetReplaceQbItemList()
{
	return ReplaceQbItemList;
}

int32 UQuickBarManager::GetReplaceQBItemLen()
{
	return ReplaceQbItemList.Num();
}

void UQuickBarManager::AddReplaceQBItem(int32 Index, int32 QbType, int32 Id, int32 BindType, int32 QuickID, FString PetUid)
{
	for (auto item : ReplaceQbItemList)
	{
		if (item.QbID == Id)
		{
			return;
		}
	}
	FQB_ITEM item = InitQuickItem(Index, QbType, Id, BindType, QuickID, PetUid);
	ReplaceQbItemList.Add(item);

	//���¼ӵ�SkillID����һ�ݶ�ӦSkillData���ݲ�����
	UUECS3GameInstance::Instance->SkillManager->AddTotalSkillData(item.QbID);
}

void UQuickBarManager::RemoveReplaceQBItem()
{
	for (auto item : ReplaceQbItemList)
	{
		//��ɾ����SkillID��������ϲ����ڵģ�ɾ��һ�ݶ�ӦSkillData����
		UUECS3GameInstance::Instance->SkillManager->RemoveTotalSkillData(item.QbID);
	}
	ReplaceQbItemList.Empty();
}

void UQuickBarManager::SetIsReplaceQb(bool IsReplaceQb)
{
	IsReplace = IsReplaceQb;
}

void UQuickBarManager::OnPlaySkill(int32 SkillID)
{
	SwitchNextSkillStage(SkillID);
}

void UQuickBarManager::AddPassiveHoldEffectData(int32 QuickID, int32 PassiveSkillLevel, int32 SkillLevel)
{
	FSKILL_PASSIVE_HOLD_EFFECT_DATA HoldEffectData;
	HoldEffectData.QuickID = QuickID;
	if (!SkillPassiveHoldEffectDatas.Contains(QuickID))
	{
		HoldEffectData.PassiveSkillLevel = PassiveSkillLevel;
		HoldEffectData.SkillLevel = SkillLevel;
		SkillPassiveHoldEffectDatas.Add(QuickID, HoldEffectData);
	}
	else
	{
		//����
		FSKILL_PASSIVE_HOLD_EFFECT_DATA TempHoldEffectData = SkillPassiveHoldEffectDatas[QuickID];
		HoldEffectData.PassiveSkillLevel = TempHoldEffectData.PassiveSkillLevel + PassiveSkillLevel;
		HoldEffectData.SkillLevel = TempHoldEffectData.SkillLevel + SkillLevel;
		SkillPassiveHoldEffectDatas[QuickID] = HoldEffectData;
	}

	UpdateLevelSwitchSkillID(QuickID);
}

void UQuickBarManager::RemovePassiveHoldEffectData(int32 QuickID, int32 PassiveSkillLevel, int32 SkillLevel)
{
	if (SkillPassiveHoldEffectDatas.Contains(QuickID))
	{
		FSKILL_PASSIVE_HOLD_EFFECT_DATA TempHoldEffectData = SkillPassiveHoldEffectDatas[QuickID];
		FSKILL_PASSIVE_HOLD_EFFECT_DATA HoldEffectData;
		HoldEffectData.PassiveSkillLevel = TempHoldEffectData.PassiveSkillLevel - PassiveSkillLevel;
		HoldEffectData.SkillLevel = TempHoldEffectData.SkillLevel - SkillLevel;
		if (HoldEffectData.PassiveSkillLevel == 0 && HoldEffectData.SkillLevel == 0)
		{
			SkillPassiveHoldEffectDatas.Remove(QuickID);
		}
		else
		{
			SkillPassiveHoldEffectDatas[QuickID] = HoldEffectData;
		}
		UpdateLevelSwitchSkillID(QuickID);
	}
}

void UQuickBarManager::LoadCfg()
{
	QuickSkillTableData.Empty();
	if (!UGolbalBPFunctionLibrary::CfgManager())
	{
		CS3_Warning(TEXT("-->Null Pointer error:UQuickBarManager::LoadCfg : CfgManager()!"));
		return;
	}
	const UConfigTable* ConfigTable = UGolbalBPFunctionLibrary::CfgManager()->GetTableByType(CSV_CONFIG_TYPE_ENUM::CSV_CONFIG_QUICK_SKILL_DATA);
	if (!ConfigTable)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UQuickBarManager::LoadCfg : ConfigTable!"));
		return;
	}
	TArray<FName> Rows = ConfigTable->GetRowNames();
	if (Rows.Num() <= 0) return;
	for (FName& Row : Rows)
	{
		const FQUICKSKILL_CONFIG* Data = ConfigTable->GetRow<FQUICKSKILL_CONFIG>(Row);
		if (!Data)
		{
			CS3_Warning(TEXT("-->Null Pointer error:UQuickBarManager::LoadCfg : Data!"));
			continue;
		}
		if (QuickSkillTableData.Contains(Data->QuickID))
		{
			CS3_Warning(TEXT("QuickSkillCfg Table has two same QuickID[%s]"), *(INT_TO_FSTRING(Data->QuickID)));
			continue;
		}
		FQUICKSKILL_CONFIG* TempData = const_cast<FQUICKSKILL_CONFIG*>(Data);
		//���뵽��������
		QuickSkillTableData.Add(Data->QuickID);
		QuickSkillTableData[Data->QuickID] = *TempData;
	}
}

bool UQuickBarManager::IsNeedUpdateQuickBar(int32 PosturePage)
{
	UQuickBarInterface* QuickBarInterface = Cast<UQuickBarInterface>(UGolbalBPFunctionLibrary::GetInterfaceByName(TEXT("QuickBarInterface"), 0));
	if (IsValid(QuickBarInterface))
	{
		int32 skillPosture = QuickBarInterface->GetSkillPosture();
		if (skillPosture == 0 && PosturePage == 0)
		{
			return true;
		}
		else if ((skillPosture % 100 - 1) == PosturePage)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void UQuickBarManager::OnUpdateQBItemUI(FQB_ITEM QBItem)
{
	//֪ͨ����
	if (IsValid(UUECS3GameInstance::Instance) && IsValid(UUECS3GameInstance::Instance->GEventManager))
	{
		if (QBItem.SlotIndex < UUECS3GameInstance::Instance->ConstDataBP->QB_IDX_ROLE_ADDITIONAL_SHORTCUT_BAR_1)
		{
			//�������
			UUECS3GameInstance::Instance->GEventManager->OnUpdateQBItemEvent.Broadcast(QBItem);
		}
		else
		{
			//�������
			UUECS3GameInstance::Instance->GEventManager->OnUpdateMoreQBItemEvent.Broadcast(QBItem);
		}
	}
}

FQB_ITEM UQuickBarManager::InitQuickItem(int32 Index, int32 QbType, int32 Id, int32 BindType, int32 QuickID, FString PetUid)
{
	FQB_ITEM item;
	item.SlotIndex = Index;
	item.QuickID = QuickID;
	item.QbID = Id;
	item.QbType = QbType;
	item.BindType = BindType;
	item.PetUid = PetUid;

	if (QuickID != 0)
	{
		//�л��������������������û�ȡID
		bool IsSuccess = false;
		FQUICKSKILL_CONFIG QuickData = GetQuickSkillCfgData(item.QuickID, IsSuccess);
		if (IsSuccess)
		{
			switch (QuickData.Type)
			{
			case 1:///<�ȼ��л�
			{
				item.QuickType = QUICK_SKILL_TYPE::QUICK_SKILL_TYPE_LEVEL;
				item.CurrQbID = GetLevelSwitchSkillID(QuickID, Id, QuickData.QuickSkillData);
				item.CurrStage = 0;
				item.RemainHoldTime = 0;
				item.TotalHoldTime = 0;
				return item;
			}
			case 2:///<��Я�л�
			{
				if (QuickData.QuickSkillData.Num() > 0)
				{
					item.QuickType = QUICK_SKILL_TYPE::QUICK_SKILL_TYPE_STAGE;
					item.TotalHoldTime = FSTRING_TO_INT(QuickData.QuickSkillData[0].Param1);
					if (RemoveStageQbItems.Contains(item.QuickID))
					{
						FQB_ITEM OldItem = RemoveStageQbItems[item.QuickID];
						item.CurrQbID = OldItem.CurrQbID;
						item.CurrStage = OldItem.CurrStage;
						item.RemainHoldTime = OldItem.RemainHoldTime;
					}
					else
					{
						item.CurrQbID = FSTRING_TO_INT(QuickData.QuickSkillData[0].SkillID);
						item.CurrStage = 0;
						item.RemainHoldTime = item.TotalHoldTime;
					}
					return item;
				}
			}
			}
		}
	}
	item.QuickType = QUICK_SKILL_TYPE::QUICK_SKILL_TYPE_NORMAL;
	item.CurrQbID = Id;
	item.CurrStage = 0;
	item.RemainHoldTime = 0;
	item.TotalHoldTime = 0;
	return item;
}

FQUICKSKILL_CONFIG UQuickBarManager::GetQuickSkillCfgData(int32 QuickID, bool& IsSuccess)
{
	if (QuickSkillTableData.Contains(QuickID))
	{
		IsSuccess = true;
		return QuickSkillTableData[QuickID];
	}
	IsSuccess = false;
	return FQUICKSKILL_CONFIG();
}

int32 UQuickBarManager::GetLevelSwitchSkillID(int32 QuickID, int32 SkillID, TArray<FQUICKSKIL_SWITCH_DATA> QuickSkillData)
{
	int32 SkillLevel = UUECS3GameInstance::Instance->SkillManager->GetSkillDataById(SkillID)->GetSkillLevel();
	int32 PassiveSkillLevel = 0;//Ĭ��0
	int32 AddSkillLevel;
	int32 AddPassiveSkillLevel;
	GetPassiveHoldEffect(QuickID, AddPassiveSkillLevel, AddSkillLevel);
	//SkillLevel = SkillLevel+����Ч���ȼ���PassiveSkillLevel = PassiveSkillLevel+����Ч���ȼ�
	SkillLevel = SkillLevel + AddSkillLevel;
	PassiveSkillLevel = PassiveSkillLevel + AddPassiveSkillLevel;

	for (FQUICKSKIL_SWITCH_DATA Data : QuickSkillData)
	{
		if (FSTRING_TO_INT(Data.Param1) == SkillLevel && FSTRING_TO_INT(Data.Param2) == PassiveSkillLevel)
		{
			return FSTRING_TO_INT(Data.SkillID);
		}
	}
	return SkillID;
}

void UQuickBarManager::GetPassiveHoldEffect(int32 QuickID, int32& PassiveSkillLevel, int32& SkillLevel)
{
	if (SkillPassiveHoldEffectDatas.Contains(QuickID))
	{
		PassiveSkillLevel = SkillPassiveHoldEffectDatas[QuickID].PassiveSkillLevel;
		SkillLevel = SkillPassiveHoldEffectDatas[QuickID].SkillLevel;
	}
	else
	{
		PassiveSkillLevel = 0;
		SkillLevel = 0;
	}
}

void UQuickBarManager::UpdateLevelSwitchSkillID(int32 QuickID)
{
	for (TPair<int32, TArray<FQB_ITEM>>& Data : QbItemLists)
	{
		if (IsNeedUpdateQuickBar(Data.Key))
		{
			for (FQB_ITEM& Item : Data.Value)
			{
				if (Item.QuickID == QuickID)
				{
					bool IsSuccess = false;
					FQUICKSKILL_CONFIG QuickData = GetQuickSkillCfgData(Item.QuickID, IsSuccess);
					if (IsSuccess)
					{
						if (QuickData.Type == 1)	//�ȼ��л�
						{
							//��ɾ����SkillID��������ϲ����ڵģ�ɾ��һ�ݶ�ӦSkillData����
							UUECS3GameInstance::Instance->SkillManager->RemoveTotalSkillData(Item.CurrQbID);
							Item.CurrQbID = GetLevelSwitchSkillID(QuickID, Item.QbID, QuickData.QuickSkillData);
							//���¼ӵ�SkillID����һ�ݶ�ӦSkillData���ݲ�����
							UUECS3GameInstance::Instance->SkillManager->AddTotalSkillData(Item.CurrQbID);
							//ˢ�½���
							OnUpdateQBItemUI(Item);
						}
					}
					return;
				}
			}
		}
	}
}

bool UQuickBarManager::HasStageSkill()
{
	TArray<FQB_ITEM> QbItems = GetQbItemList();
	for (FQB_ITEM Item : QbItems)
	{
		if (Item.QuickType == QUICK_SKILL_TYPE::QUICK_SKILL_TYPE_STAGE)
		{
			return true;
		}
	}
	return false;
}

void UQuickBarManager::UpdateQuickSkillHoldTime()
{
	if (HasStageSkill() || RemoveStageQbItems.Num() > 0)
	{
		if (!IsCoolDowning())
		{
			StartCdTimer();
		}
	}
	else
	{
		StopCdTimer();
	}
}

void UQuickBarManager::StartCdTimer()
{
	UUECS3GameInstance::Instance->CustomTimerManager->SetTimer(CdTimerHandle, this, &UQuickBarManager::SetCd, 1.0f, true);
	HasCD = true;
}

void UQuickBarManager::SetCd()
{
	if (!HasStageSkill() && RemoveStageQbItems.Num() == 0)
	{
		StopCdTimer();
		return;
	}
	//��鵱ǰ�ķ������еļ���
	for (TPair<int32, TArray<FQB_ITEM>>& Data : QbItemLists)
	{
		if (IsNeedUpdateQuickBar(Data.Key))
		{
			for (FQB_ITEM& Item : Data.Value)
			{
				if (Item.QuickType == QUICK_SKILL_TYPE::QUICK_SKILL_TYPE_STAGE && Item.TotalHoldTime != -1)
				{
					Item.RemainHoldTime = Item.RemainHoldTime - 1;
					if (Item.RemainHoldTime <= 0)
					{
						//��Я���ܳ���ʱ���ѹ������ص�һ�׶μ���
						bool IsSuccess = false;
						FQUICKSKILL_CONFIG QuickData = GetQuickSkillCfgData(Item.QuickID, IsSuccess);
						if (IsSuccess && QuickData.QuickSkillData.Num() > 0)
						{
							Item.CurrStage = 0;
							Item.CurrQbID = FSTRING_TO_INT(QuickData.QuickSkillData[0].SkillID);
							Item.TotalHoldTime = FSTRING_TO_INT(QuickData.QuickSkillData[0].Param1);
							Item.RemainHoldTime = Item.TotalHoldTime;

							//���¼ӵ�SkillID����һ�ݶ�ӦSkillData���ݲ�����
							UUECS3GameInstance::Instance->SkillManager->AddTotalSkillData(Item.CurrQbID);
							//ˢ�½���
							OnUpdateQBItemUI(Item);
						}
					}
				}
			}
		}
	}
	
	//�Ѵӿ�����Ƴ�������Я�еļ���
	for (TMap<int32, FQB_ITEM>::TConstIterator aiter = RemoveStageQbItems.CreateConstIterator(); aiter; ++aiter)
	{
		if (aiter.Value().TotalHoldTime != -1)
		{
			RemoveStageQbItems[aiter.Key()].RemainHoldTime = aiter.Value().RemainHoldTime - 1;
			if (aiter.Value().RemainHoldTime <= 0)
			{
				//��Я���ܳ���ʱ���ѹ���ɾ��
				RemoveStageQbItems.Remove(aiter.Key());
			}
		}
	}
}

void UQuickBarManager::StopCdTimer()
{
	if (CdTimerHandle.IsValid())
	{
		UUECS3GameInstance::Instance->CustomTimerManager->ClearTimer(CdTimerHandle);
	}
	HasCD = false;
}

bool UQuickBarManager::IsCoolDowning()
{
	return HasCD;
}

void UQuickBarManager::SwitchNextSkillStage(int32 SkillID)
{
	if (!HasStageSkill())
	{
		//��ǰû����Я�����򲻴���
		return;
	}
	for (TPair<int32, TArray<FQB_ITEM>>& Data : QbItemLists)
	{
		if (IsNeedUpdateQuickBar(Data.Key))
		{
			for (FQB_ITEM& Item : Data.Value)
			{
				if (Item.CurrQbID == SkillID && Item.QuickType == QUICK_SKILL_TYPE::QUICK_SKILL_TYPE_STAGE)
				{
					bool IsSuccess = false;
					FQUICKSKILL_CONFIG QuickData = GetQuickSkillCfgData(Item.QuickID, IsSuccess);
					//��Я����
					if (IsSuccess && QuickData.QuickSkillData.Num() > 0)
					{
						//��ɾ����SkillID��������ϲ����ڵģ�ɾ��һ�ݶ�ӦSkillData����
						UUECS3GameInstance::Instance->SkillManager->RemoveTotalSkillData(Item.CurrQbID);

						//��һ�׶Σ����û�к����׶Σ���ص���һ�׶�
						Item.CurrStage = Item.CurrStage + 1;
						if (QuickData.QuickSkillData.Num() > Item.CurrStage)
						{
							Item.CurrQbID = FSTRING_TO_INT(QuickData.QuickSkillData[Item.CurrStage].SkillID);
							Item.TotalHoldTime = FSTRING_TO_INT(QuickData.QuickSkillData[Item.CurrStage].Param1);
						}
						else
						{
							Item.CurrStage = 0;
							Item.CurrQbID = FSTRING_TO_INT(QuickData.QuickSkillData[0].SkillID);
							Item.TotalHoldTime = FSTRING_TO_INT(QuickData.QuickSkillData[0].Param1);
						}
						Item.RemainHoldTime = Item.TotalHoldTime;

						//���¼ӵ�SkillID����һ�ݶ�ӦSkillData���ݲ�����
						UUECS3GameInstance::Instance->SkillManager->AddTotalSkillData(Item.CurrQbID);
						//ˢ�½���
						OnUpdateQBItemUI(Item);
					}
					//����
					return;
				}
			}
		}
	}
}

CONTROL_COMPILE_OPTIMIZE_END