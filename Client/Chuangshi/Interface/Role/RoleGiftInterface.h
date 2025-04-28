// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CS3Base/CS3EntityInterface.h"
#include "GameData/OnLineReward.h"
#include "RoleGiftInterface.generated.h"

/*
* �ļ����ƣ�RoleGiftInterface.h
* ����˵����������߽���
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2018-08-15
*/
UCLASS(BlueprintType)
class CHUANGSHI_API URoleGiftInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleGiftInterface();
	~URoleGiftInterface();
	static FString GetName() { return TEXT("RoleGiftInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleGiftInterface.BP_RoleGiftInterface_C'"); } //��ȡ��ͼ����·��

	/**
	*��ʾ���߽���
	*
	*@param LiftTime ���ж೤ʱ�������ȡ(��λ����)
	*@param Reward ����
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleGiftInterface")
		void OnShowOnlineReward(const int32& LiftTime, const FString& Reward, const int32& BindType);

	// ��ȡ�������߽���
	UFUNCTION(BlueprintCallable, Category = "RoleGiftInterface")
		void ReceiveNewPlayerGift();
	// ����������߽���
	UFUNCTION(BlueprintNativeEvent, Category = "RoleGiftInterface")
		void OnFinishReceiveNewPlayerGift();

	/**
	*ǩ������
	*
	*@param SignInTotalNum �ۼ�ǩ������
	*@param SignInTotalRewardNum ��ȡ�ۼƽ�������
	*@param SignInRewardList �Ѿ���ȡ�ۼƽ�������
	*@param SignInJson ǩ��json����
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleGiftInterface")
	void OnShowSignInRewardEnd();

	void OnShowSignInReward(const int32& SignInTotalNum, const int32& SignInTotalRewardNum, const FVariant& SignInRewardList, const FVariant& SignInJson);

	// ĳ��ǩ������
	// ���� {ItemID:amount,....}
	UFUNCTION(BlueprintCallable, Category = "RoleGiftInterface")
		TArray<FSignInReward> GetSignInReward(const int32& Day);

	// �ۼ�ǩ������
	// ���� {ItemID:amount,....}
	UFUNCTION(BlueprintCallable, Category = "RoleGiftInterface")
		TArray<FSignInReward> GetTotalSignInReward(const int32& AccumulateDay);

	// �Ƿ���ǩ��
	UFUNCTION(BlueprintCallable, Category = "RoleGiftInterface")
		bool bSignIn(const int32& year, const int32& month, const int32& day);

	// ǩ��
	UFUNCTION(BlueprintCallable, Category = "RoleGiftInterface")
		void SignInOnline();
	UFUNCTION(BlueprintNativeEvent, Category = "RoleGiftInterface")
		void OnSignInOnlineSuccess();

	// ��ǩһ��
	UFUNCTION(BlueprintCallable, Category = "RoleGiftInterface")
		void AugmentSignIn(const int32& Year, const int32& Month, const int32& Day);
	UFUNCTION(BlueprintNativeEvent, Category = "RoleGiftInterface")
		void OnAugmentSignInSuccess(const int32& Year, const int32& Month, const int32& Day);

	// ��ǩһ����
	UFUNCTION(BlueprintCallable, Category = "RoleGiftInterface")
		void AugmentSignInMonth(const int32& Year, const int32& Month);
	UFUNCTION(BlueprintNativeEvent, Category = "RoleGiftInterface")
		void OnAugmentSignInMonthSuccess(const int32& Year, const int32& Month);

	// ��ȡ�ۼ�ǩ������
	UFUNCTION(BlueprintCallable, Category = "RoleGiftInterface")
		void ReceiveTotalSignReward(const int32& AccumulateNum);
	UFUNCTION(BlueprintNativeEvent, Category = "RoleGiftInterface")
		void OnReceiveTotalSignRewardSuccess(const int32& AccumulateNum);

	// �ﵽ��ȡ ĳ�ۼ�ǩ������
	UFUNCTION(BlueprintNativeEvent, Category = "RoleGiftInterface")
		void OnReachSignRewardNum(const int32& num);

	// ��ȡ��һ���ۼ�ǩ������
	UFUNCTION(BlueprintNativeEvent, Category = "RoleGiftInterface")
		void OnFinishRecSignReward();

	virtual void InitBlueCB() override;
	virtual void onLeaveWorld() override;
public:
	/// �������߽������� { itemID : amount ,...}
	UPROPERTY(BlueprintReadOnly)
		TArray<FSignInReward> OnLineRewardItems;

	/// ǩ������
	UPROPERTY(BlueprintReadOnly)
		TArray<FSignInData> SignInList;
	/// �ۼƽ�������
	UPROPERTY(BlueprintReadOnly)
		TMap<int32, SIGN_IN_REWARD_TYPE> SignInRewardMap;



private:
	/// ��ʼ�� �ۼ�ǩ������
	void InitTotalSignInNum();
	/// ���ɽ�������
	void AnalysisItemStr(const FString& ItemStr, const int32& BindType, TArray<FSignInReward>& ItemList);

	void CalculateAugmentSignInMonth(const int32& Month, TArray<int32>& Days);

	/// ����ǩ������
	void AddSignInNum();

private:
	/// ǩ������
	int32 SignInNum;

	/// ��ȡǩ���ۼƽ��� ����
	int32 SignInRewardNum;


};