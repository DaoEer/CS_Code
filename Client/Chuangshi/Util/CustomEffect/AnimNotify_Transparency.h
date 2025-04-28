// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3AnimNotify.h"
#include "AnimNotify_Transparency.generated.h"

/*
* �ļ����ƣ�AnimNotify_CustomSkeletalAnim.h
* ����˵������͸��֪ͨ
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2019-01-09
*/

UENUM(BlueprintType)
enum class Transparency_Type : uint8
{
	ADDTRANS = 0,			//��Ӱ�͸��
	REMOVETRANS = 1			//�Ƴ���͸��
};

UCLASS(meta = (DisplayName = "CS3AnimNotify_Transparency"))
class CHUANGSHI_API UAnimNotify_Transparency : public UCS3AnimNotify
{
	GENERATED_BODY()
	
	// Begin UAnimNotify interface
	virtual FString GetNotifyName_Implementation() const override;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	// End UAnimNotify interface

	virtual void StopNotifyEffect(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	// ����
	UPROPERTY(EditAnywhere, Category = "TransparencyAnimNotify")
	Transparency_Type TransType = Transparency_Type::ADDTRANS;

	// ͸����
	UPROPERTY(EditAnywhere, Category = "TransparencyAnimNotify", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Alpha = 1.0f;
};
