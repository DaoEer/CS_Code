// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameData/CS3Object.h"
#include "GameData/AutomaticFightData.h"
#include "AutoFightMar.generated.h"

/*
* �ļ����ƣ�AutoFightMar.h
* ����˵����
* �ļ����ߣ�yanjingxin
* Ŀǰά����yanjingxin
* ����ʱ�䣺2018-08-28
*/
UCLASS()
class CHUANGSHI_API UAutoFightMar : public UCS3Object
{
	GENERATED_BODY()
	
public:
	static UAutoFightMar* NewInstance();

	static UAutoFightMar* GetInstanceByCS3GameInstance();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "UAutoFightMar|Event")
		void OnStartAutoAdd_HpMp();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "UAutoFightMar|Event")
		void OnStopAutoAdd_HpMp();
public:
	//-----------------------------------�Զ�ս���¼�------------------------------
	//�����Զ�ս���ɹ��¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event")
		void OnBeginAutomaticFightOver();

	//����Զ�ս���ɹ��¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event")
		void OnBreakFightSuccessed(EBreakAutomaticType BreakType, const FName& IDValue);

	//����Զ�ս��ʧ���¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event")
		void OnBreakFightFailed(EBreakAutomaticType BreakType, const FName& IDValue);

	//-----------------------------------�Զ�ս�����ܿ�����¼�------------------------------
	//��Ӽ��ܵ��Զ�ս��������¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event|SkillList")
		void OnAddSkillOnListOver(int32 SkillKey, int32 NewSkill);

	//ͨ���Զ�ս�������Key�Ƴ������¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event|SkillList")
		void OnRemoveSkillOnListByKey(int32 SkillKey);

	//ͨ������id�Ƴ������¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event|SkillList")
		void OnRemoveSkillOnListByValue(int32 RemSkill);

	//�Զ�ս����������������¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event|SkillList")
		void OnExchangeOnSkill(int32 KeyValue1, int32 KeyValue2);

	//-----------------------------------�Զ�ս����Ʒ������¼�------------------------------
	//�����Ʒ���Զ�ս����Ʒ������¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event|ItemList")
		void OnAddItemOnListOver(int32 ItemKey, int32 NewUID);

	//ͨ���Զ�ս����Ʒ�����Key�Ƴ���Ʒ�¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event|ItemList")
		void OnRemoveItemOnListByKey(int32 ItemKey);

	//ͨ����Ʒid�Ƴ���Ʒ�¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "UAutoFightMar|Event|ItemList")
		void OnRemoveItemOnListByValue(int32 RemItem);

	//-----------------------------------�Զ�ս�������¼�------------------------------
	//�Զ�ս�����ñ仯�¼�
	UPROPERTY(BlueprintAssignable, Category = "UAutoFightMar|Event|SettingData")
		FOnChangeAutoFightData OnChangeAutoFightData;
};
