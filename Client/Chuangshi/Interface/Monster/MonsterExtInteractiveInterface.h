#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtInteractiveInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtInteractiveInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-05-08
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtInteractiveInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtInteractiveInterface();
	~UMonsterExtInteractiveInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtInteractiveInterface'"); } //��ȡ��ͼ����·��

	/**
	*������֪ͨ��ӽ�������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|MonsterExtInteractiveInterface")
	void AddInitiativeTrap();

	void OnPlayerBeginOverlap();

	void OnPlayerEndOverlap();

	virtual void InitBlueCB() override;

	UFUNCTION(BlueprintCallable, Category = "cs3|MonsterExtInteractiveInterface")
	void RPC_InteractiveWith();

private:
	float Radius = 5.0f;
	UBaseShape* pInitiativeShape = nullptr;
};