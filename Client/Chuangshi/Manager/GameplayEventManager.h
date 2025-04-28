#pragma once

#include "GameData/CS3Object.h"
#include "GameplayEventManager.generated.h"

/*
* �ļ����ƣ�GameplayEventManager.h
* ����˵����
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2018-11-12
*/

UCLASS(Blueprintable)
class CHUANGSHI_API UGameplayEventManager : public UCS3Object
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UGameplayEventManager();
	~UGameplayEventManager();

	static UGameplayEventManager* GetInstance();

};