#pragma once
#include "CoreMinimal.h"
#include "Actor/GameCharacter.h"
#include "../ServerCharacter.h"
#include "PetProxyCharacter.generated.h"

/*
* �ļ����ƣ�PetProxyCharacter.h
* ����˵�������ڽ�������ʾ����ģ��
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2020-4-26
*/


UCLASS(BlueprintType, Blueprintable)
class CHUANGSHI_API APetProxyCharacter : public AGameCharacter
{
	GENERATED_BODY()
public:
	APetProxyCharacter();///<���캯��
	virtual void BeginPlay()override;
	virtual void OnCreateModelOver() override;
	virtual void OnCreateApperanceOver() override;

public:
	//���Ŷ���
	UFUNCTION(BlueprintCallable, Category = "PetProxyCharacter")
		void PlayAction_BP(FName ActionID);
	//�����������
	UFUNCTION(BlueprintCallable, Category = "PetProxyCharacter")
		void PlayActionFinish(ACharacter* Character, FACTION_DATA InActionData);

	///ͨ��ModleID����ģ��
	UFUNCTION(BlueprintCallable, Category = "PetProxyCharacter")
		void ChangeModel(FString ModelID);
	
	UFUNCTION(BlueprintPure, Category = "PetProxyCharacter")
		FString GetModelID();

protected:
	virtual void InitBaseComponent() override;///<��дInitBaseComponent
	
};
