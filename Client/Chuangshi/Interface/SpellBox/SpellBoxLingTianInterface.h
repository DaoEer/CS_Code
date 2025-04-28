// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Interface/SpellBox/SpellBoxInterface.h"
#include "GameData/LingTianPlantData.h"
#include "SpellBoxLingTianInterface.generated.h"

/*
* �ļ����ƣ�SpellBoxLingTianInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2020-04-23
*/

UCLASS(BlueprintType)
class CHUANGSHI_API USpellBoxLingTianInterface : public USpellBoxInterface
{
	GENERATED_BODY()
		typedef USpellBoxInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()

public:
	USpellBoxLingTianInterface();
	~USpellBoxLingTianInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.SpellBoxLingTianInterface'"); } //��ȡ��ͼ����·��

	void Set_clientSeedNum(const int32& newVal, const int32& oldVal);
	void Set_clientGrowthStage(const int32& newVal, const int32& oldVal);

public:
	///����ֲ����UI
	void ShowLingTianPlantUI(const int32& entityID);

	///�򿪳ɳ���Ϣ����UI
	void ShowGrowUpMsgUI(const int32& entityID, const FString& endTimeStr);

	///�����ֲ��ť֪ͨ
	UFUNCTION(BlueprintCallable, Category = "SpellBoxLingTianInterface")
	void RPC_onClickPlant(int32 ItemID);

	///��ȡ��������
	UFUNCTION(BlueprintCallable)
		void GetLingTianSeedData(FString &seedIcon, FString &seedName);
	
	///��ȡ�����б�
	UFUNCTION(BlueprintCallable, Category = "SpellBoxLingTianInterface")
		TArray<int32> GetSeedIDList();

	// ��ȡ��ǰ���ӵ������׶�����(��Ϊ������ �������һ�׶��õ�ģ��һ��)
	UFUNCTION(BlueprintCallable)
		FGROWTHSTAGEMODELNUMBER GetCurSeedGrowData();

	// ģ�ʹ�����ɻص�
	UFUNCTION(BlueprintCallable)
		void OnCreateModelFinish();
private:
	///��ʼ����������
	void InitLingTianSeedData();

	void BeginCreateMesh();
	void CheckMeshComponent(const TArray<FVector>& PosList);
	void CreateApperaance(const FString& ModelID);

public:
	/// ��������
	UPROPERTY(BlueprintReadOnly)
		int32 seedNum;

	///�����׶�
	UPROPERTY(BlueprintReadOnly)
		int32 growthStage;

	//����ʱ��
	UPROPERTY(BlueprintReadOnly)
		FString endStrTime;

	///��������
	TMap<int32, FLING_TIAN_PLANT_DATA*> seedData;

	UPROPERTY(BlueprintReadOnly)
		UStaticMesh* TempMesh;

	bool ModelIsCreate;
private:
	TArray<UStaticMeshComponent*> CropMeshComponents;
	//TArray<UStaticMesh*> MeshArr;
	FTimerHandle DelayCreateHandle;				// �ӳ����ɣ���Ϊ��Ҫ�������� �� �׶����� �������ɵ�ģ��
	int32 CurCreateMeshIndex;

	
};
