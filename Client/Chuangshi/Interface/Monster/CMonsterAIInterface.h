// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3Base/CS3EntityInterface.h"
#include "KBEngine.h"
#include "CMonsterAIInterface.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API UCMonsterAIInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
	typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	static FString GetName() { return TEXT("MonsterAIInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_CMonsterAIInterface.BP_CMonsterAIInterface_C'"); } //��ȡ��ͼ����·��	

	void Set_cMonsterAIState(const uint8& newVal, const uint8& oldVal); 
};
