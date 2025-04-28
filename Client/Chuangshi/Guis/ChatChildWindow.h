#pragma once
#include "CS3Base/BaseWindow.h"
#include "ChatChildWindow.generated.h"

/*
* �ļ����ƣ�ChatChildWindow.h
* ����˵���������Ӵ���
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2019-03-28
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UChatChildWindow : public UBaseWindow
{
	GENERATED_BODY()
public:
	UChatChildWindow(const FObjectInitializer& ObjectInitializer);
	~UChatChildWindow();
public:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
};