// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusMessageInterface.h"
#include "GameDevelop/CS3GameInstance.h"
#include "Manager/MessageManager.h"
#include "Util/CS3Debug.h"

CS3_BEGIN_INTERFACE_METHOD_MAP(UStatusMessageInterface, Supper)
CS3_END_INTERFACE_METHOD_MAP()

CS3_BEGIN_INTERFACE_PROPERTY_MAP(UStatusMessageInterface, Supper)
CS3_END_INTERFACE_PROPERTY_MAP()
	
UStatusMessageInterface::UStatusMessageInterface()
{

}

UStatusMessageInterface::~UStatusMessageInterface()
{

}

void UStatusMessageInterface::statusMessage_Implementation(const int32& statusID, const FString& args)
{
	//���ݴ����ID�Լ�������ȡ����ʾ��Ϣ�����������н������
	UUECS3GameInstance::Instance->MessageManager->ShowMessage(statusID, args);
}


void UStatusMessageInterface::HideStatusMessage_Implementation(const int32& statusID)
{
	//���ݴ����ID ������Ϣ
	UUECS3GameInstance::Instance->MessageManager->HideMessage(statusID);
}

void UStatusMessageInterface::inquireMessage_Implementation(const int32 & statusID, const FString & args, const int32 Key, const FString& Compotent)
{
	//��������ͻ��˽��������ڵ����ť�Զ���Ӧ����������Ϣ������Ҫ�ͻ��˵����ť���¼�֪ͨ
	UUECS3GameInstance::Instance->MessageManager->ShowMessage(statusID, args, nullptr, Key, Compotent);
}

FString UStatusMessageInterface::GetReplaceMessage(const FString& replaceMessage, const FString args /*= TEXT("")*/, FString SplitChar /*= TEXT("|")*/)
{
	//����ʾ��Ϣ�еĲ����ô���Ĳ����������
	FString MsgArgs = args;
	TArray<FStringFormatArg> ArgsArray;
	FString left, right;
	bool result = true;
	while (!MsgArgs.IsEmpty())
	{
		result = MsgArgs.Split(SplitChar, &left, &right, ESearchCase::Type::CaseSensitive);
		if (result)
		{
			MsgArgs = right;
			ArgsArray.Add(left);
		}
		else
		{
			ArgsArray.Add(MsgArgs);
			MsgArgs = TEXT("");
		}
	}
	FString infoMessage;
	if (ArgsArray.Num() > 0)
		infoMessage = FString::Format(*replaceMessage, ArgsArray);
	else
		infoMessage = replaceMessage;
	return infoMessage;
}

void UStatusMessageInterface::RPC_Base_replyMessage(const FString& STRING_1, const FString& STRING_2)
{
	KBEngine::Entity* entity = GetEntity();
	if (entity == nullptr)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UStatusMessageInterface::RPC_Base_replyMessage : entity!"));
		return;
	}

	KBEngine::FVariantArray args;
	args.Add(STRING_1);
	args.Add(STRING_2);

	entity->BaseCall(TEXT("replyMessage"), args);
}

void UStatusMessageInterface::RPC_Cell_replyMessage(const FString& STRING_1, const FString& STRING_2)
{
	KBEngine::Entity* entity = GetEntity();
	if (entity == nullptr)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UStatusMessageInterface::RPC_Cell_replyMessage : entity!"));
		return;
	}

	KBEngine::FVariantArray args;
	args.Add(STRING_1);
	args.Add(STRING_2);

	entity->CellCall(TEXT("replyMessage"), args);
}


void UStatusMessageInterface::InitBlueCB()
{
	ArrBlueFunc.Add("statusMessage"); 
	ArrBlueFunc.Add("HideStatusMessage");
	ArrBlueFunc.Add("inquireMessage");
	ArrBlueFunc.Add("ShowCountDown");
	ArrBlueFunc.Add("ShowSpaceCopyIntroduction");
	Supper::InitBlueCB();
}
