// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "GameData/QTEDate.h"
#include "Operation/QTEBaseOperation.h"
#include "QTEManager.generated.h"


/*
* �ļ����ƣ�QTEManager.h
* ����˵����QTE������
* �ļ����ߣ�huting
* Ŀǰά����huting
* ����ʱ�䣺2018-7-17
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyInputEvent, FKey, Key);

DECLARE_STATS_GROUP(TEXT("UQTEManager"), STATGROUP_QTEManager, STATCAT_Advanced);
UCLASS(BlueprintType)
class CHUANGSHI_API UQTEManager : public UCS3Object
{
	GENERATED_BODY()

private:
	UQTEManager();
	~UQTEManager();

public:
	static UQTEManager* GetInstance();

	void OnStartQTEEvent(FString TableRowName);///<��ʼQTE�¼�
	void OnStartQTESetTimer();
	void OnCheckQTEEvent();///<���QTE�¼�
	void OnDeathQTEEvent();///<ֹͣQTE�¼�
	void OnStopQTEEvent();
	void OnStartQTEEventType(FQTE_EVENT_DATA QTEEventData);
	void ImplementQTETypeEvent(QTE_COMPLETE_TYPE QTECompleteType);
	void OtherShowQTE();

	/**
	*null����ʾboss������
	*
	*@param IsShow �Ƿ���ʾ
	*@param Percent ���˺��ٷ���
	*@param HurtPercent Ԥ�ƿ�Ѫ�׷���
	*@param IsQTE �Ƿ���QTE
	*
	*@return ��
	*/
	void ShowHPProgressBar(uint8 bIsShow, int32 Percent, int32 HurtPercent);

	UFUNCTION()
		void OnCheckKey(FKey Key);//��ʼִ������QTE�¼�

	UFUNCTION()
		void OnContinueCheckKey(FKey Key);

	UFUNCTION()
		void OnContinueCheckRandomKey(FKey Key);///<CST-12007

	UFUNCTION()
		void OnContinuityKeyboard(FKey Key);

	UFUNCTION(BlueprintImplementableEvent, Category = "cs3|QTEManager")
		void OnBPStartQTEEvent(); ///��ͼ��ʼ�¼�

	UFUNCTION(BlueprintImplementableEvent, Category = "cs3|QTEManager")
		void OnBPStopQTEEvent(); ///��ͼ�����¼�

	UFUNCTION(BlueprintImplementableEvent, Category = "cs3|QTEManager")
		void ShowWobbleMouseBar(bool isvisbale);

	/**
	*��ʾboss������
	*
	*@param IsShow �Ƿ���ʾ
	*@param Percent ���˺��ٷ���
	*@param HurtPercent Ԥ�ƿ�Ѫ�׷���
	*@param IsQTE �Ƿ���QTE
	*
	*@return ��
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "cs3|QTEManager")
		void OnBPShowHPProgressBar(uint8 bIsShow, int32 Percent, int32 HurtPercent);

	/**
	*��ʾ����Ƿ�ʼҡ�����ui��ʾ
	*
	*@param bIsSucceed �Ƿ���ʾ
	*@param Delay �ӳٶ����������ʾ
	*
	*@return ��
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "cs3|QTEManager")
		void OnBPNotifyClinetQTEResult(uint8 bIsSucceed,float DelayTime);

	/**
	*BlueprintImplementableEvent�����������ʾQTE��ʾ
	*
	*@return ��
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "cs3|QTEManager")
		void OnBPOtherShowQTE();

	UFUNCTION(BlueprintCallable, Category = "cs3|QTEManager")
		float GetQTEValue() { return QTEValue; }

		FOnKeyInputEvent OnKeyInputEvent;

private:
	void OnCellCall(bool bIsSuccess);///<֪ͨ�������Ƿ�ɹ�
	void OnCreatOperation(int32 QteType);///<����QTE����
	void OnResetQTEDate();///<���QTE����
	void OnClearTimer();
	void ResetContinueRandomKey(FQTE_TYPE_DATA  QTEType);///<�����������������
	void SetContinueRandomKeyActionEnable(bool Enable);///<���������Ƿ񼤻����Action��Ϊ 
private:
	FTimerHandle CheckQTEEventHandle;///<���QTE�¼���ʱ��
	FTimerHandle StopQTEEventHandle;///<ֹͣQTE�¼���ʱ��
	FTimerHandle DelayQTEEventHandle;///<�ӳ�QTE�¼���ʱ��
	UQTEBaseOperation* Operation;//<QTE����
	float QTEValue;
	bool Mouseistrue;
	TArray<FString> QTETypeArray;
	TArray<FString> QTETimeArray;
	TArray<FString> QTEKeypressArray;
	int32 QTEIndex = 0;
	TArray<FQTE_TYPE_DATA> QTETypeDataArray;
	TArray<FQTE_EVENT_DATA> QTEEventDataArray;
	TArray<FString> ContinueKeyList;
	FString ContinueName;
	FKey KeyValue;
	int8 ContinueInedx;
};
