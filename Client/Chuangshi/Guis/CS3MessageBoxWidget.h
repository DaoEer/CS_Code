#pragma once
#include "../CS3Base/BaseWindow.h"
#include "GameData/MessageData.h"
#include "CS3MessageBoxWidget.generated.h"

/*
* �ļ����ƣ�MessageBoxWidget.h
* ����˵����
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2019-01-03
*/

class UMessageManager;

UCLASS(BlueprintType)
class CHUANGSHI_API UCS3MessageBoxWidget : public UBaseWindow
{
	GENERATED_BODY()
public:

	/**
	*BlueprintNativeEvent����ʾ��Ϣ��
	*@param msg �Ի�����Ϣʵ��
	*@param Key �������Զ����ɵ�ֵ
	*@param Compotent ��cell ���� base ��������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3MessageBoxWidget")
		void ShowMessage(const UDialogMessage* msg, int32 Key, const FString& Compotent);

	/**
	*BlueprintNativeEvent����Ӧ��Ϣ��ť
	*@param BtnType ��ť���� �ǻ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3MessageBoxWidget")
		void ResponseMessageBtn(RT_BTN_TYPE BtnType);

public:
	///<��ϢID
	UPROPERTY(BlueprintReadWrite, category = "MessageBoxWidget")
		FName MessageBoxID;
	///<�Ƿ�����
	UPROPERTY(BlueprintReadWrite, category = "MessageBoxWidget")
		bool IsCover;
};