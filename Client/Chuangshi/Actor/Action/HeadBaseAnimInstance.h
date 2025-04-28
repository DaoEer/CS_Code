// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HeadBaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API UHeadBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "CharacterDataCode")
		UAnimSequenceBase* CurAnimSquenceBase;

	///��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "CharacterDataCode")
		float PlayRate = 1.0f;

	///������ʼλ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "CharacterDataCode")
		float StartPosition = 0.0f;

	///�Ƿ�ѭ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "CharacterDataCode")
		bool bLoop = true;
};
