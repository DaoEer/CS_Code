// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AutoTest/BaseTest/BaseProfile.h"
#include "FMOProfile.generated.h"

/*
* �ļ����ƣ�FMOProfile.h
* ����˵����
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UFMOProfile : public UBaseProfile
{
	GENERATED_BODY()
	
public:
	UFMOProfile();
	virtual void LoadCfg() override;
	virtual void EndRecord() override;
	virtual void StartTickTask() override;

	
};
