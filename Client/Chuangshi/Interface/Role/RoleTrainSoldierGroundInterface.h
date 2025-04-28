// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CS3Base/CS3EntityInterface.h"
#include "GameData/Barracks/RoleArmyData.h"
#include "GameData/TrainSoldierGroundAreaCfg.h"
#include "RoleTrainSoldierGroundInterface.generated.h"


/*
* �ļ����ƣ�RoleTrainSoldierGroundInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-04-18
*/

/**
 * �������������
 */
UCLASS(BlueprintType)
class CHUANGSHI_API URoleTrainSoldierGroundInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleTrainSoldierGroundInterface();
	~URoleTrainSoldierGroundInterface();
	static FString GetName() { return TEXT("RoleTrainSoldierGroundInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleTrainSoldierGroundInterface.BP_RoleTrainSoldierGroundInterface_C'"); } //��ȡ��ͼ����·��

	/// ���������������
	void OpenTrainSoldierGroundDetails(const FString& name, int32 lineNumber, uint8 npcState, const FVariant& warNameList, const FVariant& warProfessionList, int32 isTrainSoldier, uint8 trainGroundType ,int32 npcID, const FString& notifyFightTime, uint8 isCanClickCancelDec);

	//�������� ��ս
	UFUNCTION(BlueprintCallable)
	void DeclareTrainSoldierGround(const int32& npcID);

	//�������� ������ս
	UFUNCTION(BlueprintCallable)
	void CancelDeclareTrainSoldierGround(const int32& npcID);

	// ������������������
	UFUNCTION(BlueprintCallable)
		void RequestTrainGroundQuest();
	/**
	*
	*@param NPCID �Ի���npcID
	*@param TGQuestList ����������
	*@param SuccessQuestIndex ��ɵ����񣨳ɹ���(����ֵ����ӦTGQuestList������ID)
	*@param FailQuestIndex ��ɵ�����ʧ�ܣ�(����ֵ����ӦTGQuestList������ID)
	*@param DoingQuestIndex ������������(����ֵ����ӦTGQuestList������ID)
	*@param QuestVar ��������
	*
	*@return ��
	*/
	void CLIENT_initTrainGroundQuest(const int32& NPCID, const TArray<FVariant>& TGQuestList, const TArray<FVariant>& SuccessQuestIndex, const TArray<FVariant>& FailQuestIndex, const TArray<FVariant>& DoingQuestIndex, const TArray<FVariant>& QuestVar);
	UFUNCTION(BlueprintCallable)
		bool GetTrainGroundQuestByID(int32 QuestID, FTRAIN_GROUND_QUEST& OutTrainFroundQuest);
	//�����������״̬State 0:δ��ȡ,1:���ڽ��У�2:�����,3:��ʧ�ܣ�
	UFUNCTION(BlueprintCallable)
		int32 GetTrainGroundQuestState(int32 Index);
	// �ֶ�ˢ������
	UFUNCTION(BlueprintCallable)
		void RequestRefreshTGQuest();
	// �Զ�ˢ��
	UFUNCTION(BlueprintCallable)
		void BeginCalculationAuToRefreshQuest();
	UFUNCTION(BlueprintCallable)
		void EndsCalculationAuToRefreshQuest();
	void AutoRefreshTGQuest();
	// ����ˢ�»ص�
	void CLIENT_OnRefreshTGQuest(const TArray<FVariant>& TGQuestList,const TArray<FVariant>& QuestVar);
	
	// ������������
	UFUNCTION(BlueprintCallable)
		void RequestAcceptTGQuest(const int32& Index, const int32& battackID);
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_OnAcceptTGQuest(const int32& Index, const int32& battackID);

	/** ���������� 
	*
	*@param Index �����б������
	*@param Result ������
	*@param Exp ��Ӫ����ܵľ���
	*@param addExp ����buff��ӵľ���
	*@param BattackID �ɳ����ӵ�id
	*@param LossNum ��ʧ�ı���
	*@param LossNum �Ƿ��Ѿ�ˢ�£����ܴ��ڣ������������������� ˢ���ˣ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_onTGQuestResult(const int32& Index, const int32& Result, const int32& Exp, const int32& addExp, const int32& BattackID, const int32& LossNum, const int32& BRefreshAlready);
	// ���������ص���Ӫ
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_onSoldierFinishQuestBack(const int32& BattackID);

	/**������������鿴����
	*@param roleOccupylineNumber ���ռ����߱��
	*@param roleOccupyIndex ���ռ�����������
	*@param AllGroundIndexs �÷����������������
	*@param AllGroundOccDBIDs �÷�������������ռ������DBID
	*@param maxLineNumber ��������
	*/
	void OpenAllGroundDetail(int32 roleOccupylineNumber, int32 roleOccupyIndex, const TArray<FVariant>& AllGroundIndexs, const TArray<FVariant>& AllGroundOccDBIDs, int32 maxLineNumber, int32 NpcID);

	void LoadTrainGroundAreaCfgData();

	// �����������������
	UFUNCTION(BlueprintCallable)
	FTRAIN_SOLDIER_GROUND_MAP_DATA GetTrainGroundCfgByIndex(int32 index);
	
	// ���������NPC������
	UFUNCTION(BlueprintCallable)
		FTrainSoldierGroundNpcData GetTrainGroundNPCCfgData(int32 index, int32 group);
	// ���������NPC������
	UFUNCTION(BlueprintCallable)
		FTrainSoldierGroundNpcData GetTrainGroundNPCCfgDataByGroup(int32 group);

	// �ж�������NPC�Ƿ�����
	UFUNCTION(BlueprintCallable)
		bool IsTrainGroundNPCNeutrally(int32 group);

	// �ж�������NPC�Ƿ���ռ��
	UFUNCTION(BlueprintCallable)
		bool IsTrainGroundNPCOccupy(int32 group);

	virtual void InitBlueCB() override;
	virtual void onLeaveWorld() override;
	// ǰ��ĳ��������
	UFUNCTION(BlueprintCallable)
	void RequestGotoTrainGroundByGroup(int32 lineNumber, int32 group, const FVector& position);

	//����ĳ�����ߵ���������������
	UFUNCTION(BlueprintCallable)
		void RequestAllGroundDetail(int32 lineNumber,int32 npcID);

	// �ͼ������� ��ʼ���������ͼ����(BattackVar����Ӫ���ݵ�����)
	void InitGTAttackDatas(const FVariant& BattackVar);
	// ��Ӫ���ݵ㣩��ռ��
	void occupyGTBarrack(const int8& BelongSide, const FString& ScriptID);

	// �ͼ������� ��ʼ���ط������ͼ����
	// @Param BattackVar����Ӫ���ݵ�����
	// @Param BatteryVar����������
	// @Param BattackVar���ɴ������꣨ue4���꣩
	// @Param TeleportCD������CDʱ��
	void InitGTProtectDatas(const FVariant& BattackVar, const FVariant& BatteryVar, const TArray<FVariant>& TeleportPos, const int32& TeleportCD_);
	// ���ڱ�����
	void onDestroyGTBattery(const int32& EntityID_);
	

	// �ط���ң����󹥷�λ�ã��߻����󣬴򿪴��ͼ��ÿ5������һ�Σ�
	UFUNCTION(BlueprintCallable)
		void RequestAttckPos();
	// �������ص�����λ�� ����ʾ ��սͼ�꣩
	void onRequestAttackPos(const FVector& Pos);
	// �������ص�����λ�� ������ʾ ��սͼ�꣩
	void onRequestAttackPosNone();

	// �ط���ң�������λ�� UE4���꣨������ͺ󣬴���ͼ���ûң�
	UFUNCTION(BlueprintCallable)
		void RequestTeleportPos(const FVector& TeleportPos);
	// ����CDʱ���ѹ�������ͼ��ɵ��
	void TeleportCDIsReady();

private:
	void initQuestDatas(const TArray<FVariant>& QuestVar);

	FTimerHandle AutoRefreshHandle;
	TMap<int32, TMap<int32, FTrainSoldierGroundNpcData>> TrainGroundNPCCfgData;
public:
	// �������� ����
	UPROPERTY(BluePrintReadOnly)
		TMap<int32, FTRAIN_GROUND_QUEST> TrainGroundQuestConfig;
	// �������� ID
	UPROPERTY(BluePrintReadOnly)
		TArray<int32> TGQuestIDArr;
	// �������� �ɹ���ɵ�����
	UPROPERTY(BluePrintReadOnly)
		TArray<int32> SuccessQuestIndexArr;
	// �������� ʧ����ɵ�����
	UPROPERTY(BluePrintReadOnly)
		TArray<int32> FailQuestIndexArr;
	// �������� ���ڽ������������
	UPROPERTY(BluePrintReadOnly)
		TArray<int32> DoingQuestIndexArr;

	UPROPERTY(BluePrintReadOnly)
		FString FightTime;
	UPROPERTY(BluePrintReadOnly)
		bool bCanClickCancelDec;
	UPROPERTY(BluePrintReadOnly)
		int32 RoleOccupylineNumber;
	UPROPERTY(BluePrintReadOnly)
		int32 RoleOccupyIndex;
	UPROPERTY(BluePrintReadOnly)
		TMap<int32, FString> AllGroundDict;
	UPROPERTY(BluePrintReadOnly)
		TMap<int32, FTRAIN_SOLDIER_GROUND_MAP_DATA> TrainGroundAreaCfg;

	// ��Ӫ���ݵ㣩��Ϣ
	UPROPERTY(BluePrintReadOnly)
		TMap<FString, FTG_BARRACK> BarrackDatas;
	// ������Ϣ
	UPROPERTY(BluePrintReadOnly)
		TMap<int32, FTG_BATTERY> BatteryDatas;
	//�Ƿ�Ϊ������
	UPROPERTY(BluePrintReadOnly)
		bool bIsBattack;



private:
	int32 TeleportCD;			// ����CD
};