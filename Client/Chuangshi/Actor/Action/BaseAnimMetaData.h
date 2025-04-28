// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//UE4
#include "Animation/AnimMetaData.h"
#include "BaseAnimMetaData.generated.h"

/// �����������ж�����
UENUM(BlueprintType)
enum class ACTION_INTERRUPTED_ENUM : uint8
{
	ACTION_INTERRUPTED_STOP = 1 UMETA(DisplayName = "RoleProfessionZhanShi"),//��̫��ֹͣ
	ACTION_INTERRUPTED_OTHER = 2 UMETA(DisplayName = "RoleProfessionJianKe"),//�����ж�
};

/*
* �ļ����ƣ�BaseAnimMetaData.h
* ����˵������������Ԫ���ݣ�������ʶ���ݰ󶨵�����������
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2018-07-24
*/
UCLASS()
class CHUANGSHI_API UBaseAnimMetaData : public UAnimMetaData
{
	GENERATED_BODY()
public:
	void SetInterruptedType(ACTION_INTERRUPTED_ENUM InInterruptedType);
	ACTION_INTERRUPTED_ENUM GetInterruptedType();

private:
	ACTION_INTERRUPTED_ENUM InterruptedType;
	
};
