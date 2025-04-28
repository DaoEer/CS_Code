// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/StateInterface.h"
#include "CMonsterStateInterface.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API UCMonsterStateInterface : public UStateInterface
{
	GENERATED_BODY()
	typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	static FString GetName() { return TEXT("StateInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_CMonsterStateInterface.BP_CMonsterStateInterface_C'"); } //��ȡ��ͼ����·��


};
