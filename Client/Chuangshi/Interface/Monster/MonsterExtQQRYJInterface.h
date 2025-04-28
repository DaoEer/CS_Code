#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtQQRYJInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtQQRYJInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-11-18
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtQQRYJInterface : public UMonsterInterface
{
	GENERATED_BODY()
		typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtQQRYJInterface();
	~UMonsterExtQQRYJInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtQQRYJInterface'"); } //��ȡ��ͼ����·��

	UFUNCTION(BlueprintNativeEvent, Category = "cs3|MonsterExtQQRYJInterface")
		void AddAlternatelyRange();

	void OnPlayerBeginOverlap();

	void OnPlayerEndOverlap();

	virtual void InitBlueCB() override;

	UFUNCTION(BlueprintCallable, Category = "cs3|MonsterExtQQRYJInterface")
		void RPC_alternatelyResults();

private:
	float Radius = 6.0f;
	UBaseShape* pInitiativeShape = nullptr;
};