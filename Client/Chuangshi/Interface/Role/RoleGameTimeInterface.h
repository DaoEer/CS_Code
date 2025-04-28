#pragma once
#include "Util/CS3Debug.h"
#include "CS3Base/CS3EntityInterface.h"
#include "RoleGameTimeInterface.generated.h"

/*
* �ļ����ƣ�RoleGameTimeInterface.h
* ����˵������Ϸʱ�����ѽӿ�
* �ļ����ߣ�zhutianyang
* Ŀǰά����zhutianyang
* ����ʱ�䣺2020-8-12
*/
/**
 * �����Ϸʱ���շѽӿ�
 */

UCLASS(BlueprintType)
class CHUANGSHI_API URoleGameTimeInterface: public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()

public:
	URoleGameTimeInterface();
	~URoleGameTimeInterface();

	static FString GetName() { return TEXT("RoleGameTimeInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleGameTimeInterface.BP_RoleGameTimeInterface_C'"); } //��ȡ��ͼ����·��

public:
	void OnGameTimeBalanceCountDown(const int32& TimeBalance);
	void ShowStartBillingWnd(const int32& Level, const int32& CountDownTime);
	void HideStartBillingWnd();

};

