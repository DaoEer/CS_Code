#include "ActivityFuncBtnWidget.h"
#include "../Util/GolbalBPFunctionLibrary.h"
#include "../GameDevelop/CS3GameInstance.h"
#include "Manager/CustomTimerManager.h"
#include "Manager/MessageManager.h"
#include "Manager/SystemSwitchManager.h"
#include "CS3Base/UIManager.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Util/CS3Debug.h"
#include "Util/ConvertUtil.h"

UActivityFuncBtnWidget::UActivityFuncBtnWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void UActivityFuncBtnWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (!FuncBtn->OnClicked.IsAlreadyBound(this, &UActivityFuncBtnWidget::OnClickedFuncBtn))
	{
		FuncBtn->OnClicked.AddDynamic(this, &UActivityFuncBtnWidget::OnClickedFuncBtn);
	}
}

void UActivityFuncBtnWidget::OpenActivity(FName InBtnTag, int32 InPriority)
{
	//�����ι�Ч���
	EffectImg->SetVisibility(ESlateVisibility::Collapsed);
	/*�����ι�Ч���
	//����ICON
	FuncBtn->SetVisibility(ESlateVisibility::Collapsed);
	//���ù�Ч
	FStringAssetReference refAsset(TEXT("MaterialInstanceConstant'/Game/BluePrints/UI/Materials/M_HightLightSlot_01_Inst.M_HightLightSlot_01_Inst'"));
	TArray<FSoftObjectPath> TargetsToStream;
	TargetsToStream.AddUnique(refAsset);
	TWeakObjectPtr<UImage> EffectImgThisPtr(EffectImg);
	UUECS3GameInstance::Instance->ResourceManager->RequestAsyncLoad(this, refAsset,
		FStreamableDelegate::CreateLambda([this, TargetsToStream, EffectImgThisPtr]()
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
		UMaterialInterface* EffectImgMaterial = Cast<UMaterialInterface>(LoadedResourceArray[0]);
		EffectImg->SetBrushFromMaterial(EffectImgMaterial);
		EffectImg->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		//��ʾ��Ч
		this->ShowOpenEffect();
	}), RESOURCE_LOAD_PRIORITY_TYPE::RESOURCE_LOAD_PRIORITY_TYPE_DEFAULT);
	*/
}

void UActivityFuncBtnWidget::SetCountDown(int32 InRemainTime)
{
	if (InRemainTime <= 0)
	{
		ClearCountDown();
	}
	else
	{
		TextPanel->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		RemainTime = InRemainTime;
		StartCountDown();
		if (IsValid(UUECS3GameInstance::Instance))
		{
			UUECS3GameInstance::Instance->CustomTimerManager->SetTimer(CountdownHandle, this, &UActivityFuncBtnWidget::StartCountDown, 1.0, true);
		}
	}
}

void UActivityFuncBtnWidget::SetBtnInfo(FName InBtnTag, int32 InPriority, int32 InRemainTime)
{
	BtnTag = InBtnTag;
	Priority = InPriority;
	bool IsSuccess;
	FFunctionBtnData BtnData = UUECS3GameInstance::Instance->SystemSwitchManager->GetBtnCfgByBtnTag(BtnTag, IsSuccess);
	if (!IsSuccess)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UActivityFuncBtnWidget::SetBtnInfo : BtnData!"));
		return;
	}
	WindowType = BtnData.WindowType;
	FButtonStyle BtnStyle = FuncBtn->WidgetStyle;
	UTexture2D* NormalTexture = Cast<UTexture2D>(UGolbalBPFunctionLibrary::LoadObjectByAssetPath(BtnData.NormalTexture));
	UTexture2D* HoveredTexture = Cast<UTexture2D>(UGolbalBPFunctionLibrary::LoadObjectByAssetPath(BtnData.HoveredTexture));
	UTexture2D* PressedTexture = Cast<UTexture2D>(UGolbalBPFunctionLibrary::LoadObjectByAssetPath(BtnData.PressedTexture));
	UTexture2D* DisableTexture = Cast<UTexture2D>(UGolbalBPFunctionLibrary::LoadObjectByAssetPath(BtnData.DisableTexture));

	BtnStyle.Normal.SetResourceObject(NormalTexture);
	BtnStyle.Normal.ImageSize = BtnData.Size;

	BtnStyle.Hovered.SetResourceObject(HoveredTexture);
	BtnStyle.Hovered.ImageSize = BtnData.Size;

	BtnStyle.Pressed.SetResourceObject(PressedTexture);
	BtnStyle.Pressed.ImageSize = BtnData.Size;

	BtnStyle.Disabled.SetResourceObject(DisableTexture);
	BtnStyle.Disabled.ImageSize = BtnData.Size;

	FuncBtn->SetStyle(BtnStyle);

	//���õ���ʱ
	SetCountDown(InRemainTime);
}

void UActivityFuncBtnWidget::ShowOpenEffect()
{
	PhaseValue = 0.0;
	PlayEffectTimer();
	
	if (IsValid(UUECS3GameInstance::Instance))
	{
		UUECS3GameInstance::Instance->CustomTimerManager->SetTimer(EffectHandle, this, &UActivityFuncBtnWidget::PlayEffectTimer, EffectTimer, true);
	}
}

void UActivityFuncBtnWidget::PlayEffectTimer()
{
	PhaseValue = PhaseValue + EffectTimer;
	if (PhaseValue >= 1.0 && !FuncBtn->IsVisible())
	{
		//��ʾICON
		FuncBtn->SetVisibility(ESlateVisibility::Visible);
	}
	//���ù�Ч֡
	if (EffectImg->GetDynamicMaterial())
	{
		EffectImg->GetDynamicMaterial()->SetScalarParameterValue(TEXT("Phase"), PhaseValue);
	}
}

void UActivityFuncBtnWidget::ClearOpenEffect()
{
	//�����ʱ��
	if (IsValid(UUECS3GameInstance::Instance))
	{
		UUECS3GameInstance::Instance->CustomTimerManager->ClearTimer(EffectHandle);
	}
	//���ù�Ч
	EffectImg->SetBrushFromMaterial(nullptr);
	EffectImg->SetVisibility(ESlateVisibility::Collapsed);
}

void UActivityFuncBtnWidget::StartCountDown()
{
	if (RemainTime <= 0)
	{
		ClearCountDown();
	}
	else
	{
		RemainTime = RemainTime - 1.0;
		FString TimeString = UGolbalBPFunctionLibrary::ConvertSecondsToHourColonModle(RemainTime);
		RemainTimeText->SetText(FSTRING_TO_FTEXT(TimeString));
	}
}

void UActivityFuncBtnWidget::ClearCountDown()
{
	RemainTime = 0;
	//�����ʱ��
	if (IsValid(UUECS3GameInstance::Instance))
	{
		UUECS3GameInstance::Instance->CustomTimerManager->ClearTimer(CountdownHandle);
	}
	//���߽�������ʱ������ʾ������ȡ��
	if (BtnTag == TEXT("OnlineReward"))
	{
		RemainTimeText->SetText(FSTRING_TO_FTEXT(UGolbalBPFunctionLibrary::GetChinese(TEXT("CanReceiveReward"))));
	}
	else
	{
		//����
		TextPanel->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UActivityFuncBtnWidget::OnClickedFuncBtn()
{
	//ɾ����Ч
	/*�����ι�Ч���
	ClearOpenEffect();
	*/
	//�򿪶�Ӧ�Ľ���
	if (WindowType == TEXT(""))
	{
		UUECS3GameInstance::Instance->MessageManager->ShowMessage(2901);
	}
	else
	{
		UGolbalBPFunctionLibrary::GUIManager()->UpdateWindow(false, EGameStatus::InWorld, WindowType, false);
	}
}