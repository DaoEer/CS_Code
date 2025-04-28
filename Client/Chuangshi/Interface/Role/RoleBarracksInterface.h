// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CS3Base/CS3EntityInterface.h"
#include "../../GameData/Barracks/BarracksTableData.h"
#include "GameData/Barracks/RoleBarracksItemData.h"
#include "GameData/Barracks/RoleArmyData.h"
#include "GameData/Barracks/BarracksGuardSoldierSkillData.h"
#include "GameData/Barracks/BarracksReviveCostData.h"
#include "RoleBarracksInterface.generated.h"


/*
* �ļ����ƣ�RoleBarracksInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-12-23
*/

/**
 * ��ұ�Ӫ�ӿ�
 */
UCLASS(BlueprintType)
class CHUANGSHI_API URoleBarracksInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
	typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleBarracksInterface();
	~URoleBarracksInterface();
	static FString GetName() { return TEXT("RoleBarracksInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleBarracksInterface.BP_RoleBarracksInterface_C'"); } //��ȡ��ͼ����·��

	/**
	* BlueprintCallable������򿪱�Ӫ
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	void RequestOpenBarracks();

	/**
	* Define method
	* ��ʼ����ұ�Ӫ����
	*
	* @return ��
	*/
	void InitRoleBarracksDatas(const FVariant& Var);

	/**
	* Define method
	* ������ұ�Ӫ����
	*
	* @return ��
	*/
	void AddRoleBarracksData(const FVariant& Var);

	UFUNCTION(BlueprintImplementableEvent, Category = "RoleBarracksInterface")
	void OnAddRoleBarracksData(FROLEBARRACKSITEMDATA soldierData);

	/**
	* Define method
	* BlueprintNativeEvent����ʼ����ұ�Ӫ���ݽ���
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleBarracksInterface")
	void InitRoleBarracksDataOver(const int32& soldierType);

	void InitLoadBarracksCfgDatas(const int32& soldierType);

	void InitLoadBarracksSoldierSkillCfgDatas();

	void InitBarracksReviveCostDatas();
	/**
	* Define method
	* ��ʼ����Ҳ�������
	*
	* @return ��
	*/
	void InitRoleArmyDatas(const FVariant& Var);

	/**
	* Define method
	* ������Ҳ�������
	*
	* @return ��
	*/
	void SaveArmyDataCB(const FVariant& Var);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "RoleBarracksInterface")
		void OnSaveArmyDataCB(FROLEARMYDATA armyData);

	/**
	*
	* BlueprintCallable��ƽ�־����С��
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		void UpGradeGuardSoldierSkillLevel(const FString& scriptID, const int32& guardSoldierID, const int32& skillID, const int32& exp );
	/**
	* Define method
	* �������������������
	*
	* @return ��
	*/
	void OnUpdateGuardSoldierSkill(const FString& scriptID, const int32& soldierID,const int32& lastSkillID, const FVariant& Var);
	UFUNCTION(BlueprintImplementableEvent, Category = "RoleBarracksInterface")
		void OnUpdateGuardSoldierSkillBP(const FString& scriptID, const int32& soldierID, const int32& lastSkillID,FPASSIVESKILLDATA skillData);

	/**
	* Define method
	* BlueprintNativeEvent���Ƴ���ұ�Ӫ����
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleBarracksInterface")
		void RemoveRoleBarracksData(const FString& scriptID);

	/**
	* Define method
	* BlueprintNativeEvent���ѽ����ı�
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleBarracksInterface")
		void InitRoleBarracksUnLockSoldiers(const TArray<FString>& unLockSoldierScriptIDs);

	/**
	* Define method
	* BlueprintNativeEvent���Ƴ���ұ�Ӫ��������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleBarracksInterface")
	void RemoveRoleBarracksSoldierData(const FString& scriptID, const int32& soldierID);

	/**
	* Define method
	* BlueprintNativeEvent��������ұ�Ӫ���ĵȼ�����
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleBarracksInterface")
		void UpdateSoldierLevelData(const FString& scriptID, const int32& soldierID,const int32& level);

	/**
	* Define method
	* BlueprintNativeEvent��������ұ�Ӫ�����Ƿ��ڲ�������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleBarracksInterface")
		void UpdateSoldierIsInArmyData(const FString& scriptID, const int32& soldierID, const int32& isInArmy);


	/**
	* Define method
	* BlueprintNativeEvent���Ƿ񼤻��������ʱ��������Ҫ��һЩ�������������CST-10623 ���Ӫ���桪������/�ױ�����֮�󸴻�����
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleBarracksInterface")
		void UpdateSoldierIsActive(const FString& scriptID, const int32& soldierID, const int32& isActive);


	/**
	* Define method
	* BlueprintNativeEvent��������ұ�Ӫ���ľ�������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleBarracksInterface")
		void UpdateSoldierExpData(const FString& scriptID, const int32& soldierID, const int32& exp, const int32& maxExp);

	/**
	*
	* BlueprintCallable��������ļĳ����
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	void RequestBuyBarracksSoldier(ENUM_BARRACKS_SOLDIER_TYPE soldierType,const FString& scriptID,const int32& count);


	/**
	*
	* BlueprintCallable�����󸴻�ĳ������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		void RequestRevive(const FString& scriptID);

	/**
	*
	* BlueprintCallable����ȡ������Ҫ���ѵĽ�Ǯ
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		int32 GetReviveCost(const FString& scriptID, int32 level);

	/**
	*
	* BlueprintCallable��ƽ�־����С��
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		void DivideExpToSoldiers(ENUM_BARRACKS_SOLDIER_TYPE soldierType, const FString& scriptID,const int32& exp);


	/**
	*
	* BlueprintCallable���������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	void SaveArmyData(const int32& id,const FString& firstGuardScriptID, const FString& secondGuardScriptID, const FString& soldierScriptID, const TArray<int32>& soldierIDs);

	/**
	* 
	* BlueprintCallable�������ұ�Ӫ����
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	TArray<FROLEBARRACKSITEMDATA> GetRoleRarracksDatasByScriptID(const FString& scriptID);

	/**
	*
	* BlueprintCallable����ñ�Ӫ������������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	FBARRACKS_TABLE_DATA GetRarracksCfgDatasByScriptID(const ENUM_BARRACKS_SOLDIER_TYPE soldierType,const FString& scriptID);

	/**
	*
	* BlueprintCallable����ñ�Ӫĳ�����͵���������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	TArray<FBARRACKS_TABLE_DATA> GetRarracksCfgDatasBySoldierType(const ENUM_BARRACKS_SOLDIER_TYPE soldierType);

	/**
	*
	* BlueprintCallable�������Ҳ�������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	FROLEARMYDATA GetRoleArmyDatasByID(const int32& id);

	/**
	*
	* BlueprintCallable��������ĳ�����ͱ�������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		TArray<FROLEBARRACKSITEMDATA> GetRoleRarracksDatasBySoldierType(const ENUM_BARRACKS_SOLDIER_TYPE soldierType,const TArray<FString>& removeScriptIDs);

	/**
	*
	* BlueprintCallable�������ұ�������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		FString GetRoleBarracksExp();

	/**
	*
	* BlueprintCallable�������������һ���ļ�������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	TArray<FBARRACKS_GUARD_SOLDIER_SKILL_DATA> GetGuardSoldierFirstLevelSkillCfgData(const FString& scriptID);

	/**
	*
	* BlueprintCallable��ͨ������ID�����������������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		FBARRACKS_GUARD_SOLDIER_SKILL_DATA GetGuardSoldierSkillCfgDataBySkillID(const FString& scriptID, const int32& skillID);

	/**
	*barracksExp(��������)���Է������޸Ŀͻ����Զ����ú���
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		void OnRep_barracksExp();

	UFUNCTION(BlueprintImplementableEvent, Category = "RoleBarracksInterface")
	void OnBarracksExpChange();

	/**
	*BlueprintCallable ��õȼ������ĳ��ʿ�����б�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		TArray<FROLEBARRACKSITEMDATA> GetRoleRarracksDatasBySortLevel(const FString& scriptID, const TArray<int32>& removeSoldierIDs, const int32& count);

	/**
	*�����Ƿ����
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	bool CheckSoldierIsUnLock( const FString& scriptID);

	/**
	* ��ɢĳ֧����
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		void DismissArmyData(const int32& armyID);

	/**
	* Define method
	* BlueprintNativeEvent����ɢĳ֧���ӻص�
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleBarracksInterface")
		void CLIENT_OnDismissArmyData(const int32& armyID);


	// ���ӱ��ɳ�ȥ������
	void OnArmyDoQuest(const int32& armyID);
	// ���������� ���� ����
	void OnArmyDoQuestConsume(const int32& armyID, const int32& num);
	// �����������ص���Ӫ
	void OnArmyFinishQuestAndBack(const int32& armyID);

	virtual void onLeaveWorld() override;
	virtual void InitBlueCB() override;

	void ClearRoleBarracksData();

	int32 GetArmySoldierNumByScriptID(const FString& scriptID);

	/**
	* ������������Ӫ
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		void EnterTrainSoldierGround();

	void Set_isCanOpenBarracks(const uint8& newVal, const uint8& oldVal);

	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		bool IsCanOpenRoleBarracks();

	void InitBarracksByOccupyTrainGround(const FVariant& Var);

	void InitBarracksByOccupyTrainGroundOver(const int32& npcID, const int32& requireSoldierAmount, const int32& requireSoldierLevel);
	// ��ÿ�������ռ���С��scriptID
	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
	TArray<FString> GetCanUseOccupySoldierScriptID();

	UFUNCTION(BlueprintCallable, Category = "RoleBarracksInterface")
		void SureToOccupyTrainGround(const int32& npcID, const FString& soldierScriptID);

	UPROPERTY(BlueprintReadOnly)
	TMap<int32, FROLEARMYDATA> RoleArmyDatas;
	UPROPERTY(BlueprintReadOnly)
		TArray<FString> RoleUnLockSoldiers; ///<����ѽ����ı�
	UPROPERTY(BlueprintReadOnly)
		bool IsCanOpenBarracks; /// false ��ť�û�

	UPROPERTY(BlueprintReadOnly)
		int32 OccupySoldierAmount; ///  ռ����������ҪС������
	UPROPERTY(BlueprintReadOnly)
		int32 OccupySoldierLevel; /// ռ����������ҪС���ȼ�

private:
	TMap<ENUM_BARRACKS_SOLDIER_TYPE, TMap<FString, FBARRACKS_TABLE_DATA>> BarracksCfgDatas; //{�����ͣ�{��ScriptID:������}}
	TMap<FString, TArray<FROLEBARRACKSITEMDATA>> RoleBarracksDatas; //{��scriptID:[]}
	TMap<FString, TMap<int32, FBARRACKS_GUARD_SOLDIER_SKILL_DATA>> BarracksSoldierSkillCfgData; // {��ScriptID:{����ID:��������}}
	TMap<FString, TMap<uint32, uint32>> BarracksReviveCostDatas; 
};