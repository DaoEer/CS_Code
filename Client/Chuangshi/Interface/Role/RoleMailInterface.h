// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CS3Base/CS3EntityInterface.h"
#include "GameData/MailData.h"
#include "RoleMailInterface.generated.h"

/*
* �ļ����ƣ�RoleMailInterface.h
* ����˵��������ʼ�
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2018-07-24
*/
UCLASS(BlueprintType)
class CHUANGSHI_API URoleMailInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleMailInterface();
	~URoleMailInterface();
	static FString GetName() { return TEXT("RoleMailInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleMailInterface.BP_RoleMailInterface_C'"); } //��ȡ��ͼ����·��

	/**
	*Define method
	*���������ʼ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleMailInterface")
		void ReceiveAllMailBP();
	void ReceiveAllMail(const FVariantArray& recordNames,const FVariantArray& AllMailData);

	/**
	*Define method
	*����һ���ʼ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleMailInterface")
		void ReceiveMailBP(const FString& mailId);

	void ReceiveMail(const FVariant& MailData);

	/**
	*Define method
	*ɾ���ʼ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleMailInterface")
		void OnMailDeletedBP(const TArray<FString>& MailIDList);

	void OnMailDeleted(const FVariantArray&  mailids);
	/**
	*Define method
	*��ȡһ���ʼ��ɹ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleMailInterface")
		void CLIENT_ExtractMailSuccess(const FString& MailID);

	/**
	*Define method
	*���������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleMailInterface")
		void CLIENT_OpenMailWindow();

	FMailData AddOneMailData(const FVariant& MailData);

	void AddMailByJsonData(const FString& jsonData);

	void BASE_TimeToDelMail(const FString& MailID);

	/**
	*����ɾ���ʼ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleMailInterface")
		void BASE_RequestDeleteMail(TArray<FString> MailIDList);

	/**
	*�������ʼ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleMailInterface")
		void BASE_RequestSendMail(FString receiverName, FString title, FString content);

	/**
	*Define method
	*�����ʼ��ɹ��ص�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleMailInterface")
		void OnMailSendSuccess();

	/**
	*������ȡ�ʼ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleMailInterface")
		void CELL_RequestExtractMail(TArray<FString> MailIDList);

	/**
	*�����Ѷ��ʼ���������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleMailInterface")
		void BASE_ReadedMailNotifyToSever(FString MailID);

	/**
	*���ĳ���������͵��ʼ��б�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleMailInterface")
		TArray<FMailData> GetMailDataByMailSendType(MAIL_SEND_TYPE mailSendType);

	/**
	*ͨ���ʼ�ID����ʼ�
	*
	*param mailID �ʼ�ID
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleMailInterface")
		FMailData GetMailDataByMailID(FString mailID);

	/**
	*�ж�ĳ���������͵��ʼ��б��Ƿ���δ���ʼ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleMailInterface")
		bool IsMailDataNotRead(MAIL_SEND_TYPE mailSendType);


	/**
	*Define method
	*���������˵ļ�¼
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleMailInterface")
		void CLIENT_AddRecordReceiveName( const FString& receiveName );

	/**
	*Define method
	*ɾ�������˵ļ�¼
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleMailInterface")
		void CLIENT_RemoveRecordReceiveName(const FString& receiveName);

	/**
	*��������˵ļ�¼
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleMailInterface")
		TArray<FString> GetRecordReceiveNames();

	virtual void InitBlueCB() override;

	virtual void onLeaveWorld() override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<FString,FMailData> MailMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> RecordReceiceNames;

private:
	TMap< FString, FTimerHandle > MailTimerDict;
};