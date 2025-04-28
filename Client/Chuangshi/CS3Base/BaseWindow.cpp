// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWindow.h"
//UE4
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanelSlot.h"
#include "Runtime/Engine/Classes/Engine/UserInterfaceSettings.h"
//CS3
#include "GameDevelop/CS3GameInstance.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "CS3Base/RootUIWidget.h"
#include "CS3Base/UIManager.h"
#include "CS3Base/UIFixerManager.h"
#include "Manager/GameStatus.h"
#include "Manager/StoryManager.h"
#include "Manager/CustomCursorManager.h"
#include "Manager/SystemSwitchManager.h"
#include "Manager/TutorialManager.h"
#include "Util/CS3Debug.h"
#include "Interface/Role/RoleTradeInterface.h"
#include "Manager/MessageManager.h"
#include "Manager/MediaPlayerManager.h"

CONTROL_COMPILE_OPTIMIZE_START
UBaseWindow::UBaseWindow(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	H_DockStyle = EUIHDOCKSTYLE::CENTER;//Ĭ�ϴ��ھ�����ʾ
	V_DockStyle = EUIVDOCKSTYLE::MIDDLE;
	Left = 0;
	Top = 0;
	Center = 0;
	Middle = 0;
	Right = 0;
	Bottom = 0;

	R_Left = 0;
	R_Top = 0;
	R_Center = 0.5;
	R_Middle = 0.5;
	R_Right = 1;
	R_Bottom = 1;

	Pos.X = 0;
	Pos.Y = 0;

	PosZSegment = 0;
	PosZ = 0;
	bMoveable = true;
	bActivable = true;
	bHitable = true;
	bEscHide = true;
	
	ParentWindowType = TEXT("");
	LastParentWindowType = TEXT("");
	SubWindows.Empty();
}

UBaseWindow::~UBaseWindow()
{
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("UBaseWindow::~UBaseWindow is dispose------------------>>>"));
}

FReply UBaseWindow::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	//������������״̬������Ӧ
	if (UGolbalBPFunctionLibrary::CustomCursorManager() && UGolbalBPFunctionLibrary::CustomCursorManager()->IsEspecialCursorState())
	{
		return FReply::Handled();
	}
	//�������
	if (UGolbalBPFunctionLibrary::GUIManager())
	{
		UGolbalBPFunctionLibrary::GUIManager()->ActiveWindow(this);
	}
	//������ק
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		DragWindowOffest = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	}

	TSharedPtr<SWidget> CapturingSlateWidget = this->GetCachedWidget();
	if (CapturingSlateWidget.IsValid())
	{
		return FReply::Handled().CaptureMouse(CapturingSlateWidget.ToSharedRef());
	}
	else
	{
		return FReply::Handled();
	}
}

FReply UBaseWindow::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled().ReleaseMouseCapture();
}

FReply UBaseWindow::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled().ReleaseMouseCapture();
}

FReply UBaseWindow::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	// ��겶���� && �������ƶ� && ������
	if (HasMouseCapture() && bMoveable && InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton) && UGolbalBPFunctionLibrary::GUIManager() && UGolbalBPFunctionLibrary::GUIManager()->RootUIWidget)
	{
		FVector2D Offest = UGolbalBPFunctionLibrary::GUIManager()->RootUIWidget->GetCachedGeometry().AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
		SetPosition(Offest - DragWindowOffest);

		TSharedPtr<SWidget> CapturingSlateWidget = this->GetCachedWidget();
		if (CapturingSlateWidget.IsValid())
		{
			return FReply::Handled().CaptureMouse(CapturingSlateWidget.ToSharedRef());
		}
		else
		{
			return FReply::Handled();
		}
	}
	return FReply::Unhandled();
}

void UBaseWindow::NativeOnEnterWorld()
{
	OnEnterWorld();
}

void UBaseWindow::NativeOnLeaveWorld()
{
	OnLeaveWorld();
}

void UBaseWindow::NativeOnAfterActived()
{
	OnAfterActived();
}

bool UBaseWindow::OnClickDrop(const FDragDropOperationData& MouseCaptureData)
{
	return true;
}

bool UBaseWindow::IsCanShow(FString ParentType)
{
	if (!IsValid(UUECS3GameInstance::Instance) || !IsValid(UUECS3GameInstance::Instance->GameStatus) || !IsValid(UGolbalBPFunctionLibrary::GUIManager()))
	{
		return false;
	}
	//��Ƶ����һֱ��������
	if (WindowType.Equals(TEXT("CreateCG")))
	{
		return true;
	}
	//�Ƿ�������UI
	if (UUECS3GameInstance::Instance->GameStatus->GetCurrStatus() == EGameStatus::InWorld && UGolbalBPFunctionLibrary::GUIManager()->GetIsHideAllUI())
	{
		if (UGolbalBPFunctionLibrary::GUIManager()->GetIsHideAllUI())
		{
			LastParentWindowType = ParentType;
			UGolbalBPFunctionLibrary::GUIManager()->AddBeforeHideVSWindow(this);
		}
		return false;
	}
	//�ɴ򿪽����б������ݣ����ҵ�ǰ���治�ڿɴ򿪽����б���
	if (UGolbalBPFunctionLibrary::GUIManager()->GetCanShowWindowTypes().Num() > 0 && !UGolbalBPFunctionLibrary::GUIManager()->GetCanShowWindowTypes().Contains(WindowType))
	{
		return false;
	}
	//���ھ���״̬���������ϴ򿪽��棬��Ҫ��Ҫ�򿪵Ľ��汣�����������뿪����ʱ�ٴ�
	if (UGolbalBPFunctionLibrary::GStoryManager() && UGolbalBPFunctionLibrary::GStoryManager()->IsNeedHideUI())
	{
		if (IsStoryHide())
		{
			LastParentWindowType = ParentType;
			UGolbalBPFunctionLibrary::GUIManager()->AddBeforeHideVSWindow(this);
			return false;
		}
	}
	//������Ƶ״̬���������ϴ򿪽��棬��Ҫ��Ҫ�򿪵Ľ��汣������������Ƶ�����ٴ�
	if (UGolbalBPFunctionLibrary::MediaPlayerManager() && UGolbalBPFunctionLibrary::MediaPlayerManager()->IsNeedHideUI())
	{
		LastParentWindowType = ParentType;
		UGolbalBPFunctionLibrary::GUIManager()->AddBeforeHideVSWindow(this);
		return false;
	}
	//����״̬�У������Ҫ���ʼ����̵ꡢ�̳ǽ���ʱ��������ʾ������״̬�£��޷��򿪸ý��桱,ID 1421 
	URoleTradeInterface* TradeInterface = Cast<URoleTradeInterface>(UGolbalBPFunctionLibrary::GetInterfaceByName(TEXT("RoleTradeInterface"), 0));
	if (IsValid(TradeInterface) && TradeInterface->GetRoleTradeState() != TRADE_STATE::TRADE_STATE_NULL)
	{
		//���ʼ����̵ꡢ�̳ǽ���ʱ
		if (WindowType == TEXT("Mail")
			|| WindowType == TEXT("NPCShop")
			|| WindowType == TEXT("Mall"))
		{
			//��ʾ������״̬�£��޷��򿪸ý��桱, ID 1421
			UUECS3GameInstance::Instance->MessageManager->ShowMessage(1421);
			return false;
		}
	}
	return true;
}

bool UBaseWindow::IsStoryHide()
{
	if (WindowType != TEXT("SwitchScene")
		&& WindowType != TEXT("PortraitDialog")
		&& WindowType != TEXT("MonsterAIDialog")
		&& WindowType != TEXT("Story")
		&& WindowType != TEXT("StoryText")
		&& WindowType != TEXT("HaoLingGuQTE")
		&& WindowType != TEXT("CreateCG"))
	{
		return true;
	}
	return false;
}

void UBaseWindow::InitConfigData(FUIConfigData data)
{
	WindowType = data.WinType;
	PosZSegment = data.PosZSegment;
	bMoveable = data.IsMoveable;
	bActivable = data.IsActivable;
	bHitable = data.IsHitable;
	bEscHide = data.IsEscHide;

	H_DockStyle = data.H_DockStyle;
	V_DockStyle = data.V_DockStyle;
	Left = data.Left;
	Top = data.Top;
	Center = data.Center;
	Middle = data.Middle;
	Right = data.Right;
	Bottom = data.Bottom;

	R_Left = data.R_Left;
	R_Top = data.R_Top;
	R_Center = data.R_Center;
	R_Middle = data.R_Middle;
	R_Right = data.R_Right;
	R_Bottom = data.R_Bottom;
}

void UBaseWindow::Init()
{
	this->InitOnes();//��ͼ�����ʼ��
	if (UUECS3GameInstance::Instance)
	{
		if (UUECS3GameInstance::Instance->SystemSwitchManager)
		{
			UUECS3GameInstance::Instance->SystemSwitchManager->InitOpenStateByWindowType(WindowType);
		}
		if (UUECS3GameInstance::Instance->UIFixerManager)
		{
			UUECS3GameInstance::Instance->UIFixerManager->OnWindowInit(this);
		}
	}
}

void UBaseWindow::Show(FString ParentType /*= TEXT("")*/)
{
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("before UBaseWindow::Show name:%s"), *this->GetFullName());
	if (IsVisible()) return;
	if (!IsCanShow(ParentType)) return;
	if (OnBeforeShowBP()) return;
	
	//�򿪴���֮ǰ��Ҫ���Ĵ���
	this->OnBeforeShow();

	ParentWindowType = ParentType;
	LastParentWindowType = ParentWindowType;

	UBaseWindow* ParentWindow = UGolbalBPFunctionLibrary::GUIManager()->GetWindow(ParentWindowType);
	if (ParentWindow)
	{
		//��ӱ�����Ϊ�����ڵ��Ӵ���
		ParentWindow->AddSubWindow(this);
	}

	if (!IsVisible())
	{
		//��ʾ����
		SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
	//�򿪴���֮����Ҫ���Ĵ���
	this->OnAfterShowed();
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("end UBaseWindow::Show name:%s"), *this->GetFullName());
}

void UBaseWindow::Hide()
{
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("before UBaseWindow::Hide name:%s"),*this->GetFullName());
	if (!IsVisible())
	{
		//�����У����鿪ʼʱ�ر��˽��棬Ȼ�����������ϢҪ�رս��棨˵��������治��Ҫ�ڳ��������ˣ������ʱ����Ҫ��BeforeHideVSWindow�б��Ƴ�����
		UGolbalBPFunctionLibrary::GUIManager()->RemoveBeforeHideVSWindow(this);
		return;
	}
	bool IsSuccess = DoHide();
	if (IsSuccess)
	{
		UGolbalBPFunctionLibrary::GUIManager()->RemoveBeforeHideVSWindow(this);
	}
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("end UBaseWindow::Hide name:%s"), *this->GetFullName());
}

bool UBaseWindow::DoHide()
{
	if (OnBeforeHideBP())
	{
		return false;
	}

	//�ر�ǰ�Ĵ���
	this->OnBeforeClose();
	
	if (IsVisible())
	{
		//���ش���
		SetVisibility(ESlateVisibility::Collapsed);
	}

	//������سɹ�
	if (!IsVisible())
	{
		DoWindowTreeHide();
	}

	//�رպ�Ĵ���
	this->OnAfterClosed();
	return true;
}

void UBaseWindow::DoWindowTreeHide()
{
	UBaseWindow* ParentWindow = UGolbalBPFunctionLibrary::GUIManager()->GetWindow(ParentWindowType);
	if (ParentWindow)
	{
		//��Ӹ������б���������Լ�
		ParentWindow->RemoveSubWindow(this);
	}
	//���������Ӵ���
	for (int i = 0; i < SubWindows.Num(); i++)
	{
		SubWindows[i]->OnParentHide();
	}
	SubWindows.Empty();
}

void UBaseWindow::OrderHide()
{
	if (OnBeforeOrderHideBP()) return;
	if (OnBeforeHideBP()) return;

	//�ر�ǰ�Ĵ���
	this->OnBeforeClose();

	if (IsVisible())
	{
		//���ش���
		SetVisibility(ESlateVisibility::Collapsed);
	}

	//������سɹ�
	if (!IsVisible())
	{
		UBaseWindow* ParentWindow = UGolbalBPFunctionLibrary::GUIManager()->GetWindow(ParentWindowType);
		if (ParentWindow)
		{
			//��Ӹ������б���������Լ�
			ParentWindow->RemoveSubWindow(this);
		}
	}

	//�رպ�Ĵ���
	this->OnAfterClosed();
}

void UBaseWindow::StoryHide()
{
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("before UBaseWindow::StoryHide name:%s"), *this->GetFullName());
	if (!IsVisible())
	{
		return;
	}
	DoHide();
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("end UBaseWindow::StoryHide name:%s"), *this->GetFullName());
}

void UBaseWindow::Destroy()
{
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("before UBaseWindow::Destroy name:%s"), *this->GetFullName());
	if (OnBeforeDestroyBP()) return;

	//����ǰ�Ĵ���
	this->OnBeforeDestroy();
	
	DoWindowTreeHide();

	//����
	this->RemoveFromParent();
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("end UBaseWindow::Destroy name:%s"), *this->GetFullName());
}

void UBaseWindow::SetPosition(FVector2D InPosition)
{
	//��������ƶ�����Ļ������
	const FVector2D ViewportSize = UGolbalBPFunctionLibrary::GetViewportSize();
	const float ViewportScale = GetDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass())->GetDPIScaleBasedOnSize(FIntPoint(ViewportSize.X, ViewportSize.Y));
	if (InPosition.X < (-Size.X + 20))//���
	{
		InPosition.X = -Size.X + 20;
	}
	if (InPosition.X > (ViewportSize.X / ViewportScale - 20))//�ұ�
	{
		InPosition.X = ViewportSize.X / ViewportScale - 20;
	}
	if (InPosition.Y < (-Size.Y + 20))//�ϱ�
	{
		InPosition.Y = -Size.Y + 20;
	}
	if (InPosition.Y > (ViewportSize.Y / ViewportScale - 20))//�±�
	{
		InPosition.Y = ViewportSize.Y / ViewportScale - 20;
	}
	//����λ��
	Pos = InPosition;
	UCanvasPanelSlot* canvasPanelSlot = Cast<UCanvasPanelSlot>(UWidgetLayoutLibrary::SlotAsCanvasSlot(this));
	if (canvasPanelSlot)
	{
		canvasPanelSlot->SetPosition(Pos);
	}
}

void UBaseWindow::SetSize(FVector2D InSize)
{
	Size = InSize;
	UCanvasPanelSlot* canvasPanelSlot = Cast<UCanvasPanelSlot>(UWidgetLayoutLibrary::SlotAsCanvasSlot(this));
	if (canvasPanelSlot)
	{
		if (Size == FVector2D::ZeroVector)
		{
			CS3_Warning(TEXT("-->error:UBaseWindow::SetSize : %s WindowSize IsZero !"), *WindowType);
			canvasPanelSlot->SetAutoSize(true);
		}
		else
		{
			canvasPanelSlot->SetSize(Size);
		}
	}
}

void UBaseWindow::SetDockStyle(EUIHDOCKSTYLE InHDockStyle, EUIVDOCKSTYLE InVDockStyle)
{
	H_DockStyle = InHDockStyle;
	V_DockStyle = InVDockStyle;
	if (UUECS3GameInstance::Instance->UIFixerManager)
	{
		UUECS3GameInstance::Instance->UIFixerManager->UpdateDockStyle(this);
	}
}

void UBaseWindow::AddSubWindow(UBaseWindow* Window)
{
	if (SubWindows.Num() <= 0)
	{
		SubWindows.Add(Window);
	}
	else
	{
		bool isIn = SubWindows.Find(Window) < 0 ? false : true;
		if (!isIn)
		{
			SubWindows.Add(Window);
		}
	}
}

void UBaseWindow::RemoveSubWindow(UBaseWindow* Window)
{
	if (SubWindows.Num() <= 0)
	{
		return;
	}
	else
	{
		bool isIn = SubWindows.Find(Window) < 0 ? false : true;
		if (isIn)
		{
			SubWindows.Remove(Window);
		}
	}
}

void UBaseWindow::OnParentHide()
{
	Hide();
	ParentWindowType = TEXT("");
}

void UBaseWindow::OnBeforeShow()
{
	//���͹㲥�¼�
	OnBeforeShowDelegate.Broadcast(this);
}

void UBaseWindow::OnAfterShowed()
{
	if (UGolbalBPFunctionLibrary::GUIManager())
	{
		//���߹�������ʾ������
		UGolbalBPFunctionLibrary::GUIManager()->OnWindowShow(this);
	}
	OnAfterShowedBP();
	if (UGolbalBPFunctionLibrary::TutorialManager())
	{
		//��������ָ��
		UGolbalBPFunctionLibrary::TutorialManager()->OnOpenWindow(WindowType);
	}
}

void UBaseWindow::OnBeforeClose()
{
	if (UGolbalBPFunctionLibrary::GUIManager())
	{
		//���߹�������һ�� UI ����
		UGolbalBPFunctionLibrary::GUIManager()->OnWindowHide(this);
	}
}

void UBaseWindow::OnAfterClosed()
{
	OnAfterClosedDelegate.Broadcast(this);
	OnAfterHideBP();
}

void UBaseWindow::OnBeforeDestroy()
{
	if (UGolbalBPFunctionLibrary::GUIManager())
	{
		UGolbalBPFunctionLibrary::GUIManager()->OnWindowDestroy(this);
	}
}

void UBaseWindow::UpdatePosition()
{
	const FVector2D ViewportSize = UGolbalBPFunctionLibrary::GetViewportSize();
	const float ViewportScale = GetDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass())->GetDPIScaleBasedOnSize(FIntPoint(ViewportSize.X, ViewportSize.Y));
	FVector2D NewPos = Pos;
	//ˮƽ����
	if (H_DockStyle == EUIHDOCKSTYLE::LEFT)
	{
		NewPos.X = Left;
	}
	else if (H_DockStyle == EUIHDOCKSTYLE::CENTER)
	{
		NewPos.X = ViewportSize.X / ViewportScale * 0.5 - Size.X * 0.5 + Center;
	}
	else if (H_DockStyle == EUIHDOCKSTYLE::RIGHT)
	{
		NewPos.X = ViewportSize.X / ViewportScale - Size.X - Right;
	}
	else if (H_DockStyle == EUIHDOCKSTYLE::S_LEFT)
	{
		NewPos.X = ViewportSize.X / ViewportScale * R_Left;
	}
	else if (H_DockStyle == EUIHDOCKSTYLE::S_CENTER)
	{
		NewPos.X = ViewportSize.X / ViewportScale * R_Center - Size.X * 0.5;
	}
	else if (H_DockStyle == EUIHDOCKSTYLE::S_RIGHT)
	{
		NewPos.X = ViewportSize.X / ViewportScale * R_Right - Size.X;
	}
	else if (H_DockStyle == EUIHDOCKSTYLE::HFILL)
	{
		NewPos.X = 0;
	}
	//��ֱ����
	if (V_DockStyle == EUIVDOCKSTYLE::TOP)
	{
		NewPos.Y = Top;
	}
	else if (V_DockStyle == EUIVDOCKSTYLE::MIDDLE)
	{
		NewPos.Y = ViewportSize.Y / ViewportScale * 0.5 - Size.Y * 0.5 + Middle;
	}
	else if (V_DockStyle == EUIVDOCKSTYLE::BOTTOM)
	{
		NewPos.Y = ViewportSize.Y / ViewportScale - Size.Y - Bottom;
	}
	else if (V_DockStyle == EUIVDOCKSTYLE::S_TOP)
	{
		NewPos.Y = ViewportSize.Y / ViewportScale * R_Top;
	}
	else if (V_DockStyle == EUIVDOCKSTYLE::S_MIDDLE)
	{
		NewPos.Y = ViewportSize.Y / ViewportScale * R_Middle - Size.Y * 0.5;
	}
	else if (V_DockStyle == EUIVDOCKSTYLE::S_BOTTOM)
	{
		NewPos.Y = ViewportSize.Y / ViewportScale * R_Bottom - Size.Y;
	}
	else if (V_DockStyle == EUIVDOCKSTYLE::VFILL)
	{
		NewPos.Y = 0;
	}
	SetPosition(NewPos);
}

CONTROL_COMPILE_OPTIMIZE_END
