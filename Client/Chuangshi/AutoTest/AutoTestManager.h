// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "AutoTest/BaseTest/BaseProfile.h"
#include "AutoTestManager.generated.h"

/*
* �ļ����ƣ�AutoTestManager.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UAutoTestManager : public UObject
{
	GENERATED_BODY()
	
public:
	UAutoTestManager();
	static UAutoTestManager* GetInstance();
	
	UFUNCTION(BlueprintCallable, Category = "AutoTest")
	void StartFMO();

	UFUNCTION(BlueprintCallable, Category = "AutoTest")
		void StopFMO();

	UFUNCTION(BlueprintCallable, Category = "AutoTest")
		void PrintFMO();

public:
	UPROPERTY()
		UBaseProfile* Profile;
	bool bIsStartFMO = false;
	//static UAutoTestManager* Instance;
};
