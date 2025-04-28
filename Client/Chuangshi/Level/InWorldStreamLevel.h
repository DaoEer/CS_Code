// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Level/InWorldLevel.h"
#include "InWorldStreamLevel.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FLoadNextSubLevelFinishedDelegate, FString);///<

UCLASS(BlueprintType, Blueprintable)
class CHUANGSHI_API AInWorldStreamLevel : public AInWorldLevel
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	void ChangeToNextSubLevel(FName LevelName);///<�л��ӹؿ�

	bool GetIsNextSubLevelFinished() { return IsLoadNextSubLevelFinished; };
private:
	virtual void OnLoadLevelFinished() override;///<�ؿ��������

	void LoadDefaultSubLevel();///<����Ĭ���ӹؿ�
	UFUNCTION()
		void LoadDefaultSubLevelFinished();///<����Ĭ���ӹؿ����
	UFUNCTION()
		void DelayNotifyLoadDefaultSubLevelFinished();///<����Ĭ���ӹؿ����

	void LoadNextSubLevel(bool bIsShow = false);///<������һ���ӹؿ�
	UFUNCTION()
		void LoadNextSubLevelFinished();///<������һ���ӹؿ����

	void UnLoadSubLevelByLevelName(FName LevelName);///<ж���ӹؿ�
	UFUNCTION()
		void UnLoadSubLevelFinished();///<ж���ӹؿ����

	void LoadSubLevelByLevelName(const FName LevelName, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FName ExecutionFunction);///<�����ӹؿ�

	void UpdateSubLevelVisiblity(FName VisibleLevelName,FName InvisibleLevelName);///<�����ӹؿ��Ŀɼ���	
	UFUNCTION()
		void UpdateSubLevelVisiblityFinished(float FinishedTime=2.0f);///<��ʾ�ӹؿ����

	void SetNextSubLevelName();///<�����¸��ӹؿ�������

	UFUNCTION()
		void PostChangeInWorldOver();///<�л���InWard״̬���¼�
	bool IsCompareLevelManagerSubStreamLevel(FName LevelName);////<�Ƿ����LevelMananger��Level���Ƿ�Ϊ������

	void LoadLevelStreamingByLevelName(FName LevelName);///<���ذ���LevelName�����ؿ�

	void UpdateStreamingVolume();///<�����������

	void DelaySetInvisibleStreamingLevels();///<ÿһ֡����һ�����ؿ�
public:
	FLoadNextSubLevelFinishedDelegate LoadNextSubLevelFinishedDelegate;///<��һ���ӹؿ��������

private:
	FTimerHandle DelayNotifyLoadFinishedHandle;
	FString CurSubLevelName = TEXT("");///<��ǰ���ӹؿ�
	FString OldSubLevelName = TEXT("");///<ǰһ���ӹؿ�
	FString NextSubLevelName = TEXT("");///<��һ���ӹؿ�
	FString NewSubLevelName = TEXT("");///<�µ��ӹؿ�
	bool IsLoadNextSubLevelFinished = false;///<��һ���ӹؿ��Ƿ�������
	bool IsLoadSubLevelFinished = false;
	bool IsLoadStreamingLevel = false;///<�Ƿ�������������ؿ�
	FVector LastEntitypostion = FVector::ZeroVector;
	UPROPERTY()
		TArray<ULevelStreaming*> InvisibleStreamingLevels;
};
