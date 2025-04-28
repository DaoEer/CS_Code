// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Interface/NPCBaseObjectInterface.h"
#include "MultiAreaSpellBoxInterface.generated.h"

/*
* �ļ����ƣ�MultiAreaSpellBoxInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-10-18
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMultiAreaSpellBoxInterface : public UNPCBaseObjectInterface
{
	GENERATED_BODY()
	typedef UNPCBaseObjectInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()

public:
	UMultiAreaSpellBoxInterface();
	~UMultiAreaSpellBoxInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MultiAreaSpellBoxInterface'"); } //��ȡ��ͼ����·��

	/**
	*Define method ������֪ͨ��ת��ָ���������
	*@param ��������
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|MultiAreaSpellBoxInterface")
		void CLIENT_OnSwitchArea(int32 areaIndex);

	virtual void InitBlueCB() override;
};
