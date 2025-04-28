#pragma once

#include "GameData/ServerListData.h"
#include "CS3Base/CS3EntityInterface.h"
#include "RoleCrossServiceInterface.generated.h"


/*
* �ļ����ƣ�RoleCrossServiceInterface.h
* ����˵������ҿ����ؽӿ�
* �ļ����ߣ�zhutianyang
* Ŀǰά����zhutianyang
* ����ʱ�䣺2020-04-13
*/


UCLASS(BlueprintType)
class CHUANGSHI_API URoleCrossServiceInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleCrossServiceInterface();
	~URoleCrossServiceInterface();
	static FString GetName() { return TEXT("RoleCrossServiceInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleCrossServiceInterface.BP_RoleCrossServiceInterface_C'"); } //��ȡ��ͼ����·��

	virtual void InitBlueCB() override;

private:
	bool Check(FSERVER_DATA CurrServerData, FSERVER_DATA TargetServerData);
	void BeforeCrossService();
	void BeforeReturnServer();

public:

	/**
	*BlueprintCallable,������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "cs3|RolePerformanceInterface")
		void RPC_RequestCrossService(FString TargetServerName);
	/**
	*Define Method
	*BlueprintNativeEvent,���������
	*
	*@return ��
	*/
	void CLIENT_OnRequestCrossServiceResult(const FString& Result);
	/**
	*BlueprintCallable,���󷵻�ԭ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "cs3|RolePerformanceInterface")
		void RPC_RequestReturnServer();
	/**
	*Define Method
	*BlueprintNativeEvent,����ԭ��������
	*
	*@return ��
	*/
	void CLIENT_OnRequestReturnServerResult(const FString& Result);

	/**
	*Define method
	*BlueprintNativeEvent �����ɷ���ԭ��ͼ
	*
	*@return ��
	*/
	void OnRoleReEnterWorld();

private:
};

