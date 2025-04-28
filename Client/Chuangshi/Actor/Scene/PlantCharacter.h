// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Scene/SceneCharacter.h"
#include "GameData/LingTianPlantData.h"
#include "PlantCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API APlantCharacter : public ASceneCharacter
{
	GENERATED_BODY()

		typedef ASceneCharacter Supper;

	APlantCharacter();
public:
	virtual void BeginPlay()override;
	void InitPlantData(const LINGTIAN_DATA PlantData_);

	void CreateAppearance();
	const FLING_TIAN_PLANT_DATA* GetCurLingTianData();

	// ��ȡ��ǰ���ӵ������׶�����(��Ϊ������ �������һ�׶��õ�ģ��һ��)
	FGROWTHSTAGEMODELNUMBER GetCurSeedGrowData(const FLING_TIAN_PLANT_DATA* curSeedData);

private:
	virtual void OnCreateApperanceOver() override;

	
	void CheckGrowthStage();
	// ����ͬ��һ�Σ�����ͻ���ģ��
	void AddGrowthStage();
	void BeginCreateMesh();
	void CheckMeshComponent(const TArray<FVector>& PosList);

public:
	UPROPERTY(BlueprintReadOnly)
		UStaticMesh* TempMesh;

private:
	// �������
	int32 seedNum;
	// �ɳ��׶�
	int8 growthStage;
	// �ý׶ο�ʼʱ�䣨��Ӧ������time.time()��
	uint32 growTime;

	TArray<UStaticMeshComponent*> CropMeshComponents;
	int32 CurCreateMeshIndex;

	FTimerHandle DelayGrowHandle;
};
