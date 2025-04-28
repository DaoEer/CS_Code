// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Level/LoginSelectLevel.h"
#include "GameData/RoleCreateUIData.h"
#include "NewSelectRoleLevel.generated.h"

class ALoginCharacter;
/**
 * 
 */
UCLASS()
class CHUANGSHI_API ANewSelectRoleLevel : public ALoginSelectLevel
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void CreateDynamicRes() override;
	virtual void OnCreateModelFinished() override;
	//virtual void OnLoadLevelFinished() override;

	void ChangeSelectRole(const FString& DBID);

	UFUNCTION(BlueprintCallable, Category = "SelectRoleLevel")
		void AddAccountActor(FROLEINFO RoleInfo); ///<����һ����ɫ, -1��ʾ��Ҫ�Զ�����û��ʹ�õ�����

	UFUNCTION(BlueprintCallable, Category = "SelectRoleLevel")
		void OnAddAccount(const FString& DBID);

	UFUNCTION(BlueprintCallable, Category = "SelectRoleLevel")
		void OnDelAccount(const FString& DBID);

	ALoginCharacter* GetActorByDBID(const uint64& dbid);//ͨ��DBID��ȡBP_Account��Actor
	FROLEINFO GetRoleInfoByDBID(const uint64& dbid);

	void CloseLoadingWidget();///�رռ��ؽ�����
	void CloseWidgetByTimeOut();///���غ�30���Զ��رս�����
	void StopMediaSkip();

private:
	UFUNCTION()
		void  OnSelectRoleByTabKey();///<�ڽ�ɫѡ��ʱ��Tabѡ���ɫ

	UFUNCTION()
		void LoadBlockStreamLevelSelectFinished();///<���ؿ��ĸ������������

	UFUNCTION()
		void OpenSelectLevel(FRoleCreateUIData RoleCreateUIData);///<��ѡ�еĹؿ�

	UFUNCTION()
		void OpenSelectCamera(int32 Index, FRoleCreateUIData RoleCreateUIData);///<��ѡ�еĹؿ������

	UFUNCTION()
		void OpenSelectRole(FString Dbid);///<��ѡ�е�����ģ��
	
	uint64 GetLastLoginDBID();///<��ȡ��ǰ��¼��ɫ�ϴν�����Ϸ�Ľ�ɫ��DBID

	int32 GetRowIndex(int32 Profession, int32 Gender, int32 Camp);///��ȡѡ�е�����FRoleCreateUIData��rowName[ͨ��ְҵ+�Ա�+��Ӫת������]
	
public:
	UPROPERTY()
		TMap<int32, AActor *> CreateRoleCameras;//key ��Ӫ+ְҵ

	UPROPERTY(BlueprintReadOnly, Category = "SelectRoleLevel")
		TArray<AActor*> AccountActors; ///<�����Ľ�ɫBP_Account���б�

	UPROPERTY(BlueprintReadOnly, Category = "SelectRoleLevel")
		int32 CurrSelectIndex;	//��ǰ��һ����ɫ����������0��ʼ

	UPROPERTY(BlueprintReadOnly, Category = "SelectRoleLevel")
		FString CurrDBID;

	int32 CreateFinishCount; //����ģ�ͻص��Ĵ���

private:
	int32 LoadLevelIndex = 0;

};
