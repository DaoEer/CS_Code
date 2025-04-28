#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtRHBInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtRHBInterface.h
* ����˵����
* �ļ����ߣ�lintongbin
* Ŀǰά����lintongbin
* ����ʱ�䣺2020-01-13
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtRHBInterface : public UMonsterInterface
{
	GENERATED_BODY()
		typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtRHBInterface();
	~UMonsterExtRHBInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtRHBInterface'"); } //��ȡ��ͼ����·��

	virtual void InitBlueCB() override;

	UFUNCTION(BlueprintNativeEvent, Category = "cs3|MonsterExtRHBInterface")
		void startThorwtorch(const FString& effectID, const int32& radius);
};