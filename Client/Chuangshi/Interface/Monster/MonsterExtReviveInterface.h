#pragma once
#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtReviveInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtReviveInterface.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-05-15
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtReviveInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtReviveInterface();
	~UMonsterExtReviveInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtReviveInterface'"); } //��ȡ��ͼ����·��

};

