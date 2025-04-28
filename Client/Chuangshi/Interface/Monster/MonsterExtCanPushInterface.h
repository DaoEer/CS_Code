

#pragma once

#include "CoreMinimal.h"
#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtCanPushInterface.generated.h"


UCLASS()
class CHUANGSHI_API UMonsterExtCanPushInterface : public UMonsterInterface
{

	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()

public:
	UMonsterExtCanPushInterface();
	~UMonsterExtCanPushInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtCanPushInterface'"); } //��ȡ��ͼ����·��

	//��ȡ�ͻ��˵�����
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|UMonsterExtDemonGuardInterface")
		void CLIENT_OnRoleNearbyMonster(int32 MonsterID);

	/*�������*/
	void RPC_OnRolePushComplete();

	virtual void InitBlueCB() override;
private:
	FTimerHandle KeyDownTimerEventHandle;///<��⵱ǰ�����Ƿ��г����涨ʱ�䶨ʱ��
};
