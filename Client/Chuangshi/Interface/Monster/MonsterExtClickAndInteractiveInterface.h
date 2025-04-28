#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtClickAndInteractiveInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtClickAndInteractiveInterface.h
* ����˵����
* �ļ����ߣ�liyuxia
* Ŀǰά����liyuxia
* ����ʱ�䣺2020-05-26
*/

class UBaseShape;

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtClickAndInteractiveInterface : public UMonsterInterface
{
	GENERATED_BODY()
		typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	virtual void onLeaveWorld() override;
	void CLIENT_AddInteractiveRange(const float& Radius);
	void OnPlayerBeginOverlap();
	void OnPlayerEndOverlap();

	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtClickAndInteractiveInterface'"); } //��ȡ����·��

	UFUNCTION(BlueprintCallable)
		void RPC_CELL_RequestInteraction();

private:
	//UPROPERTY()
	UBaseShape* pInitiativeShape = nullptr;//��UShapeManager���������
};