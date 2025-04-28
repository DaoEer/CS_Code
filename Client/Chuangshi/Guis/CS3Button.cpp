#include "CS3Button.h"
#include "ButtonSlot.h"
#include "GameDevelop/CS3GameInstance.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "Util/CS3Debug.h"
#include "Manager/CustomCursorManager.h"
#include "Manager/TutorialManager.h"
#include "Manager/AudioManager.h"

CONTROL_COMPILE_OPTIMIZE_START

#pragma region /** SCS3Button */

FReply SCS3Button::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bool isEspecialCursorState = DealEspecialCursorState(MouseEvent);
	if(isEspecialCursorState) return FReply::Handled();
	//һ��Ҫ�ڼ��ָ��֮ǰ�����ָ���ᴥ����һ��
	FReply TempReply = SButton::OnMouseButtonDown(MyGeometry, MouseEvent);
	//������ָ��
	CheckFinishTutorial();
	return TempReply;
}

FReply SCS3Button::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return SButton::OnMouseButtonUp(MyGeometry, MouseEvent);
}

bool SCS3Button::DealEspecialCursorState(const FPointerEvent& MouseEvent)
{
	//������������״̬
	if (UGolbalBPFunctionLibrary::CustomCursorManager() && UGolbalBPFunctionLibrary::CustomCursorManager()->IsEspecialCursorState())
	{
		//�Ҽ�
		if (MouseEvent.IsMouseButtonDown(EKeys::RightMouseButton))
		{
			//�Ҽ��ָ����״̬
			UGolbalBPFunctionLibrary::CustomCursorManager()->ResetCursor();
			return true;
		}
		//���
		else if (MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
		{
			//��������Ч
			return true;
		}
	}
	return false;
}

void SCS3Button::CheckFinishTutorial()
{
	if (IsValid(UUECS3GameInstance::Instance) && IsValid(UUECS3GameInstance::Instance->TutorialManager))
	{
		UUECS3GameInstance::Instance->TutorialManager->OnTriggerItemClicked();
	}
}

#pragma endregion

#pragma region /** UCustomButton */
UCS3Button::UCS3Button(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

TSharedRef<SWidget> UCS3Button::RebuildWidget()
{
	TSharedPtr<SCS3Button> CS3Button = SNew(SCS3Button)
		.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleClicked))
		.OnPressed(BIND_UOBJECT_DELEGATE(FSimpleDelegate, CS3SlateHandlePressed))
		.OnReleased(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleReleased))
		.OnHovered_UObject(this, &ThisClass::CS3SlateHandleHovered)
		.OnUnhovered_UObject(this, &ThisClass::SlateHandleUnhovered)
		.ButtonStyle(&WidgetStyle)
		.ClickMethod(ClickMethod)
		.TouchMethod(TouchMethod)
		.IsFocusable(IsFocusable)
		;

	MyButton = CS3Button;

	if (GetChildrenCount() > 0) Cast<UButtonSlot>(GetContentSlot())->BuildSlot(MyButton.ToSharedRef());

	return MyButton.ToSharedRef();
}

void UCS3Button::CS3SlateHandlePressed()
{
	if (!PressedSoundID.IsEmpty() && IsValid(UUECS3GameInstance::Instance) && IsValid(UUECS3GameInstance::Instance->AudioManager))
	{
		UUECS3GameInstance::Instance->AudioManager->PlaySoundUI(PressedSoundID);
	}
	SlateHandlePressed();
}

void UCS3Button::CS3SlateHandleHovered()
{
	if (!HoveredSoundID.IsEmpty() && IsValid(UUECS3GameInstance::Instance) && IsValid(UUECS3GameInstance::Instance->AudioManager))
	{
		UUECS3GameInstance::Instance->AudioManager->PlaySoundUI(HoveredSoundID);
	}
	SlateHandleHovered();
}

#pragma endregion
CONTROL_COMPILE_OPTIMIZE_END
