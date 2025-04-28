#include "ActivityFunctionBarWidget.h"
#include "VerticalBoxSlot.h"
#include "../GameDevelop/CS3PlayerController.h"
#include "GameDevelop/CS3GameInstance.h"
#include "../Util/GolbalBPFunctionLibrary.h"
#include "GameData/UIConfigData.h"
#include "Util/ConvertUtil.h"
#include "Manager/SystemSwitchManager.h"

void UActivityFunctionBarWidget::NativeOnEnterWorld()
{
	Show();
	Super::NativeOnEnterWorld();
}

void UActivityFunctionBarWidget::NativeOnLeaveWorld()
{
	BtnRowBoxMap.Empty();
	BtnWidgetMap.Empty();
	BtnsVerticalBox->ClearChildren();
	Super::NativeOnLeaveWorld();
}

void UActivityFunctionBarWidget::AddActivitySystem(FName BtnTag, int32 RemainTime /*= 0*/)
{
	UActivityFuncBtnWidget* FuncBtnWidget = GetBtnWidgetByBtnTag(BtnTag);
	if (IsValid(FuncBtnWidget))
	{
		//�Ѿ������ϵͳICON
		//���µ���ʱ
		FuncBtnWidget->SetCountDown(RemainTime);
		return;
	}
	bool IsSuccess;
	FFunctionBtnData BtnData = UUECS3GameInstance::Instance->SystemSwitchManager->GetBtnCfgByBtnTag(BtnTag, IsSuccess);
	if (!IsSuccess)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UActivityFunctionBarWidget::AddActivitySystem : BtnData!"));
		return;
	}
	ACS3PlayerController* PlayerController = UGolbalBPFunctionLibrary::GetCS3PlayerController();
	if (!IsValid(PlayerController)) return;
	UActivityFuncBtnWidget* IconWidget = CreateWidget<UActivityFuncBtnWidget>(PlayerController, UGolbalBPFunctionLibrary::GetUClassByStr(TEXT("BP_ActivityFuncBtnWidget")));
	if (!IsValid(IconWidget)) return;

	TArray<FString> SplitArray = UGolbalBPFunctionLibrary::SplitString(BtnData.BtnPosition, false, "|");
	int32 Row = 0;
	int32 InPriority = 0;
	if (SplitArray.Num() == 2)
	{
		Row = FSTRING_TO_INT(SplitArray[0]);
		InPriority = FSTRING_TO_INT(SplitArray[1]);
	}
	//����BtnWidgetMap
	if (!BtnWidgetMap.Contains(Row))
	{
		FBtnArray Btns;
		BtnWidgetMap.Add(Row, Btns);
	}
	BtnWidgetMap[Row].Btns.Add(IconWidget);
	//�Ƿ���Ҫ����һ��
	if (!BtnRowBoxMap.Contains(Row))
	{
		UHorizontalBox* BtnRowBox = NewObject<UHorizontalBox>();
		UVerticalBoxSlot* BoxSlot = Cast<UVerticalBoxSlot>(BtnsVerticalBox->AddChild(BtnRowBox));
		BoxSlot->SetHorizontalAlignment(HAlign_Right);
		BoxSlot->SetVerticalAlignment(VAlign_Top);

		BtnRowBoxMap.Add(Row);
		BtnRowBoxMap[Row] = BtnRowBox;
		//������
		LayoutRow(Row);
	}
	//Ҫ������֮ǰ�������ݣ���Ȼ������Ҫ�����ݲ���
	IconWidget->SetBtnInfo(BtnTag, InPriority, RemainTime);
	//�¼���ICON��ˢ��˳��
	LayoutSystem(Row);
	//ICON��ʾ��������Ч
	IconWidget->OpenActivity(BtnTag, InPriority);
}

void UActivityFunctionBarWidget::RemoveActivitySystem(FName BtnTag)
{
	bool IsSuccess;
	FFunctionBtnData BtnData = UUECS3GameInstance::Instance->SystemSwitchManager->GetBtnCfgByBtnTag(BtnTag, IsSuccess);
	if (!IsSuccess)
	{
		CS3_Warning(TEXT("-->Null Pointer error:RemoveActivitySystem::AddActivitySystem : BtnData!"));
		return;
	}
	TArray<FString> SplitArray = UGolbalBPFunctionLibrary::SplitString(BtnData.BtnPosition, false, "|");
	int Row = 0;
	if (SplitArray.Num() == 2)
	{
		Row = FSTRING_TO_INT(SplitArray[0]);
	}
	for (TPair<int32, FBtnArray>& Widgets : BtnWidgetMap)
	{
		for (UActivityFuncBtnWidget* BtnWidget : Widgets.Value.Btns)
		{
			if (BtnWidget->BtnTag == BtnTag)
			{
				//�Ƴ��ؼ�
				BtnRowBoxMap[Row]->RemoveChild(BtnWidget);
				//�Ƴ�����
				Widgets.Value.Btns.Remove(BtnWidget);
				return;
			}
		}
	}
}

int32 UActivityFunctionBarWidget::GetRemainTime(FName BtnTag)
{
	for (TPair<int32, FBtnArray>& Widgets : BtnWidgetMap)
	{
		for (UActivityFuncBtnWidget* BtnWidget : Widgets.Value.Btns)
		{
			if (BtnWidget->BtnTag == BtnTag)
			{
				return BtnWidget->RemainTime;
			}
		}
	}
	return 0;
}

void UActivityFunctionBarWidget::LayoutSystem(int32 Row)
{
	//�Ƴ���һ�����лICON
	BtnRowBoxMap[Row]->ClearChildren();
	//����
	BtnWidgetMap[Row].Btns.Sort([](const UActivityFuncBtnWidget& Widget1, const UActivityFuncBtnWidget& Widget2)
	{
		return Widget1.Priority > Widget2.Priority;
	});
	//�������ȫ���������
	for (UActivityFuncBtnWidget* Widget : BtnWidgetMap[Row].Btns)
	{
		BtnRowBoxMap[Row]->AddChild(Widget);
	}
}

void UActivityFunctionBarWidget::LayoutRow(int32 Row)
{
	//�ж�һ���Ƿ���Ҫ����
	bool IsNeedSort = false;
	for (TPair<int32, UHorizontalBox*>& BtnRowBox : BtnRowBoxMap)
	{
		if (BtnRowBox.Key > Row)
		{
			//����Ѿ��е��кű��¼ӵ�Ҫ������Ҫ����
			IsNeedSort = true;
			break;
		}
	}
	if (!IsNeedSort)
	{
		return;
	}
	//�Ƴ�������
	BtnsVerticalBox->ClearChildren();
	//����
	BtnRowBoxMap.KeySort(TLess<int32>());
	//�������
	for (TPair<int32, UHorizontalBox*>& BtnRowBox : BtnRowBoxMap)
	{
		BtnsVerticalBox->AddChild(BtnRowBox.Value);
	}
}

UActivityFuncBtnWidget* UActivityFunctionBarWidget::GetBtnWidgetByBtnTag(FName BtnTag)
{
	for (TPair<int32, FBtnArray>& Widgets : BtnWidgetMap)
	{
		for (UActivityFuncBtnWidget* BtnWidget : Widgets.Value.Btns)
		{
			if (BtnWidget->BtnTag == BtnTag)
			{
				return BtnWidget;
			}
		}
	}
	return nullptr;
}