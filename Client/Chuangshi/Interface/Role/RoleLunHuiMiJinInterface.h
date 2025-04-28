// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CS3Base/CS3EntityInterface.h"
#include "GameData/Item/ToolCost.h"
#include "GameData/NPCShopData.h"
#include "RoleLunHuiMiJinInterface.generated.h"

/*
* �ļ����ƣ�RoleLunHuiMiJinInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-12-09
*/


/**
* ����ֻ��ؾ��ӿ���
*/
UCLASS(BlueprintType)
class CHUANGSHI_API URoleLunHuiMiJinInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	static FString GetName() { return TEXT("RoleLunHuiMiJinInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleLunHuiMiJinInterface.BP_RoleLunHuiMiJinInterface_C'"); } //��ȡ��ͼ����·��
	/**
	*Define Method
	*BlueprintNativeEvent,������޲�׽���ģʽ
	*@param	skillID ����ͷż���
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void EnterHSBZModelTPS(const int32& skillID);

	/**
	*Define Method
	*BlueprintNativeEvent,�뿪���޲�׽���ģʽ
	*@param	skillID ����ͷż���
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void LeaveHSBZModelTPS();

	/**
	*Define Method
	*BlueprintNativeEvent,��׽ԭ�޽��
	*@param	result �����1���ɹ���0��ʧ�ܣ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void OnCatchOriginPetResult(const int32& result);

	/**
	*Define Method
	*BlueprintNativeEvent,ͨ��������ʧ�ܽ���
	*@param	difference 0������ʾ������ս��ť�� 1������ʾ������ս��ť
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void TongTinaDaSpaceFailure(const int32& difference);

	/**
	*Define Method
	*BlueprintNativeEvent,ͨ���������ɹ��������
	*@param	money ��Ǯ��
	*@param	exp ������
	*@param	itemList ��Ʒ ��ʽ����ƷID:����|��ƷID:����|��ƷID:���� (���磺101040128:1|101040129:2|101040130:3|)
	*@param	difference 1������ʾͻ��������ť�� 0������ʾ������ս��ť,2����ǰͨ�ص������һ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void TongTinaDaSpaceSuccess(const int32& money, const int32& exp, const FString& itemList, const int32& difference);

	/**
	*��ҵ��������޲�׽���ģʽ
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onEnterHSBZModelTPS();

	/**
	*����л�Ŀ�� �뿪���޲�׽���ģʽ
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onLeaveHSBZModelTPS();

	/**
	*ͨ����   ������ս��ǰ��
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onAgainChallengeCurrentLayer();

	/**
	*ͨ����   ������ս
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onContinueChallengeLayer();

	/**
	*Define Method
	*BlueprintCallable,��ʼ���ֻ��ؾ�����
	*@param	spaceType 1:������˽�У���2���ɸ������У�
	*@param	builds {�������ͣ��ȼ�} 1����Ȫ��2��������3��Ǭ������4��������5������
	*
	*@return ��
	*/
	void CLIENT_initLHMJBuild(const int32& spaceType, const FVariant& BuildVar);

	/**
	*Define Method
	*BlueprintCallable,�ֻ��ؾ���������
	*@param	buildType 1����Ȫ��2��������3��Ǭ������4��������5������
	*@param	level �ȼ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void CLIENT_OnLHMJBuildLevelChange(const int32& buildType, const int32& level);

	/*
	* ���������ť��������Ҷ������ڵ�������
	*/
	UFUNCTION(BlueprintCallable)
		void RequestPlayerDFDatas();
	/*
	*����ص�
	*@param LineNumber ��Ҷ������ڵ��ߣ����û���� ����1��
	*@param AllLineNumber �ֻ��ؾ�һ���м�����
	*@param TotalPage ������ҳ��
	*@param FreeDfNum ����Ķ�������ûռ��
	*@param DFVari ��һҳ�Ķ�������
	*/
	void OnRequestPlayerDFDatas(const int32& LineNumber, TArray<FVariant>& AllLineNumber, const int32& TotalPage, const int32& FreeDfNum, const FVariant& DFVari);
	/*
	*���󶴸�����
	*@param LineNumber �����ļ���
	*/
	UFUNCTION(BlueprintCallable)
		void RequestDFDatas(const int32& LineNumber);
	/*
	*����ص�
	*@param TotalPage ������ҳ��
	*@param FreeDfNum ����Ķ�������ûռ��
	*@param DFVari ��һҳ�Ķ�������
	*/
	void OnRequestDFDatas(const int32& TotalPage, const int32& FreeDfNum, const FVariant& DFVari);

	/*
	*�����ҳ��ť�����󶴸�����
	*@param LineNumber ��ǰ������ʾ�� �ڼ���
	*@param Page ��Ҫ�����ҳ�루��2ҳ��Ϊ2��
	*/
	UFUNCTION(BlueprintCallable)
		void requestDFDatasByPage(const int32& LineNumber, const int32& Page);
	/*
	*����ص�
	*@param DFVari ��������
	*/
	void OnRequestDFDatasByPage(const FVariant& DFVari);

	// �򿪽�������ص���������ʾ��������
	void OnFirstShowDFDatas(const int32& LineNumber, const TArray<int32>& AllLineNumber, const int32& TotalPage, const int32& Page, const int32& FreeDfNum, const TArray<FDongFuData>& DongFuDatas);
	// ��ҳ����ص���������ʾ��������
	void OnShowDFDatas(const int32& LineNumber, const int32& Page, const TArray<FDongFuData>& DongFuDatas);

	/**
	*Define Method
	*BlueprintCallable,������������
	*@param	level �ȼ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "cs3|RoleLunHuiMiJinInterface")
		void CLIENT_onUpgradeJadeItem(const int32& level);
	UFUNCTION(BlueprintImplementableEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void OnUpgradeJadeItemBP(const int32& level);
	// �Ƿ�ռ���˶���/�ɸ�
	UFUNCTION(BlueprintCallable)
		bool IsOccupySpaceType(LHMJ_SPACE_TYPE spaceType);
	// ��ȡ�����ȼ�
	UFUNCTION(BlueprintCallable)
		int32 GetBuildLevel(LHMJ_BUILD_TYPE buildType);
	// ��������
	UFUNCTION(BlueprintImplementableEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void OnUpdateBuildLevel(const LHMJ_BUILD_TYPE& build, const int32& level);

	/** 
	*Define Method
	*BlueprintNativeEvent,֪ͨ����������UI����
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void OnShowCompassUI();

	/**
	*Define Method
	*BlueprintNativeEvent,֪ͨ�ػ�����λ��
	*@param	buildPos λ��
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void OnNotifyBuildPos(const FVector& buildPos, const int32& npcID);

	/**
	*Define Method
	*BlueprintNativeEvent,ռ����ؽ��
	*@param	result ��� 1��ռ��ɹ��رս��棬0��ռ��ʧ�ܣ�������ʾ̽��
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void OccupyBuildResult(const int32& result);

	/**
	*Define Method
	*BlueprintNativeEvent,֪ͨ�򿪽��춴������
	*@param	endStrTime ����״̬�Ľ���ʱ��
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void StartBuildCaveHouse(const int32& dongfuID, const FString& endStrTime);

	/**
	*Define Method
	*BlueprintNativeEvent,֪ͨ�򿪽��붴������
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void OnEnterCaveHouse(const int32& dongfuID);

	// ������˵Ķ�������ս��
	UFUNCTION(BlueprintCallable, Category = "cs3|RoleLunHuiMiJinInterface")
		void OnEnterOtherCaveHouse(const int32& dongfuID);
	// ���������˵Ķ���
	UFUNCTION(BlueprintCallable, Category = "cs3|RoleLunHuiMiJinInterface")
		void OnClieckEnterOtherCaveHouse(const int32& dongfuID);
	/**
	*Define Method
	*,֪ͨ����Ȫ����
	*@param	_ActiveChartID �ڼ���״̬����ͼID
	*@param	LHMJ_CoverHP  ������HP
	*@param	_TotalLingNeng �ɻ�õ�������
	*@param	_LQCurrHP  ��ȪHP
	*@param	DestroyBuild ���ƻ��Ľ���
	*@param	NPCID �Ի�NPCID
	*@return ��
	*/
	void OpenLingQuanUI(const int32& _ActiveChartID, const int32& LHMJ_CoverHP, const int32& _TotalLingNeng, const int32& _LQCurrHP, const FVariant& DestroyBuild, const int32& NPCID);

	/* ������������ʱ�䣨��Ȫ�Ƿ��ƻ������Ϸ�����DestroyBuild��
	* �����Ȫ���ƻ��ˣ��������ʾ����ʱ��ֵΪReviveTime���Ҳ���ʼ����ʱ��
	* �����Ȫ�Ǻõģ�����浹��ʱ��ֵΪ�·�����ʼ����ʱ��
	* UGolbalBPFunctionLibrary::FromServerTimeToClientTime(ReviveTime) - FDateTime::Now()
	*/
	void OnGuardReviveTime(const int32& ReviveTime);

	/**
	*Define Method
	*BlueprintNativeEvent,��ʼ����ĳ����
	*@param	buildType ��������
	*@param	endStrTime  ������Ҫ��ʱ��
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void StartBuildUpgrade(const int32& buildType, const FString& endStrTime);

	/**
	*���� ���̽����ť
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onCliskExplore();

	/**
	*���� ���ռ�찴ť
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onCliskOccupyBuild();

	/**
	*���� ������춴����ť
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onCliskBuildCaveHouse(const int32& dongfuID);

	/**
	*���� ������붴����ť
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onCliskEnterCaveHouse(const int32& dongfuID);

	/**
	*���� �����ȡ����
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onReceiveLingNeng();

	/**
	*���� ��������ĳ����
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onUpgradeBuild(const int32& buildType, const int32& buildLevel);

	/**
	*���� ����ĳ�����ɹ��ص�
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_onUpgradeBuildSuccess(const int32& buildType);

	/**
	*��ȡ��������������
	*/
	UFUNCTION(BlueprintCallable)
		void GetBuildDepleteData(LHMJ_BUILD_TYPE buildType, const int32& buildLevel, TArray<int32> &itemList, TArray<int32> &amountList, int32 &depleteMoney, int32 &depletePsionic, int32 &depleteTime);

	/**
	*��ȡ��Ȫ��������
	*/
	UFUNCTION(BlueprintCallable)
		void GetLingQuanProduceData(const int32& lingQuanLevel, int32 &timeKey, int32 &outLingNengAmount, int32 &lingNengMaxAmount, int32 &lingQuanMaxHP);
	

	// ������ͼ(��ͼID)
	UFUNCTION(BlueprintCallable)
		void OpenBattleFormations(const int32& ItemID);
	/**
	*BlueprintNativeEvent,������ͼ�ص�(PS��������ʾ������ ����ȥ������ȡ����Ϊ�Ѿ�ɾ���ˣ�)
	*@param	_ActiveChartID �ڼ���״̬����ͼID
	*@param	LHMJ_CoverHP  ������HP
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void CLIENT_OnActiveBatteleFormations(const int32& _ActiveChartID, const int32& LHMJ_CoverHP);

	// �ر���ͼ
	UFUNCTION(BlueprintCallable)
		void CloseBattleFormations();
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void CLIENT_OnCloseBatteleFormations();

	UFUNCTION(BlueprintCallable)
		void OnLHMJWInClose();

	// �Զ���������սShowChallenge
	UFUNCTION(BlueprintCallable)
		void RequestLHMJChallenge(const int32& lineNumber, const int32& group);
	// ������ս�ص�
	UFUNCTION(BlueprintCallable)
		void OnRequestLHMJChallenge(const int32& lineNumber, const FString& PlayerName);

	/**
	*BlueprintCallable,����ս����ʾ ��ս�ߵ���ս��Ϣ
	*@param	PlayerName ��ս�ߵ�����
	*@param	CanRefuseTime  ���Ծܾ��Ĵ���������Ϊ0����ܾ���ť�ûң�
	*@return ��
	*/
	UFUNCTION(BlueprintCallable)
		void ShowChallenge(const FString& PlayerName, const int32& CanRefuseTime);
	// ��Ӧ��ս���
	UFUNCTION(BlueprintCallable)
		void ReplayLHMJChallenge(const int32& replay);

	// ��ս����ʾ ��ս��Ӧ
	UFUNCTION(BlueprintCallable)
		void onRequestLHMJChallengeReply(const int32& Replay, const FString& PlayerName, const int32& IsPlunder);

	// ��ʾ����ս�ߵĶ�����Ϣ
	void ShowChallengeMsg(const FVariant& DFVar, const int32& lineNumber, const FVector& Position);
	// �Զ�Ѱ·�� ����ս�Ķ���
	UFUNCTION(BlueprintCallable)
		void AutoGotoChallengeSpace();

	// ��ҵĶ�����Ϣ
	void InitDongFuData(const FVariant& DFVar, const int32& lineNumber, const FVector& Position);
	// �Զ�Ѱ·�� �Լ��Ķ���
	UFUNCTION(BlueprintCallable)
		void AutoGotoDFSpace();

	/**
	*B ��������
	*@param	IsChallengeActive ��0���Ӷ�ս��1������ս��
	*@param	Result  ������0������ʧ�ܣ�1������ʤ����2���ط�ʧ�ܣ�3���ط�ʤ����4����һ�׶��ط�ʤ����5����һ�׶ι���ʧ�ܣ�
	*@param	RwItemStr ������Ʒ  ��ʽ����ƷID:����|��ƷID:����|��ƷID:���� (���磺101040128:1|101040129:2|101040130:3|)
	*@param	RwMoney  ������Ǯ
	*@param	RwPsychic ��������
	*@param	DestroyBuilds ���ƻ��Ľ���
	*@param	CombatTime �ʱ��
	*@param	DeadCount ��������
	*@return ��
	*/
	void OnShowDFActtiveResult(const int8 IsChallengeActive, const int8 Result, const FString& RwItemStr, const int32& RwMoney, const int32& RwPsychic, const TArray<FVariant>& DestroyBuilds_, const int32& CombatTime, const int32& DeadCount);
	
	// ��������
	//*@param	IsPlunderActive ��1���Ӷ�ս��0������ս��
	void onDFActiveStart(const uint8 IsPlunderActive, const FString& PlayerName);
	// �����
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleLunHuiMiJinInterface")
		void onDFActiveEnd();

	// ��ս���ı����ֳ���
	void NoticeMECEnter(const int32& EntityID_);
	// ��ʾ�����Ѫ����Ϣ
	void initDFMonsterInfo(const TArray<FVariant>& EntityIDList);
	void addDFMonsterInfo(const int32& EntityID_);

	// ռ�춴��
	UFUNCTION(BlueprintCallable)
		void OnOccupyPlayerDF(const int32& IsOccupy);
	// ռ�춴���ص�
	void OnOccupyPlayerDFCB(const uint16 MsgID, const FString& PlayerName);
	// ������ռ����
	void OnDFBeingOccupy();


	//�ӿڷ���   ���޸��������档itemVar Ϊ�޸�������Ҫ���ĵ���Ʒ��ʽ{itemID��amount��...}
	void OpenRepairBuildUI(const int32& buildType, const FVariant& itemVar);
	// ֪ͨ��������ʼ�޸�����
	UFUNCTION(BlueprintCallable)
		void repairDFBuild(const int32& buildType);
	// �޸��Ľ����ص�
	UFUNCTION(BlueprintCallable)
		void OnBeginRepairDFBuild(const int32& buildType, const int32& fixedTime);
	// �����޸����
	void OnRepairDFBuildFinish(const int32& buildType);
	// ��ȡ�𻵵Ľ���
	UFUNCTION(BlueprintCallable)
		void GetDestroyBuilds(TArray<int32>& BuildArr);
	// �����Ƿ���
	UFUNCTION(BlueprintCallable)
		bool IsDestroyBuild(LHMJ_BUILD_TYPE buildType);
	// ��ȡ�޸�������Ҫ�Ĳ���
	UFUNCTION(BlueprintCallable)
		void GetFixBuildCost(const int32& buildType, TMap<int32, int32>& ItemMap);

	// ��ʾ����������ʾ
	void ShowUpgradeGuardMsg(const int32& MegID, const int32& LingNeng, const int32& MonsterID, int8 mType);
	// ȷ������������ʾ
	void UpgradeDFGurard(const int32& MonsterID, int8 mType);

public:
	virtual void InitBlueCB() override;

	// ��� ��ʱ������������
	void BeginAddPsionicTime();
	void AddPsionicPerTime();
	void ClearPsionicTime();

private:
	//������������ʱ
	void UpdateRemainUpLevelTime();

	//�޸���������ʱ
	void UpdateRemainRepairTime();

	// ��ʼ����������
	void _initDongFuDatas(const int32& LineNumber, const FVariant& DFVariant, TArray<FDongFuData>& Datas);
	void _initDongFuData(const FVariant& DFVariant, FDongFuData & Data);
	void _getDongFuDataByPage(const int32& LineNumber, const int32& Page, TArray<FDongFuData>& DongFuArr);

	// �������ս���ı����ֵľ��룬С��15������ʾmsg
	void CheckDistWithMEC();

public:
	/// ռ�е�����
	UPROPERTY(BlueprintReadOnly)
		LHMJ_SPACE_TYPE OccupySpaceType;
	/// �����ȼ�
	UPROPERTY(BlueprintReadOnly)
		TMap<LHMJ_BUILD_TYPE, int32> Builds;
	/// ��Ȫ������ȫ��������
	UPROPERTY(BlueprintReadOnly)
		int32 caveHousePsionicSum;
	/// ��Ȫ��ǰѪ��
	UPROPERTY(BlueprintReadOnly)
		int32 lingQuanCurrHP;

	//��ǰ�������������죩�Ľ�������
	UPROPERTY(BlueprintReadOnly)
		LHMJ_BUILD_TYPE UpLevelBuildType;
	//��ǰ�������������죩�Ľ����Ľ���ʱ��
	UPROPERTY(BlueprintReadOnly)
		float RemainUpLevelTime;

	//��ǰ�����޸��Ľ�������
	UPROPERTY(BlueprintReadOnly)
		LHMJ_BUILD_TYPE RepairBuildType;
	//��ǰ�����޸��Ľ����Ľ���ʱ��
	UPROPERTY(BlueprintReadOnly)
		float RemainRepairTime;

	///��ǰ�������ͼID��Ϊ0��ǰû�м������ͼ��
	UPROPERTY(BlueprintReadOnly)
		int32 ActiveBattleFormationsID;
	///��ǰ�������ͼ������HP
	UPROPERTY(BlueprintReadOnly)
		int32 BattleFormationsHP;

	// ���������� ��ʽ�� {�ڼ��� �� ����������}
	UPROPERTY(BlueprintReadOnly)
		TMap<int32, FDongFuData_Map> DongFuDataMaps;
	// ����ս�Ķ�������
	UPROPERTY(BlueprintReadOnly)
		FDongFuData ChallengeDFData;
	// �Լ��Ķ�������
	UPROPERTY(BlueprintReadOnly)
		FDongFuData DFData;
	/// ��ս�Ķ��� ��·
	UPROPERTY(BlueprintReadOnly)
		int32 ChallengeLineNumber;
	/// �Լ��Ķ��� ��·
	UPROPERTY(BlueprintReadOnly)
		int32 DFLineNumber;
	// ��ս����������
	UPROPERTY(BlueprintReadOnly)
		FVector ChallengeDFPos;				
	
private:
	// ���ƻ��Ľ��� ��ʽ�磺{buildType : { itemID : amount}}
	TMap<int32, TMap<int32, int32>> DestroyBuilds;

	FTimerHandle AddPsionicTimer;
	FTimerHandle UpLevelTimerHandle;
	FTimerHandle RepairTimerHandle;

	int32 RequestPage;					// ��������ĵ�ǰҳ����������������ݻ�û���ؾ� ����ȥ����
	int32 RequestLineNumber;
	FVector DFPos;						// �Լ�����������

	bool BActivityStart;				// ��Ƿ���
	int32 MExtCoverID;					// ��ս���ı�����entityID
	FTimerHandle CheckDistTimerHandle;
};