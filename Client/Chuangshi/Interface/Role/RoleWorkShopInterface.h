// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3Base/CS3EntityInterface.h"
#include "GameData/Item/ToolCost.h"
#include "RoleWorkShopInterface.generated.h"

/*
* �ļ����ƣ�RoleWorkShopInterface.h
* ����˵�����ֻ��ؾ�����ӿ�
* �ļ����ߣ�chengdongyong
* Ŀǰά����chengdongyong
* ����ʱ�䣺2020-03-06
*/
UENUM(BlueprintType)
enum class COMPOSE_TYPE :uint8
{
	// ��
	COMPOSE_TYPE_NONE = 0,
	// ���ߴ���
	COMPOSE_TYPE_TOOL = 1,
	// ��װ����
	COMPOSE_TYPE_GEQUIP = 2,
	// Ǭ��������
	COMPOSE_TYPE_TRIPOD = 3,
};




UCLASS()
class CHUANGSHI_API URoleWorkShopInterface : public UCS3EntityInterface
{
	GENERATED_BODY()


public:
	static FString GetName() { return TEXT("RoleWorkShopInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleWorkShopInterface.BP_RoleWorkShopInterface_C'"); } //��ȡ��ͼ����·��

	virtual void OnEnterScenes() override;///<��ʼ����

	/**
	*BlueprintNativeEvent,���ߴ���������ݣ����򿪽���
	*
	*@param ComposeType  1Ϊ���ߴ��죬2Ϊ��װ���죬3ΪǬ��������
	*@param EndTime ��ǰ�������ʱ�䡣ʹ��FromServerTimeToClientTimeת��
	*@param ItemID ��ǰ�������ƷID���޴�����ƷΪ0��
	*@param UnlockNum ������������������������Ʒ��rolekitbaginterface��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_onRequestComposeData(const int32& ComposeType, const int32& EndTime, const int32& ItemID, const int32& UnlockNum, const int32& NPCID);
	// ��װ�������� SuccessRate:��װ����ɹ��ʣ�90.9��Ϊ 90.9%��
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_onRequestGEComposeData(const int32& ComposeType, const int32& EndTime, const int32& ItemID, const int32& UnlockNum, const float& SuccessRate, const int32& NPCID);

	// ����ص� ComposeType�� 1Ϊ���ߴ��죬2Ϊ��װ���죬3ΪǬ��������
	UFUNCTION(BlueprintNativeEvent, Category = "ComposeEquip")
		void CLIENT_beginComposeTool(const int32& ComposeType, const int32& ItemID, const int32& EndTime);
	// ��װ����ص� SuccessRate:��װ����ɹ��ʣ�90.9��Ϊ 90.9%��
	UFUNCTION(BlueprintNativeEvent, Category = "ComposeEquip")
		void CLIENT_beginGEComposeTool(const int32& ComposeType, const int32& ItemID, const int32& EndTime, const float& SuccessRate);
	// ���ߴ�����ɻص�ComposeType  1Ϊ���ߴ��죬2Ϊ��װ���죬3ΪǬ��������
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_OnFinishCompose(const int32& ComposeType, const int32& ItemID, const int32& Result);

	// ռ���ֻ��ؾ�spaceType�ı�
	void OnOccypySpaceTypeChange(const enum LHMJ_SPACE_TYPE & _spaceType);

	// ��ȡ��ǰ�������ı���
	UFUNCTION(BlueprintCallable)
		float GetBuildConsumeRate(const enum LHMJ_BUILD_TYPE & _buildType);
	// ��ȡ�������ɹ��ʺ����ı���
	UFUNCTION(BlueprintCallable)
		void GetBuildSuccessRate(LHMJ_BUILD_TYPE BuildType, int32 ComposeType, int32& SuccessRate, int32& ConsumeRate);

	/// ��ȡ�����ܴ��켸��
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		int32 GetComposeToolNum(const int32& ItemID);
	/// ��ȡ��װ�ܴ��켸�� 
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		int32 GetComposeGEquipNum(const int32& ItemID);
	/// ��ȡǬ�����ܴ��켸��
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		int32 GetComposeTripodNum(const int32& ItemID);
	/// ������ƷID�����ڽ��� ��ʾ��������ʽ,����Ʒ�ʣ�������ƷID��
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		void SortItemIDs(TArray<int32> InputItemIDArr, TArray<int32>& ItemIDArr);

	// ���칤��(����ID��Ҳ��װ����ID) composeType:1Ϊ���ߴ��죬3ΪǬ��������
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		void ComposeTool(const int32& ComposeType, const int32& EquipID, bool bUseUnbind);
	// ������װ BPrintUID:ʹ��ͼֽ��UID
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		void ComposeGreedEquip(const int32& EquipID, bool bUseUnbind, const FString& BPrintUID);

	// ͼֽ���� BPrintUID:ͼֽ��UID(һ�������������װ��UID����RoleKitBagInteface::GetMeltingEquipUID)
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		void MeltingGreedEquip(const FString& BPrintUID, const TArray<FString> EquipUIDArr);
	// ����ص� AddRate���������ӵĳɹ��ʣ���ֵ��0~100֮�䣡 ��ֵ��10.0������10.0%��
	UFUNCTION(BlueprintNativeEvent, Category = "ComposeEquip")
		void CLIENT_onMeltingtEquip(const FString& BPrintUID, const float& AddRate);

	// �������������ʱ���
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		void RequestPrayTimes();
	// ��ȡ������ ����ʱ��λ���루����ʱ������������Ҫ����RequestPrayTimes��
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		int32 GetReflashTime();
	// ����ص� ProyNum���Ѿ����Ĵ�����ʣ���������=10-ProyNum
	UFUNCTION(BlueprintNativeEvent, Category = "ComposeEquip")
		void CLIENT_OnRequestPrayTimes(const TArray<int32>& ProyTimeArr, const int32& ProyNum);
	// ��ʼ��
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		void BeginPrayComposeTimes();
	// ���ص� ʣ������������Ҫ��1
	UFUNCTION(BlueprintNativeEvent, Category = "ComposeEquip")
		void CLIENT_OnPrayTime(const int32& ProyTime);

	// ��װ����������
	UFUNCTION(BlueprintNativeEvent, Category = "ComposeEquip")
		void CLIENT_OpenQuenchingEquip(const int32& NPCID);
	// װ������
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		void QuenchingEquip(const FString& EquipUID);
	// �����ص� NewProperty:������װ��������
	UFUNCTION(BlueprintNativeEvent, Category = "ComposeEquip")
		void CLIENT_OnQuenchingEquip(const FString& EquipUID);

	// �Ӵ����ȡ��Ʒ���������Ʒ��RoleKitbagInteface::CLIENT_addStoreItem\CLIENT_removeStoreItem��
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		void RequestTakeToolItem(const int32& Order);

	virtual void InitBlueCB() override;

public:
	// ���ݴ������ͻ�ȡ��Ʒ�����б�
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		TArray<FString> GetCategoryNameList(COMPOSE_TYPE ComposeType);

	// ��ȡĳ�����µĹ��ߴ�������
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		TArray<int32> GetToolIDList(FString LabelName);
	// ��ȡĳ�����µ���װ��������
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		TArray<int32> GetEquipIDList(FString LabelName);
	// ��ȡĳ�����µ�Ǭ��������
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		TArray<int32> GetTripodIDList(FString LabelName);

	// �Ƿ��ڴ�����
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		bool CheckComposeState(COMPOSE_TYPE ComposeType, float& RemainTime);

	// ��ȡ��������ʱ��
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		float GetComposeTotalTime(COMPOSE_TYPE ComposeType, int32 ComposeItemID);

	// ��ȡ�������ӵĳɹ���
	UFUNCTION(BlueprintCallable, Category = "ComposeEquip")
		float GetMeltingEquipSuccessRate(FString BlueprintUID, TArray<FString> EquipUIDs);

private:
	void _InitToolConfig();
	void _InitTripodConfig();

public:
	//��ǰ���ڴ���Ĺ������ͣ�ֻ��¼���ߴ���\��װ������¼Ǭ������
	UPROPERTY(BlueprintReadOnly)
		COMPOSE_TYPE ToolComposeType;
	//����Ĺ��߽���ʱ��
	UPROPERTY(BlueprintReadOnly)
		FDateTime ToolComposeEndTime;

	// ���ߴ�������
	UPROPERTY(BlueprintReadOnly)
		TMap<int32, FToolComposeCost> ToolComposeCost;
	// ��װ��������
	UPROPERTY(BlueprintReadOnly)
		TMap<int32, FGreenEquipComposeCost> GEquipComposeCost;
	// ��������
	UPROPERTY(BlueprintReadOnly)
		TArray<FMeltingEquipCost> MeltingEquipCfg;

	//Ǭ�����������ʱ��
	UPROPERTY(BlueprintReadOnly)
		FDateTime TripodComposeEndTime;
	// Ǭ������������
	UPROPERTY(BlueprintReadOnly)
		TMap<int32, FTripodComposeCost> TripodComposeCost;

private:
	int32 _ProyNum;			// ������
	LHMJ_SPACE_TYPE spaceType;

};
