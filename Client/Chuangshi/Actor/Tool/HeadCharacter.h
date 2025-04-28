#pragma once

#include "CoreMinimal.h"
#include "Actor/GameCharacter.h"
#include "HeadCharacter.generated.h"

/*
* �ļ����ƣ�HeadCharacter.h
* ����˵�������ڶ�̬���������ù��ߣ���Ϊ���߲�����Ϸ����Ҫ�Խ�һ�����
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2019-08-12
*/


UCLASS(BlueprintType, Blueprintable)
class CHUANGSHI_API AHeadCharacter : public AGameCharacter
{
	GENERATED_BODY()
public:
	AHeadCharacter();///<���캯��
	virtual void BeginPlay()override;
	virtual void OnCreateModelOver() override;
	virtual void OnCreateApperanceOver() override;

public:
	///ͨ��HeadID����ģ��
	UFUNCTION(BlueprintCallable, Category = "HeadCharacter")
		void ChangeModel(FString ModelID);
	
	UFUNCTION(BlueprintCallable, Category = "HeadCharacter")
		void PlayAction_BP(FName ActionID);

protected:
	virtual void InitBaseComponent() override;///<��дInitBaseComponent
	
private:
	
};
