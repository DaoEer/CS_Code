// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/GameCharacter.h"
#include "ClientGameCharacter.generated.h"

/*
* �ļ����ƣ�ClientGameCharacter.h
* ����˵�����ͻ��˶������
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-06-29
*/

/*
* �ͻ��˶������
*/
UCLASS(BlueprintType)
class CHUANGSHI_API AClientGameCharacter : public AGameCharacter
{
	GENERATED_BODY()
public:
	AClientGameCharacter();
	virtual void BeginPlay()override;

protected:
	virtual void InitBaseComponent() override;///<��дInitBaseComponent
	
	UFUNCTION(BlueprintCallable, Category = "ClientCharacter")
		void PlayClientAction(FName InActionId);

	UFUNCTION(BlueprintImplementableEvent, Category = "ClientCharacter")
		void OnPlayClientActionFinished(ACharacter* Character, FACTION_DATA ActionData);

public:
	virtual void OnCreateApperanceOver() override;

	// ���������ϵ���ͼ֪ͨ���ܶ๤��ֻ�д������ģ�Ͳſ�ʼ����
	UFUNCTION(BlueprintImplementableEvent, Category = "ClientCharacter")
		void OnCreateApperanceOverBP();
	// ִ���Զ����¼�
	UFUNCTION(BlueprintImplementableEvent, Category = "ClientCharacter")
		void OnDoingCustomEvent(const int32& EventType);

public:

	// ���ñ���У��������õģ��ͻ��˱��ض���һ��������Ƕ�ȡ����
	UPROPERTY(BlueprintReadWrite)
	FString DataTableRow;
};
