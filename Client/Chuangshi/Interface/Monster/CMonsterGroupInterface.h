// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3Base/CS3EntityInterface.h"
#include "CMonsterGroupInterface.generated.h"

/**
* �ļ����ƣ�CMonsterGroupInterface.h
* ����˵�����ͻ��˼�Ⱥ����ӿ�
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2019-12-16
 */
UCLASS()
class CHUANGSHI_API UCMonsterGroupInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
	

public:
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.CMonsterGroupInterface'"); } //��ȡ��ͼ����·��
	//void ReceiveCMDFollow(FVector TargetPos)
};
