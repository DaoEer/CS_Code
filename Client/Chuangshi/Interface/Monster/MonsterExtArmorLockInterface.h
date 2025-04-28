#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtArmorLockInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtArmorLockInterface.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-10-19
*/
UCLASS(BlueprintType)
class UMonsterExtArmorLockInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtArmorLockInterface();
	virtual ~UMonsterExtArmorLockInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtArmorLockInterface'"); } //��ȡ��ͼ����·��

	UFUNCTION(BlueprintNativeEvent, Category = "cs3|MonsterExtArmorLockInterface")
		void EnterArmorLock();

	UFUNCTION(BlueprintNativeEvent, Category = "cs3|MonsterExtArmorLockInterface")
		void ExitArmorLock(const float OutTime);

	void MaterialTimer();

	virtual void InitBlueCB() override;

	float DelayTime;

	float CoverParameter;

private:
	FTimerHandle CoverEventHandle;///<���QTE�¼���ʱ��
};

