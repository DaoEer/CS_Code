#pragma once
#include "Interface/NPC/NPCInterface.h"
#include "MovingPlatformRotatorInterface.generated.h"

/*
* �ļ����ƣ�MovingPlatformRotatorInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-10-15
*/

/**
*MovingPlatformRotatorInterface�ӿ���
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UMovingPlatformRotatorInterface : public UNPCInterface
{
	GENERATED_BODY()
	typedef UNPCInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMovingPlatformRotatorInterface();
	~UMovingPlatformRotatorInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MovingPlatformRotatorInterface'"); } //��ȡ��ͼ����·��

	/**
	*Define method
	*BlueprintNativeEvent��֪ͨ��ʼ��ת
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|MovingPlatformRotator")
		void notifyClientStartRotat(FVector angle, float moveSpeed, int isContinuousMove);

	virtual void InitBlueCB() override;
};