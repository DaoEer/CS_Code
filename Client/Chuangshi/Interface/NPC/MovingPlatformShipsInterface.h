#pragma once
#include "Interface/NPC/NPCInterface.h"
#include "MovingPlatformShipsInterface.generated.h"

/*
* �ļ����ƣ�MovingPlatformShipsInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-10-08
*/

/*
���۶ɽ� -- �ƶ�ƽ̨�ӿ�
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UMovingPlatformShipsInterface : public UNPCInterface
{
	GENERATED_BODY()
		typedef UNPCInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMovingPlatformShipsInterface();
	~UMovingPlatformShipsInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MovingPlatformShipsInterface'"); } //��ȡ��ͼ����·��
};

