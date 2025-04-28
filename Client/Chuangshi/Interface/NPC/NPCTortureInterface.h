#pragma once
#include "Interface/NPC/NPCInterface.h"
#include "NPCTortureInterface.generated.h"

/*
* �ļ����ƣ�NPCTortureInterface.h
* ����˵�������ʸ�������NPC
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2018-07-16
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UNPCTortureInterface : public UNPCInterface
{
	GENERATED_BODY()
	typedef UNPCInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UNPCTortureInterface();
	~UNPCTortureInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.NPCTortureInterface'"); } //��ȡ��ͼ����·��

};