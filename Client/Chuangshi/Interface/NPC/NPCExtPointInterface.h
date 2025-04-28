#pragma once
#include "Interface/NPC/NPCInterface.h"
#include "GameData/BHZBData.h"
#include "NPCExtPointInterface.generated.h"

/*
* �ļ����ƣ�NPCExtPointInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-05-20
*/
/**
*������Ծݵ�
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UNPCExtPointInterface : public UNPCInterface
{
	GENERATED_BODY()
		typedef UNPCInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UNPCExtPointInterface();
	~UNPCExtPointInterface();
	static FString GetName() { return TEXT("NPCExtPointInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.NPCExtPointInterface'"); } //��ȡ��ͼ����·��

	void Set_index(const int32& newVal, const int32& oldVal);
	void Set_occupyPlayerName(const FString& newVal, const FString& oldVal);
	void Set_occupyTongName(const FString& newVal, const FString& oldVal);
	void Set_declareWarState(const uint8& newVal, const uint8& oldVal);
	void Set_fightEndTime(const FString& newVal, const FString& oldVal);
	void Set_restEndTime(const FString& newVal, const FString& oldVal);
	void Set_pointType(const uint8& newVal, const uint8& oldVal);

	UFUNCTION(BlueprintCallable, Category = "NPCExtPointInterface")
		int32 GetNPCEXTPointIndex();

	UFUNCTION(BlueprintCallable, Category = "NPCExtPointInterface")
		FString GetNPCEXTPointOccupyPlayerName();

	UFUNCTION(BlueprintCallable, Category = "NPCExtPointInterface")
		FString GetNPCEXTPointOccupyTongName();

	UFUNCTION(BlueprintCallable, Category = "NPCExtPointInterface")
		NPCEXTPOINT_STATE GetNPCEXTPointState();

	UFUNCTION(BlueprintCallable, Category = "NPCExtPointInterface")
		FString GetNPCEXTPointFightEndTime();

	UFUNCTION(BlueprintCallable, Category = "NPCExtPointInterface")
		FString GetNPCEXTPointRestEndTime();

	UFUNCTION(BlueprintCallable, Category = "NPCExtPointInterface")
		NPCEXTPOINT_TYPE GetNPCEXTPointType();

private:
	int32 index; ///< �ݵ���
	FString occupyPlayerName; ///< ռ���������
	FString occupyTongName; ///< ռ��������
	NPCEXTPOINT_STATE declareWarState; ///< �ݵ�״̬
	FString fightEndTime; ///< ս������ʱ��
	FString restEndTime; ///< ��������ʱ��
	NPCEXTPOINT_TYPE pointType; ///< �ݵ�����
};