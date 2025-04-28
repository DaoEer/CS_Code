// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/GameCharacter.h"
#include "TipsCharacter.generated.h"

/*
* �ļ����ƣ�HeadProxyCharacter.h
* ����˵��������ѡ����Ӫʱ�Աߵ�TIPS NPC
* �ļ����ߣ�linhaowen
* Ŀǰά����linhaowen
* ����ʱ�䣺2018-12-21
*/
UCLASS()
class CHUANGSHI_API ATipsCharacter : public AGameCharacter
{
	GENERATED_BODY()
public:
	virtual void BeginPlay()override;
	virtual void OnCreateModelOver() override;

	UFUNCTION(BlueprintCallable, Category = "HeadProxyCharacter")
		void CreateModel(FString ModelID);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 TypeID;///ÿ����Ӫ��ӦID
	

protected:
	virtual void InitBaseComponent() override;///<��дInitBaseComponent
};
