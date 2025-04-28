#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtSFMJInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtSFMJInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-08-06
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtSFMJInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtSFMJInterface();
	~UMonsterExtSFMJInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtSFMJInterface'"); } //��ȡ��ͼ����·��

	UFUNCTION(BlueprintNativeEvent, Category = "cs3|MonsterExtSFMJInterface")
		void AddInitiativeRange();

	void OnPlayerBeginOverlap();

	void OnPlayerEndOverlap();

	virtual void InitBlueCB() override;

	UFUNCTION(BlueprintCallable, Category = "cs3|MonsterExtSFMJInterface")
		void RPC_InteractionResults();

private:
	float Radius = 5.0f;
	UBaseShape* pInitiativeShape = nullptr;
};