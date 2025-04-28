// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Level/CS3LevelScriptActor.h"
#include "PersonalizeLevel.generated.h"

/**
* �ļ����ƣ�PersonalizeLevel.h
* ����˵����
* �ļ����ߣ�linhaowen
* Ŀǰά����linhaowen
* ����ʱ�䣺2019-3-29
 */
UCLASS()
class CHUANGSHI_API APersonalizeLevel : public ACS3LevelScriptActor
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void CreateDynamicRes() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnLoadLevelFinished() override;


	void SetModifyCurrBone();

	//���û��ʣ������ؿ�ǿ����������
	void SetScreenPercentage();
	//�ָ�����
	void ResetScreenPercentage();

	//����Actor
	UPROPERTY(BlueprintReadOnly, Category = "CreateRoleLevel")
		AActor* ModifyFaceCharacter;
	
	UPROPERTY(BlueprintReadOnly, Category = "SelectRoleLevel")
		TArray<AActor*> AccountActors; ///<�����Ľ�ɫBP_Account���б�
};
