#pragma once
#include "CS3Base/CS3EntityInterface.h"
#include "RoleQTEInterface.generated.h"

/*
* �ļ����ƣ�RoleQTEInterface.h
* ����˵����QTE
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-08-13
*/


UCLASS(BlueprintType)
class URoleQTEInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleQTEInterface();
	virtual ~URoleQTEInterface();
	
	static FString GetName() { return TEXT("RoleQTEInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleQTEInterface.BP_RoleQTEInterface_C'"); } //��ȡ��ͼ����·��


public:
	virtual void InitBlueCB() override;
	/**
	*Define method
	*BlueprintNativeEvent����ʼBuffQTE
	*
	*@param qteTypeList QTE�����б�
	*@param qteTimeList ʱ���б�
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleQTEInterface")
		void OnStartBuffQTE(const FString& TableRowName);
	/**
	*Define method
	*BlueprintNativeEvent������QTE
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleQTEInterface")
		void OnEndBuffQTE();

	/**
	*Define method
	*BlueprintNativeEvent����ʼ��ͷQTE
	*@param Type  QTE����
	*@param KeypressList ��������б�
	*@param qteTimeList  ʱ���б�
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleQTEInterface")
		void OnStartStoryQTE(const FString& TableRowName);

	void onCompleteQTEBuffEvent(bool bIsSuccess);

	void onCompleteBuffQTE( );
};

