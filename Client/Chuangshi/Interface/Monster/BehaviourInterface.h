// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3Base/CS3EntityInterface.h"
#include "BehaviourInterface.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API UBehaviourInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
	typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	static FString GetName() { return TEXT("BehaviourInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.BehaviourInterface'"); } //��ȡ��ͼ����·��	

	void BehClientSpell(const int32& skillID, const int32& targetID, const uint8& isGroupSkill);
	void BehClientSpellOver(const int32& skillID);

	bool GetIsUsingSkill();

public:
	bool IsUsingSkill = false;



};
