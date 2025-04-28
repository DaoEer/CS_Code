#pragma once
#include "Interface/NPC/MovingPlatformShadeInterface.h"
#include "MovingPlatformRampInterface.generated.h"

/*
* �ļ����ƣ�MovingPlatformRampInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-05-30
*/

/**
*MovingPlatformRampInterface�ӿ���
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UMovingPlatformRampInterface : public UMovingPlatformShadeInterface
{
	GENERATED_BODY()
	typedef UMovingPlatformShadeInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMovingPlatformRampInterface();
	~UMovingPlatformRampInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MovingPlatformRampInterface'"); } //��ȡ��ͼ����·��

};