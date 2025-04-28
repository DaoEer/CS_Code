#pragma once


#include "ClientGMCMDToServer.generated.h"

/*
* �ļ����ƣ�ClientGMCMDToServer.h
* ����˵����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2017-12-09
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UClientGMCMDToServer: public UObject
{
	GENERATED_BODY()
	typedef void (UClientGMCMDToServer::*pMethod) (int32 playerID, int32 desEntityID, FString methodName, FString args);
public:
	UClientGMCMDToServer();
	~UClientGMCMDToServer();
	static UClientGMCMDToServer* GetInstance();
	void BuildMap();
	UFUNCTION(BlueprintCallable, Category = "UClientGMCMDToServer | CallFunc")
	void CallFunc(int32 playerID, int32 desEntityID, const FString methodName, const FString cmdArgs);

	//����NPCPointDatasTable�е��λ��(CST-3101)
	void gotoPoint(int32 playerID, int32 desEntityID, FString methodName,  FString args);

	//����tableѡȡȫ��ս����ϵ��entity
	void tabAllEntity(int32 playerID, int32 desEntityID, FString methodName, FString args);

	//��Ŀ��ʩ�ſͻ��˼���
	void spellCSkill(int32 playerID, int32 desEntityID, FString methodName, FString args);

	//Ŀ����Լ�ʩ�ſͻ��˼���
	void spellCSkillSelf(int32 playerID, int32 desEntityID, FString methodName, FString args);

	//��ӿͻ���buff
	void addCBuff(int32 playerID, int32 desEntityID, FString methodName, FString args);

	//Ŀ����Լ���ӿͻ���buff
	void addCBuffSelf(int32 playerID, int32 desEntityID, FString methodName, FString args);

public:
	
	//ͨ���ַ������÷���

	TMap<FString, pMethod> MethodNameMap;
	//�ͻ��˷�����תΪ������������
	//TMap<FString, FString> ClientMethodToServerMap;

};


