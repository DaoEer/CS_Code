#pragma once
#include "Interface/NPC/NPCInterface.h"
#include "NPCTrainSoldierGroundInterface.generated.h"

/*
* �ļ����ƣ�NPCTrainSoldierGroundInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-04-16
*/
/**
*������NPC�ӿ���
*/

UENUM(BlueprintType)
enum class  NPCTRAINSOLDIERGROUND_STATE: uint8
{
	///���ɱ���ս
	NPCTRAINSOLDIERGROUND_STATE_CAN_NOT_BE_DECLARE = 0 UMETA(DisplayName = "NPCTRAINSOLDIERGROUND_STATE_CAN_NOT_BE_DECLARE"),
	///�ɱ���ս
	NPCTRAINSOLDIERGROUND_STATE_CAN_BE_DECLARE = 1 UMETA(DisplayName = "NPCTRAINSOLDIERGROUND_STATE_CAN_BE_DECLARE"),
	///������
	NPCTRAINSOLDIERGROUND_STATE_FIGHT = 2 UMETA(DisplayName = "NPCTRAINSOLDIERGROUND_STATE_FIGHT"),
};

UENUM(BlueprintType)
enum class  NPCTRAINSOLDIERGROUND_TYPE : uint8
{
	/// ������
	NPCTRAINSOLDIERGROUND_TYPE_NONE = 0 UMETA(DisplayName = "NPCTRAINSOLDIERGROUND_TYPE_NONE"),
	/// ����������
	NPCTRAINSOLDIERGROUND_TYPE_LOW_LEVEL = 1 UMETA(DisplayName = "NPCTRAINSOLDIERGROUND_TYPE_LOW_LEVEL"),
	/// �м�������
	NPCTRAINSOLDIERGROUND_TYPE_MIDDLE_LEVEL = 2 UMETA(DisplayName = "NPCTRAINSOLDIERGROUND_TYPE_MIDDLE_LEVEL"),
	/// �߼�������
	NPCTRAINSOLDIERGROUND_TYPE_HIGH_LEVEL = 3 UMETA(DisplayName = "NPCTRAINSOLDIERGROUND_TYPE_HIGH_LEVEL"),
};

UCLASS(BlueprintType)
class CHUANGSHI_API UNPCTrainSoldierGroundInterface : public UNPCInterface
{
	GENERATED_BODY()
		typedef UNPCInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UNPCTrainSoldierGroundInterface();
	~UNPCTrainSoldierGroundInterface();
	static FString GetName() { return TEXT("NPCTrainSoldierGroundInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.NPCTrainSoldierGroundInterface'"); } //��ȡ��ͼ����·��

	void Set_lineNumber(const int32& newVal, const int32& oldVal);
	void Set_index(const int32& newVal, const int32& oldVal);
	void Set_occupyPlayerName(const FString& newVal, const FString& oldVal);;
	void Set_declareWarState(const uint8& newVal, const uint8& oldVal);
	void Set_fightEndTime(const FString& newVal, const FString& oldVal);
	void Set_trainGroundType(const uint8& newVal, const uint8& oldVal);
	void Set_occupyPlayerDBID(const uint64& newVal, const uint64& oldVal);

	void CLIENT_CreateTrainSoldierGroundArea(const FString& InScriptID, uint8 IsOwnSide);

	UFUNCTION(BlueprintCallable, Category = "NPCTrainSoldierGroundInterface")
		int32 GetTrainSoldierGroundLineNumber();

	UFUNCTION(BlueprintCallable, Category = "NPCTrainSoldierGroundInterface")
		int32 GetTrainSoldierGroundIndex();

	UFUNCTION(BlueprintCallable, Category = "NPCTrainSoldierGroundInterface")
		FString GetTrainSoldierGroundOccupyPlayerName();

	UFUNCTION(BlueprintCallable, Category = "NPCTrainSoldierGroundInterface")
		NPCTRAINSOLDIERGROUND_STATE GetTrainSoldierGroundState();

	UFUNCTION(BlueprintCallable, Category = "NPCTrainSoldierGroundInterface")
		FString GetTrainSoldierGroundFightEndTime();

	UFUNCTION(BlueprintCallable, Category = "NPCTrainSoldierGroundInterface")
		NPCTRAINSOLDIERGROUND_TYPE GetTrainGroundType();

private:
	int32 lineNumber; ///< ���������ڷ���
	int32 index; ///< ���������
	NPCTRAINSOLDIERGROUND_TYPE TrainGroundType;
	FString occupyPlayerName; ///< ռ���������
	NPCTRAINSOLDIERGROUND_STATE declareWarState; ///< ������״̬
	FString fightEndTime; ///< ս������ʱ��
};