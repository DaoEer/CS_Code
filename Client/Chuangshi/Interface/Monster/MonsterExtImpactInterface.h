#pragma once
#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtImpactInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtImpactInterface.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-09-19
*/
UCLASS(BlueprintType)
class UMonsterExtImpactInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtImpactInterface();
	virtual ~UMonsterExtImpactInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtImpactInterface'"); } //��ȡ��ͼ����·��

};

