// Fill out your copyright notice in the Description page of Project Settings.


#include "CS3Base/UIManager.h"
// UE4
#include"Chuangshi.h"
#include "Platform.h"
#include "Algo/Reverse.h"
#include "WidgetBlueprintLibrary.h"
#include "SlateApplication.h"
// ��������
#include "GameData/StrToClass.h"
// CS3����
#include "CS3Base/BaseWindow.h"
#include "CS3Base/RootUIWidget.h"
#include "CS3Base/UIDockManager.h"
#include "CS3Base/UIFixerManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/EventManager.h"
#include "Manager/CustomCursorManager.h"
#include "Manager/StoryManager.h"
#include "Manager/MediaPlayerManager.h"
#include "Manager/SystemSwitchManager.h"
#include "Manager/GameStatus.h"
#include "GameDevelop/CS3PlayerController.h"
#include "Manager/TutorialManager.h"

CONTROL_COMPILE_OPTIMIZE_START
UGUIManager::UGUIManager()
{
}

UGUIManager::~UGUIManager()
{
	UIMaps.Empty();	
	UIVSMaps.Empty();
	AllWindows.Empty();
	AllVSWindows.Empty();
	BeforeHideVSWindows.Empty();
	HiddenVSWindows.Empty();
	CanShowWindowTypes.Empty();
	ConfigDataTable = nullptr;
	RootUIWidget = nullptr;
	CurrActWindow = nullptr;
}

UGUIManager* UGUIManager::GetInstance()
{
	cs3_checkNoReentry();

	return NewObject<UGUIManager>();
}

void UGUIManager::OpenWindowWithTabIndex(bool IsIgnoreGameStatus /*= true*/, EGameStatus GameStatus /*= EGameStatus::InWorld*/, FString WindowType /*= TEXT("")*/, FString ParentType /*= TEXT("")*/, int32 TabIndex /*= 0*/)
{
	//�ȴ򿪽���
	OpenWindow(IsIgnoreGameStatus, GameStatus, WindowType, ParentType);
	
	UBaseWindow* Window = GetWindow(WindowType);
	//�����Ƿ�����Ҵ�
	if (IsValid(Window) && Window->IsVisible())
	{
		//�򿪱�ǩҳ
		Window->OnOpenWindowWithTabIndex(TabIndex);
	}
}

/*
void UGUIManager::ClearInstanceData()
{
	Instance->UIMaps.Empty();	///<�������еĴ���
	Instance->UIVSMaps.Empty();	///<�������еĿɼ�����
	Instance->RootUIWidget = nullptr;
	Instance->AllWindows.Empty();
	Instance->AllVSWindows.Empty();
	Instance->BeforeHideVSWindows.Empty();
	Instance->HiddenVSWindows.Empty();///< ���������صĴ����б��������ctrl+G��ͷ����ʱ�������пɼ�����֮����Ҫ����ʾ�����Ľ��棩
	Instance->ConfigDataTable = nullptr;///<UI���ñ�
	Instance->CurrActWindow = nullptr;///<���浱ǰ����Ĵ���
}
*/

UBaseWindow* UGUIManager::CreateUIWindow(FString WindowType, bool IsMultiple /*= false*/)
{
	if (!IsMultiple)
	{
		UBaseWindow* Window = GetWindow(WindowType);
		if (Window)
		{
			return Window;
		}
	}
	return SynchronousCreateWindow(WindowType);
}

void UGUIManager::OpenWindow(bool IsIgnoreGameStatus /*= true*/, EGameStatus GameStatus /*= EGameStatus::InWorld*/, FString WindowType /*= TEXT("")*/, FString ParentType /*= TEXT("")*/)
{
	if (IsIgnoreGameStatus || (UUECS3GameInstance::Instance->GameStatus->GetCurrStatus() == GameStatus))
	{
		CSV_EVENT_GLOBAL(TEXT("OpenWindow %s"), *WindowType);
		UBaseWindow* Window = GetWindow(WindowType);
		if (!IsValid(Window))
		{
			//���治���ڣ�����һ��
			Window = SynchronousCreateWindow(WindowType);
		}
		if (!IsValid(Window))
		{
			CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::OpenWindow : Window is Null!"));
			return;
		}
		Window->Show(ParentType);
	}
	else
	{
		CS3_Warning(TEXT("-->error:UGUIManager::OpenWindow : GameStatus Is not match!"));
	}
}

void UGUIManager::AsyncOpenWindow(FOnOpenComplete EventBack, bool IsIgnoreGameStatus /*= false*/, EGameStatus GameStatus /*= EGameStatus::InWorld*/, 
	FString WindowType /*= TEXT("")*/, FString ParentType /*= TEXT("")*/)
{
	if (IsIgnoreGameStatus || (UUECS3GameInstance::Instance->GameStatus->GetCurrStatus() == GameStatus))
	{
		CSV_EVENT_GLOBAL(TEXT("AsyncOpenWindow %s"), *WindowType);
		UBaseWindow* Window = GetWindow(WindowType);
		if (!IsValid(Window))
		{
			//�첽����
			TWeakObjectPtr<UGUIManager> DelayThisPtr(this);
			AsyncLoadWindowAsset(FOnLoadComplete::CreateLambda([EventBack](FString WindowType, FString ParentType, UClass* WidgetClass, FUIConfigData* ConfigData, TWeakObjectPtr<UGUIManager> DelayThisPtr)
			{
				//UClass* WidgetClass = Cast<UClass>(ConfigData->Widget.Get());
				UBaseWindow* NewWindow = DelayThisPtr->CreateBaseWindow(WidgetClass, ConfigData);
				if (NewWindow)
				{
					NewWindow->Show(ParentType);
				}
				EventBack.ExecuteIfBound(WindowType);
			}), WindowType, ParentType);
		}
		else
		{
			Window->Show(ParentType);
			EventBack.ExecuteIfBound(WindowType);
		}
	}
	else
	{
		CS3_Warning(TEXT("-->error:UGUIManager::OpenWindow : GameStatus Is not match!"));
	}
}

void UGUIManager::UpdateWindow(bool IsIgnoreGameStatus, EGameStatus GameStatus, FString WindowType, bool RemoveWindowIfClose, FString ParentWindowType /*= TEXT("")*/)
{
	if (IsIgnoreGameStatus || (UUECS3GameInstance::Instance->GameStatus->GetCurrStatus() == GameStatus))
	{
		if (!UUECS3GameInstance::Instance->SystemSwitchManager->CheckOpenByWindowType(WindowType))
		{
			//ϵͳδ����
			return;
		}
		UBaseWindow* Window = GetWindow(WindowType);
		if (!IsValid(Window))
		{
			//���治���ڣ�����һ��
			Window = SynchronousCreateWindow(WindowType);
			if (!IsValid(Window))
			{
				CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::UpdateWindow : CreateWindow is Fail!"));
				return;
			}
			Window->Show(ParentWindowType);
		}
		else
		{
			if (Window->IsVisible())
			{
				if (RemoveWindowIfClose)
				{
					Window->Destroy();
				}
				else
				{
					Window->Hide();
				}
			}
			else
			{
				Window->Show(ParentWindowType);
			}
		}
	}
	else
	{
		CS3_Warning(TEXT("-->error:UGUIManager::UpdateWindow : GameStatus Is not match!"));
	}
}

UBaseWindow* UGUIManager::GetWindow(FString WindowType)
{
	if (WindowType == TEXT(""))
	{
		return nullptr;
	}
	//�������д���
	for (auto window : GetWindows())
	{
		if (WindowType == window->WindowType)
		{
			return window;
		}
	}
	return nullptr;
}

void UGUIManager::PreCreateWindows()
{
	//�����������ñ���LoadType�ֶ�Ϊ0�����н���
	if (!IsValid(ConfigDataTable))
	{
		InitUIConfigData();
	}
	if (ConfigDataTable)
	{
		for (auto data : ConfigDataTable->GetRowNames())
		{
			FUIConfigData* ConfigData = (FUIConfigData*)ConfigDataTable->FindRowUnchecked(*data.ToString());
			if (!ConfigData)
			{
				CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::PreCreateWindows : ConfigData!"));
				continue;
			}
			if (GetWindow(ConfigData->WinType) || ConfigData->LoadType == 0)
			{
				continue;
			}
			CS3_Display(CS3DebugType::CL_Undefined, TEXT("-->UGUIManager::PreCreateWindows name=%s"), *data.ToString());
			UClass* WidgetClass = ConfigData->Widget.Get();
			if (!IsValid(WidgetClass) && IsValid(UUECS3GameInstance::Instance) && IsValid(UUECS3GameInstance::Instance->ResourceManager))
			{
				//ͬ������
				WidgetClass = UUECS3GameInstance::Instance->ResourceManager->SynchronousLoadClass(ConfigData->Widget);
			}
			CreateBaseWindow(WidgetClass, ConfigData);
		}
	}
}

void UGUIManager::OnHideMouse()
{
	//ȡ����ק�¼�
	if (UWidgetBlueprintLibrary::IsDragDropping())
	{
		UWidgetBlueprintLibrary::CancelDragDrop();
	}
	//ȡ�������ϵ�����¼�
	if (UGolbalBPFunctionLibrary::GEventManager())
	{
		UGolbalBPFunctionLibrary::GEventManager()->OnCancelMouseEvent.Broadcast();
	}
	//��괦��
	if (UGolbalBPFunctionLibrary::CustomCursorManager())
	{
		UGolbalBPFunctionLibrary::CustomCursorManager()->OnHideMouse();
	}
}

void UGUIManager::OnRoleFirstEnterGame()
{
	//��ѡ�����ģʽ����
	UGolbalBPFunctionLibrary::GUIManager()->OpenWindow(false, EGameStatus::InWorld, TEXT("OperationTutorial"));
}

void UGUIManager::OnLeaveSpaceNotify()
{
	TArray<FString> NeedDestroy;
	NeedDestroy.Empty();
	for (TArray<UBaseWindow*>::TConstIterator aiter = AllWindows.CreateConstIterator(); aiter; ++aiter)
	{
		UBaseWindow* Window = *aiter;
		if (IsValid(Window))
		{
			FUIConfigData* ConfigData = GetUIConfigDataByWindowType(Window->WindowType);
			if (ConfigData)
			{
				switch (ConfigData->DestroyType)
				{
				case 0://����
				{
					//����������ֱ��Destroy��Destroy�����ٶ��󣬵������洢���Ա䶯�����洢�Ķ�������Ҳ������� ����ͨѭ������ɾ�� һ����BUG��ĳЩ����ز���
					NeedDestroy.Add(Window->WindowType);
					break;
				}
				case 1://����
				{
					Window->Hide();
					break;
				}
				default:
					break;
				}
			}
		}
	}

	//����
	for (auto WindowType : NeedDestroy)
	{
		UBaseWindow* Window = GetWindow(WindowType);
		if (IsValid(Window))
		{
			Window->Destroy();
		}
	}
}

void UGUIManager::ShowRootUI()
{
	if (!RootUIWidget)
	{
		ACS3PlayerController* PlayerController = UGolbalBPFunctionLibrary::GetCS3PlayerController();
		if (!IsValid(PlayerController))
		{
			CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::ShowRootUI : PlayerController!"));
			return;
		}
		URootUIWidget* Widget = Cast<URootUIWidget>(CreateWidget<UUserWidget>(PlayerController, UGolbalBPFunctionLibrary::GetUClassByStr(TEXT("BP_RootUIWidget"))));
		RootUIWidget = Widget;
	}
	if (RootUIWidget && !RootUIWidget->IsInViewport())
	{
		RootUIWidget->AddToViewport(0);
	}
}

void UGUIManager::AddToRootUI(UBaseWindow* Window, FVector2D Position)
{
	if (RootUIWidget)
	{
		RootUIWidget->AddToRootUI(Window, Position);
	}
}

void UGUIManager::SetRootUIVisible(ESlateVisibility InVisibility)
{
	if (RootUIWidget)
	{
		RootUIWidget->SetRootUIVisible(InVisibility);
	}
}

void UGUIManager::AddWindowToManager(UBaseWindow* window, FString WindowType)
{
	if (WindowType == TEXT("")) return;
	int zseg = window->PosZSegment;
	window->WindowType = WindowType;
	if (!FindArrayByItem(window, GetWindows()))
	{
		if (!UIMaps.Contains(zseg))
		{
			UIMaps.Add(zseg, {});
		}
		UIMaps[zseg].Add(window);
		AllWindows.Add(window);
	}
	window->PosZ = UIMaps[zseg].Num();
	if (window->IsVisible())
	{
		AddVSWindow(window);
	}
}

void UGUIManager::RemoveWindowFromManager(UBaseWindow* window)
{
	if (FindArrayByItem(window, GetWindows()))
	{
		int zseg = window->PosZSegment;
		UIMaps[zseg].Remove(window);
	}
	RemoveVSWindow(window);
	if (IsActWindow(window))
	{
		ActiveTopWindow();
	}
	AllWindows.Remove(window);
	RemoveBeforeHideVSWindow(window);
	HiddenVSWindows.Remove(window);
}

bool UGUIManager::ActiveWindow(UBaseWindow* window, bool upgrade /*= true*/)
{
	if (!window)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::ActiveWindow : window!"));
		return false;
	}
	if (!window->IsVisible() || !window->bActivable || !FindArrayByItem(window, GetWindows()))
	{
		return false;
	}
	if (upgrade)
	{
		UpgradeWindow(window);
	}
	if (IsActWindow(window))
	{
		return true;
	}
	InactiveWindow();
	CurrActWindow = window;
	CurrActWindow->NativeOnAfterActived();
	return true;
}

bool UGUIManager::InactiveWindow(UBaseWindow* window /*= nullptr*/)
{
	if (!CurrActWindow)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::InactiveWindow : CurrActWindow!"));
		return false;
	}
	if (!IsValid(window) || IsActWindow(window))
	{
		CurrActWindow = nullptr;
		return true;
	}
	return false;
}

void UGUIManager::UpgradeWindow(UBaseWindow* window)
{
	if (!window)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::UpgradeWindow : window!"));
		return;
	}
	int zseg = window->PosZSegment;
	if (!UIVSMaps.Contains(zseg)) return;
	TArray<UBaseWindow*> vsArr = UIVSMaps[zseg];
	Relayout(vsArr, window->PosZ);	// ��������ͬ�㴰�ڵĲ�ι�ϵ
	int count = vsArr.Num();
	window->PosZ = count;
	RefreshWindowsZOrder(zseg);
}

void UGUIManager::OnWindowShow(UBaseWindow* window)
{
	AddVSWindow(window);
	UpgradeWindow(window);
	if (window->bActivable)
	{
		ActiveWindow(window, false);
	}
}

void UGUIManager::OnWindowHide(UBaseWindow* window)
{
	RemoveVSWindow(window);
	if (IsActWindow(window))
	{
		ActiveTopWindow();
	}
}

void UGUIManager::OnWindowDestroy(UBaseWindow* window)
{
	//�ӹ�������ȥ��
	RemoveWindowFromManager(window);			
}

void UGUIManager::OnZSegmentChanged(UBaseWindow* window, int oldSeg, int newSeg)
{
	TArray<UBaseWindow*> wins = UIMaps[oldSeg];
	if (FindArrayByItem(window, GetWindows()))
	{
		wins.Remove(window);
		UIMaps[newSeg].Add(window);
	}
	wins = UIVSMaps[oldSeg];
	if (FindArrayByItem(window, GetVSWindows()))
	{
		wins.Remove(window);
		UIVSMaps[newSeg].Add(window);
	}
}

void UGUIManager::AddVSWindow(UBaseWindow* window)
{
	if (!FindArrayByItem(window, GetVSWindows()))
	{
		int zseg = window->PosZSegment;
		if (!UIVSMaps.Contains(zseg))
		{
			UIVSMaps.Add(zseg, {});
		}
		UIVSMaps[zseg].Add(window);
		AllVSWindows.Add(window);
	}
}

void UGUIManager::AddHiddenVSWindows(UBaseWindow* window)
{
	if(!HiddenVSWindows.Contains(window))
	{
		HiddenVSWindows.Add(window);
	}
}

void UGUIManager::SetCanShowWindowTypes(TArray<FString> WindowTypes)
{
	CanShowWindowTypes = WindowTypes;
}

void UGUIManager::ClearCanShowWindowTypes()
{
	CanShowWindowTypes.Empty();
}

TArray<FString> UGUIManager::GetCanShowWindowTypes()
{
	return CanShowWindowTypes;
}

void UGUIManager::RemoveVSWindow(UBaseWindow* window)
{
	if (FindArrayByItem(window, GetVSWindows()))
	{
		int zseg = window->PosZSegment;
		UIVSMaps[zseg].Remove(window);
		AllVSWindows.Remove(window);
	}
}

void UGUIManager::AddBeforeHideVSWindow(UBaseWindow* window)
{
	if (!HiddenVSWindows.Contains(window) && !BeforeHideVSWindows.Contains(window))
	{ 
		if (window && window->IsStoryHide())
		{
			BeforeHideVSWindows.Add(window);
		}
	}
}

void UGUIManager::RemoveBeforeHideVSWindow(UBaseWindow* window)
{
	if (BeforeHideVSWindows.Num() > 0 && BeforeHideVSWindows.Contains(window))
	{
		BeforeHideVSWindows.Remove(window);
	}	
}

void UGUIManager::ActiveTopWindow()
{
	UBaseWindow* window = nullptr;
	TArray<UBaseWindow*> winArr = GetVSWindows();
	for (int i = 0; i < winArr.Num(); i++)
	{
		//�ҳ���һ���ɱ�����Ĵ���
		if (winArr[i]->bActivable)
		{
			window = winArr[i];
			break;
		}
	}
	if (window)
	{
		ActiveWindow(window, true);
	}
	else
	{
		InactiveWindow();
	}
}

bool UGUIManager::OrderHideWindows()
{
	for (auto win : GetVSWindows())		//�������пɼ�����
	{
		if (win->bEscHide)				//����������� esc ������
		{
			win->OrderHide();				//�����ش���
			return true;				//�������سɹ�
		}
	}
	return false;						//�������ز��ɹ�
}

void UGUIManager::BeforeStatusChanged(EGameStatus oldStatus, EGameStatus newStatus)
{
	for (auto win : GetWindows())						//�������д���
	{
		win->BeforeStatusChanged(oldStatus, newStatus);//��״̬�ı�֪ͨ���д���
	}
}

void UGUIManager::AfterStatusChanged(EGameStatus oldStatus, EGameStatus newStatus)
{
	for (auto win : GetWindows())						//�������д���
	{
		win->AfterStatusChanged(oldStatus, newStatus);	//��״̬�ı�֪ͨ���д���
	}
}

void UGUIManager::OnRoleEnterWorld()
{
	//֪ͨλ�ù�����
	UUECS3GameInstance::Instance->UIFixerManager->OnRoleEnterWorld();
	//�������д���
	for (auto win : UGolbalBPFunctionLibrary::GUIManager()->GetWindows())
	{
		//֪ͨ����
		win->NativeOnEnterWorld();
	}
	//֪ͨ���ܿ���������
	UUECS3GameInstance::Instance->SystemSwitchManager->OnEnterWorld();
	//֪ͨ����ָ��������
	UUECS3GameInstance::Instance->TutorialManager->OnEnterWorld();
}

void UGUIManager::OnRoleLeaveWorld()
{
	if (UUECS3GameInstance::Instance->bIsShutDown)
	{
		return;
	}
	//�������д���
	for (auto win : GetWindows())						
	{
		//֪ͨ���д��ڽ�ɫ���뿪����
		win->NativeOnLeaveWorld();
		if (win->WindowType != TEXT("SwitchScene"))
		{
			if (win->IsVisible())
			{
				//���ش���(���������ڳ���)
				win->Hide();								
			}
		}									
	}
	BeforeHideVSWindows.Empty();
	CanShowWindowTypes.Empty();
	//֪ͨ���ܿ���������
	UUECS3GameInstance::Instance->SystemSwitchManager->OnLeaveWorld();
	//֪ͨ����ָ��������
	UUECS3GameInstance::Instance->TutorialManager->OnLeaveWorld();
}

TArray<UBaseWindow*> UGUIManager::GetWindows()
{
	return AllWindows;
}

TArray<UBaseWindow*> UGUIManager::GetVSWindows()
{
	SortVSWindows();
	
	return AllVSWindows;
}

UBaseWindow* UGUIManager::GetActWindow()
{
	return CurrActWindow;
}

/*
TMap<int, TArray<UBaseWindow*> > UGUIManager::GetWindowsTree(UBaseWindow* window)
{
	UBaseWindow* owner = window;
	while (true)
	{
		if (!owner->WndParent) break;
		owner = owner->WndParent;
	}
	TMap<int, TArray<UBaseWindow*> > wnds = GetSubWindows(owner, window);
	float zseg = owner->PosZSegment;
	if (!wnds.Contains(zseg))
	{
		wnds.Add(zseg, {});
	}
	wnds[zseg].Add(owner);
	return wnds;
}

TMap<int, TArray<UBaseWindow*> > UGUIManager::GetSubWindows(UBaseWindow* parent, UBaseWindow* window)
{
	TMap<int, TArray<UBaseWindow*> > wnds = {};
	TArray<UBaseWindow*> traveleds = {};					//��ʱ�����Ѿ������Ĵ���
	TArray<UBaseWindow*> stack;								//����һ����ʱջ
	stack.Push(parent);										//ָ��������ջ
	while (stack.Num() > 0)
	{
		UBaseWindow* topWin = stack.Top();					//��ȡջ������
		TArray<UBaseWindow*> subWindows = topWin->SubWindows;
		bool isTraveled = traveleds.Find(topWin) < 0 ? false : true;			//ջ���Ĵ����Ƿ������
		if (!isTraveled && subWindows.Num() > 0)			//���ջ���Ĵ��ڻ�û������
		{
			traveleds.Add(topWin);
			subWindows.Sort([](const UBaseWindow& win1, const UBaseWindow& win2) { return win1.PosZ > win2.PosZ; });//�� Z ������˳��������������ͬ�㴰��
			for (int i = 0; i < subWindows.Num(); i++)
			{
				if (subWindows[i]->WindowType == window->WindowType)
				{
					subWindows.Remove(window);
					subWindows.Add(window);					//��ָ���Ĵ��ڷŵ���ǰ��
					break;
				}
			}
			for (int i = 0; i < subWindows.Num(); i++)		//ѭ������ ָ������ �� ĳ�Ӵ��� ���Ӵ���
			{
				int zseg = subWindows[i]->PosZSegment;
				if (!wnds.Contains(zseg) || wnds[zseg].Find(subWindows[i]) == -1)//������Ӵ��ڲ����Ӵ����б���
				{
					stack.Push(subWindows[i]);				//����ջ
				}
			}
		}
		else if (topWin != parent && topWin->IsVisible())		//���ջ���Ĵ����Ѿ������������Ҳ�����ײ�Ĵ���
		{
			UBaseWindow* popWin = stack.Pop();
			int zseg = popWin->PosZSegment;
			TArray<UBaseWindow*> layerWindows = wnds[zseg];
			if (layerWindows.Num() > 0)
			{
				layerWindows.Add(popWin);				//�򽫸ô��ڳ�ջ����ӵ��Ӵ����б���
			}
			else
			{
				wnds.Add(zseg, {});
				wnds[zseg].Add(popWin);
			}
		}
		else
		{
			stack.Pop();									//��ջ
		}
	}
	return wnds;											//���ظ�����Ӵ����б�
}
*/
bool UGUIManager::FindArrayByItem(UBaseWindow* window, TArray<UBaseWindow*> winsArray)
{
	return winsArray.Find(window) < 0 ? false : true;
}

void UGUIManager::CheckApplicationActivation(bool bIsActive)
{
	if (!bIsActive)
	{
		//�����ǰ��focus
		FSlateApplication::Get().ClearKeyboardFocus(EFocusCause::SetDirectly);
	}
}

bool UGUIManager::IsActWindow(UBaseWindow* window)
{
	if (!CurrActWindow || !window)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::IsActWindow : CurrActWindow||window!"));
		return false;
	}
	if (window == CurrActWindow)
	{
		return true;
	}
	return false;
}

void UGUIManager::HideVSWindows()
{
	for (auto win : GetVSWindows())
	{
		win->Hide();
	}
}

void UGUIManager::HideOrShowVSWindows(bool bHide)
{	
	if (bHide)
	{
		if (BeforeHideVSWindows.Num() == 0)
		{
			TArray<UBaseWindow*> TempVSWindows = GetVSWindows();
			for (auto win : TempVSWindows)
			{
				AddBeforeHideVSWindow(win);
				win->StoryHide();
			}
		}
	}
	else
	{
		if (!bIsHideAllUI && BeforeHideVSWindows.Num() > 0)
		{
			Algo::Reverse(BeforeHideVSWindows);
			for (auto win : BeforeHideVSWindows )
			{
				win->Show(win->LastParentWindowType);
			}
			BeforeHideVSWindows.Empty();
		}
	}
}

void UGUIManager::SetIsHideAllUI(bool bIsHide)
{
	bIsHideAllUI = bIsHide;
}

bool UGUIManager::GetIsHideAllUI()
{
	return bIsHideAllUI;
}

bool UGUIManager::IsCanShowWindowState()
{
	//�������н���״̬
	if (bIsHideAllUI)
	{
		return false;
	}
	//���������ؽ���
	if (UGolbalBPFunctionLibrary::GStoryManager() && UGolbalBPFunctionLibrary::GStoryManager()->IsNeedHideUI())
	{
		return false;
	}
	//��Ƶý�������ؽ���
	if (UGolbalBPFunctionLibrary::MediaPlayerManager() && UGolbalBPFunctionLibrary::MediaPlayerManager()->IsNeedHideUI())
	{
		return false;
	}
	return true;
}

bool UGUIManager::IsShowVSWindows()
{
	if (bIsHideAllUI)
	{
		return false;
	}
	if (BeforeHideVSWindows.Num() > 0)
	{
		return false;
	}
	return true;
}

void UGUIManager::InitUIConfigData()
{
	auto CfgManager = UUECS3GameInstance::Instance->CfgManager;
	ConfigDataTable = CfgManager->GetTableByType(CSV_CONFIG_TYPE_ENUM::CSV_CONFIG_TYPE_UI)->GetBaseTable();
}

FUIConfigData* UGUIManager::GetUIConfigDataByWindowType(FString WindowType)
{
	if (!IsValid(ConfigDataTable))
	{
		InitUIConfigData();
	}
	if (ConfigDataTable)
	{
		for (auto data : ConfigDataTable->GetRowNames())
		{
			FUIConfigData* configData = (FUIConfigData*)ConfigDataTable->FindRowUnchecked(*data.ToString());
			if (WindowType == configData->WinType)
			{
				return configData;
			}
		}
	}
	return nullptr;
}

UBaseWindow* UGUIManager::SynchronousCreateWindow(FString WindowType)
{
	FUIConfigData* ConfigData = GetUIConfigDataByWindowType(WindowType);
	if (ConfigData)
	{
		UClass* WidgetClass = ConfigData->Widget.Get();
		if (!IsValid(WidgetClass) && IsValid(UUECS3GameInstance::Instance) && IsValid(UUECS3GameInstance::Instance->ResourceManager))
		{
			//ͬ������
			WidgetClass = UUECS3GameInstance::Instance->ResourceManager->SynchronousLoadClass(ConfigData->Widget);
		}
		if (!IsValid(WidgetClass))
		{
			CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::SynchronousCreateWindow : Load WindowClass Fail!"));
			return nullptr;
		}
		return CreateBaseWindow(WidgetClass, ConfigData);
	}
	else
	{
		CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::SynchronousCreateWindow : ConfigData!"));
	}
	return nullptr;
}

UBaseWindow* UGUIManager::CreateBaseWindow(UClass* WidgetClass, FUIConfigData* ConfigData)
{
	if (!IsValid(WidgetClass) || ConfigData == nullptr)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::CreateBaseWindow : Load WindowClass Fail!"));
		return nullptr;
	}
	ACS3PlayerController* PlayerController = UGolbalBPFunctionLibrary::GetCS3PlayerController();
	if (!IsValid(PlayerController))
	{
		CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::CreateBaseWindow : PlayerController!"));
		return nullptr;
	}
	UBaseWindow* NewWindow = Cast<UBaseWindow>(CreateWidget<UUserWidget>(PlayerController, WidgetClass));
	if (IsValid(NewWindow))
	{
		NewWindow->InitConfigData(*ConfigData);
		//��ӵ�������
		AddWindowToManager(NewWindow, NewWindow->WindowType);
		//��Ϊ������Ƶ��������������ƣ�������Ƶ������Ƚ����⣬������Ҫadd��RootUI�ϣ����ų������������Ż���������Ƶ����������
		if (NewWindow->WindowType != TEXT("ChatChild"))
		{
			//��ӵ�RootUI����Ҫ�Ƚ�����add�����ڵ��ϣ��Զ�������ã������ʼ����������
			AddToRootUI(NewWindow, FVector2D::ZeroVector);
		}
		//�����ʼ��
		NewWindow->Init();
		if (NewWindow->WindowType != TEXT("ChatChild"))
		{
			//��������
			NewWindow->SetVisibility(ESlateVisibility::Collapsed);
		}
		//֪ͨ����ͣ��������
		if (UUECS3GameInstance::Instance->UIDockManager)
		{
			UUECS3GameInstance::Instance->UIDockManager->OnWindowCreatedOver(NewWindow->WindowType);
		}
	}
	return NewWindow;
}

void UGUIManager::AsyncLoadWindowAsset(FOnLoadComplete DelegateToCall, FString WindowType, FString ParentType /*= TEXT("")*/)
{
	//�첽����
	FUIConfigData* ConfigData = GetUIConfigDataByWindowType(WindowType);
	if (!ConfigData)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UGUIManager::AsyncOpenWindow : ConfigData!"));
		return;
	}
	TWeakObjectPtr<UGUIManager> DelayThisPtr(this);
	if (!IsValid(ConfigData->Widget.Get()))
	{
		TArray<FSoftObjectPath> TargetsToStream;
		TargetsToStream.AddUnique(ConfigData->Widget.ToSoftObjectPath());
		if (IsValid(UUECS3GameInstance::Instance) && IsValid(UUECS3GameInstance::Instance->ResourceManager))
		{
			UUECS3GameInstance::Instance->ResourceManager->RequestAsyncLoad(this, TargetsToStream,
				FStreamableDelegate::CreateLambda([DelayThisPtr, WindowType, ParentType, ConfigData, TargetsToStream, DelegateToCall]()
			{
				TArray<UObject *> LoadedResourceArray;
				for (int32 i = 0; i < TargetsToStream.Num(); i++)
				{
					FStringAssetReference AssetReference = TargetsToStream[i];
					UObject* NewObject = AssetReference.ResolveObject();
					if (IsValid(NewObject))
					{
						LoadedResourceArray.AddUnique(NewObject);
					}
				}
				UClass* WidgetClass = Cast<UClass>(LoadedResourceArray[0]);
				if (DelegateToCall.IsBound())
				{
					DelegateToCall.Execute(WindowType, ParentType, WidgetClass, ConfigData, DelayThisPtr);
				}
			}), RESOURCE_LOAD_PRIORITY_TYPE::RESOURCE_LOAD_PRIORITY_TYPE_DEFAULT);
		}
	}
	else if (DelegateToCall.IsBound())
	{
		UClass* WidgetClass = Cast<UClass>(ConfigData->Widget.Get());
		DelegateToCall.Execute(WindowType, ParentType, WidgetClass, ConfigData, DelayThisPtr);
	}
}

void UGUIManager::Relayout(TArray<UBaseWindow*> windows, int oldZOrder)
{
	int count = windows.Num();
	if (count == 0) return;
	for (auto& item : windows)
	{
		if (item && item->PosZ > oldZOrder)
		{
			item->PosZ = item->PosZ - 1;
		}
	}
}

void UGUIManager::RefreshWindowsZOrder(int32 PosZSegment)
{
	if (RootUIWidget)
	{
		RootUIWidget->RefreshChildZOrder(PosZSegment);
	}
}

void UGUIManager::SortVSWindows()
{
	AllVSWindows.Sort([](const UBaseWindow& win1, const UBaseWindow& win2)
	{
		if (win1.PosZSegment == win2.PosZSegment)//ͬ��
		{
			return win1.PosZ > win2.PosZ;
		}
		else
		{
			return win1.PosZSegment > win2.PosZSegment;
		}
	});
}
CONTROL_COMPILE_OPTIMIZE_END
