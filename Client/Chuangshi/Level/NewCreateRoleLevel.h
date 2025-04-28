// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Level/CS3LevelScriptActor.h"
#include "GameData/CharacterData.h"
#include "GameData/RoleInfo.h"
#include "NewCreateRoleLevel.generated.h"

/**
 * 
 */
class ALoginCharacter;

UCLASS()
class CHUANGSHI_API ANewCreateRoleLevel : public ACS3LevelScriptActor
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void CreateDynamicRes() override;
	virtual void OnCreateModelFinished() override;
	//virtual void OnLoadLevelFinished() override;
	void ChangeCreateRole(ROLE_PROFESSION_ENUM Job, ROLE_GENDER_ENUM Gender);

	void CloseLoadingWidget();///�رռ��ؽ�����
	ALoginCharacter* SPawnBPAccount(FROLEINFO RoleInfo);

private:

	UFUNCTION()
		void LoadBlockStreamLevelCreateRoleFinished();

	void OpenSelectRole();

	//��ȡѡ�е�����FRoleCreateUIData��rowName[ͨ��ְҵ+�Ա�+��Ӫת������]
	int32 GetSelectIndex();

public:
	//�ĸ�ְҵ��ɫģ���б�
	UPROPERTY(BlueprintReadOnly, Category = "ANewCreateRoleLevel")
		TArray<AActor*> ProfessionActors;

	//ѡ�е�ְҵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ANewCreateRoleLevel")
		ROLE_PROFESSION_ENUM SelectRoleProfessionID = ROLE_PROFESSION_ENUM::ROLE_PROFESSION_TYPE_ZHAN_SHI;

	//ѡ�е��Ա�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ANewCreateRoleLevel")
		ROLE_GENDER_ENUM SelectGender = ROLE_GENDER_ENUM::ROLE_GENDER_TYPE_MALE;

private:
	int32 LoadLevelIndex = 0;//�����ĸ��ؿ���ɼ�¼
	int32 CreateFinishCount = 0;//�����ĸ�ְҵ��ɼ�¼
	
	UPROPERTY()
		TMap<int32, AActor *> CreateRoleCameras;//key ��Ӫ+ְҵ

};
