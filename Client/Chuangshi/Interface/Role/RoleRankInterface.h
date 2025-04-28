// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CS3Base/CS3EntityInterface.h"
#include "GameData/GameRankData.h"
#include "Entity/Alias.h"
#include "RoleRankInterface.generated.h"

/*
* �ļ����ƣ�RoleRankInterface.h
* ����˵����������߽���
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2018-08-15
*/
UCLASS(BlueprintType)
class CHUANGSHI_API URoleRankInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()

public:
	URoleRankInterface();
	~URoleRankInterface();
	static FString GetName() { return TEXT("RoleRankInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleRankInterface.BP_RoleRankInterface_C'"); } //��ȡ��ͼ����·��

	
	/* �����а����
	* @param NpcID  �򿪽���NPCid
	* @param RankNum ����ڱ����ȼ����а������(δ�ϰ�Ϊ-1)
	* @param TotalPage  �ȼ����а���ҳ��
	* @param LevelRank  ���а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void OpenGameRankBP(const int32& NpcID, const int32& RankNum, const int32& TotalPage, const TArray<FLevelRankData>& LevelRank);

	/* ��һ���������а�����
	* @param RankType  ���а�����
	* @param Camp ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	*/
	UFUNCTION(BlueprintCallable)
		void RequestRankFirstTime(EGameRank RankType, const int32& Camp);

	/* ��һ������ȼ����а�ص�
	* @param Camp  ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	* @param RankNum ����ڱ����ȼ����а������(δ�ϰ�Ϊ-1)
	* @param TotalPage  �ȼ����а���ҳ��
	* @param LevelRank  �ȼ����а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void OnRequestLevelRankFirstTimeBP(const int32& Camp, const int32& RankNum, const int32& TotalPage, const int32& Ascend, const TArray<FLevelRankData>& LevelRank);

	/* ��һ������ս�����а�ص�
	* @param Camp  ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	* @param RankNum ����ڱ���ս�����а������(δ�ϰ�Ϊ-1)
	* @param TotalPage  ս�����а���ҳ��
	* @param CombatRank  ս�����а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void OnRequestCombatRankFirstTimeBP(const int32& Camp, const int32& RankNum, const int32& TotalPage, const int32& Ascend, const TArray<FCombatRankData>& CombatRank);

	/* ��һ������Ƹ����а�ص�
	* @param Camp  ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	* @param RankNum ����ڱ����Ƹ����а������(δ�ϰ�Ϊ-1)
	* @param TotalPage  �Ƹ����а���ҳ��
	* @param MoneyRank  �Ƹ����а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void OnRequestMoneyRankFirstTimeBP(const int32& Camp, const int32& RankNum, const int32& TotalPage, const int32& Ascend, const TArray<FMoneyRankData>& MoneyRank);

	/* ��һ�������������а�ص�
	* @param Camp  ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	* @param RankNum ����ڱ����������а������(δ�ϰ�Ϊ-1)
	* @param TotalPage  �������а���ҳ��
	* @param WeaponRank  �������а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void OnRequestWeaponRankFirstTimeBP(const int32& Camp, const int32& RankNum, const int32& TotalPage, const int32& Ascend, const TArray<FWeaponRankData>& WeaponRank);

	UFUNCTION(BlueprintNativeEvent)
		void OnRequestRankStoreMoney(const FString& StoreMoney);

	/* �������а�����
	* @param RankType  ���а�����
	* @param Camp ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	* @param Page  �������а�ҳ��
	*/
	UFUNCTION(BlueprintCallable)
		void RequestRank(EGameRank RankType, const int32& Camp, const int32& Page);

	/* ��һ������ȼ����а�ص�
	* @param Camp  ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	* @param LevelRank  �ȼ����а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void OnRequestLevelRankBP(const int32& Camp, const int32& Page, const TArray<FLevelRankData>& LevelRank);

	/* ��һ������ս�����а�ص�
	* @param Camp  ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	* @param CombatRank  ս�����а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void OnRequestCombatRankBP(const int32& Camp, const int32& Page, const TArray<FCombatRankData>& CombatRank);

	/* ��һ������Ƹ����а�ص�
	* @param Camp  ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	* @param MoneyRank  �Ƹ����а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void OnRequestMoneyRankBP(const int32& Camp, const int32& Page, const TArray<FMoneyRankData>& MoneyRank);

	/* �����������а�ص�
	* @param Camp  ���󱾷�����Ӫ�����ݣ�0-�������а�1-�ɵ����а�2-ħ�����а�
	* @param WeaponRank  �������а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void OnRequestWeaponRankBP(const int32& Camp, const int32& Page, const TArray<FWeaponRankData>& WeaponRank);
	/*
	*֪ͨ�ͻ������а��Ѹ��£�������������
	* @param RankType ���а�����
	*/
	UFUNCTION(BlueprintNativeEvent)
		void Client_updateRankData(const uint8&  RankType);

	UFUNCTION(BlueprintCallable)
		void clearRankData();

	void OpenGameRank(const int32& INT32_1, const int32& INT32_2, const int32& INT32_3, const FVariant& fixedDict );

	void OnRequestCombatRankFirstTime(const int32& INT32_0, const int32& INT32_1, const int32& INT32_2, const FVariant& fixedDict );

	void OnRequestLevelRankFirstTime(const int32& INT32_0, const int32& INT32_1, const int32& INT32_2, const FVariant& fixedDict );

	void OnRequestMoneyRankFirstTime(const int32& INT32_0, const int32& INT32_1, const int32& INT32_2, const FVariant& fixedDict );

	void OnRequestWeaponRankFirstTime(const int32& INT32_0, const int32& INT32_1, const int32& INT32_2, const FVariant& fixedDict );

	virtual void InitBlueCB() override;
	virtual void onLeaveWorld() override;

private:
	inline void GetLevelRankData(const int32& Camp, const int32& Page, TArray<FLevelRankData>& RankType);
	inline void GetCombatRankData(const int32& Camp, const int32& Page, TArray<FCombatRankData>& RankType);
	inline void GetMoneyRankData(const int32& Camp, const int32& Page, TArray<FMoneyRankData>& RankType);
	inline void GetWeaponRankData(const int32& Camp, const int32& Page, TArray<FWeaponRankData>& RankType);
public:
	///����Լ��ĲƸ�ֵ
	UPROPERTY(BlueprintReadOnly)
		int64 MoneyRankValue;
private:
	/// �ȼ����а�����
	TMap<int32, int32> LevelRankNum;
	///�ȼ����а�ҳ��
	TMap<int32, int32> LevelRankPages;
	///�ȼ�����
	TMap<int32, int32> LevelRankAscend;
	/// �ɵ��ȼ����а�
	TArray<FLevelRankData> XianLevelRankList;
	/// ħ���ȼ����а�
	TArray<FLevelRankData> MoLevelRankList;
	///ȫ���ȼ����а�
	TArray<FLevelRankData> AllLevelRankList;

	/// ս�������а�����
	TMap<int32, int32> CombatRankNum;
	///ս�������а�ҳ��
	TMap<int32, int32> CombatRankPages;
	///ս��������
	TMap<int32, int32> CombatRankAscend;
	/// �ɵ�ս�������а�
	TArray<FCombatRankData> XianCombatRankList;
	/// ħ��ս�������а�
	TArray<FCombatRankData> MoCombatRankList;
	///ȫ��ս�������а�
	TArray<FCombatRankData> AllCombatRankList;

	/// �Ƹ����а�����
	TMap<int32, int32> MoneyRankNum;
	///�Ƹ����а�ҳ��
	TMap<int32, int32> MoneyRankPages;
	///�Ƹ�����
	TMap<int32, int32> MoneyRankAscend;
	/// �ɵ��Ƹ����а�
	TArray<FMoneyRankData> XianMoneyRankList;
	/// ħ���Ƹ����а�
	TArray<FMoneyRankData> MoMoneyRankList;
	///ȫ���Ƹ����а�
	TArray<FMoneyRankData> AllMoneyRankList;

	/// �������а�����
	TMap<int32, int32> WeaponRankNum;
	///�������а�ҳ��
	TMap<int32, int32> WeaponRankPages;
	///��������
	TMap<int32, int32> WeaponRankAscend;
	/// �ɵ��������а�
	TArray<FWeaponRankData> XianWeaponRankList;
	/// ħ���������а�
	TArray<FWeaponRankData> MoWeaponRankList;
	///ȫ���������а�
	TArray<FWeaponRankData> AllWeaponRankList;
	///�ȼ����а���±��
	bool levelUptadeMark = false;
	///ս�����а���±��
	bool combatUptadeMark = false;
	///�Ƹ����а���±��
	bool moneyUptadeMark = false;
	///�������а���±��
	bool weaponUptadeMark = false;



	/// �������а�ʱ��
	FDateTime requestTime;

};

