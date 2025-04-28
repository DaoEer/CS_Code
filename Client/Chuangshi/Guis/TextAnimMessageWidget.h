#pragma once

#include "Blueprint/UserWidget.h"
#include "Image.h"
#include "CS3Base/CS3UserWidget.h"
#include "GameData/MessageData.h"
#include "CS3Base/BaseWindow.h"
#include "TextAnimMessageWidget.generated.h"



/*
* �ļ����ƣ�TextAnimMessageWidget.h
* ����˵����
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2020-03-24
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UTextAnimMessageWidget : public UBaseWindow
{
	GENERATED_BODY()
public:

	UTextAnimMessageWidget(const FObjectInitializer& ObjectInitializer);
	//������Ϣ
	void SetInfo(FTextAnimationMessage TextData);
	//����
	void PlayAnimation();
	//����
	void ResetAnimation();

public:
	UPROPERTY(meta = (BindWidget))
		UImage* TextAnimImage;

public:
	float PlayTime;
	float AnimPhase;
	FTimerHandle AnimEventHandle;
};