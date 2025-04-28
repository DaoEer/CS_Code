// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3Base/CS3EntityInterface.h"
#include "NPCAmbulantInterface.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API UNPCAmbulantInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
	typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()	
public:
	static FString GetName() { return TEXT("NPCAmbulantInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.NPCAmbulantInterface'"); } //��ȡ��ͼ����·��

};
