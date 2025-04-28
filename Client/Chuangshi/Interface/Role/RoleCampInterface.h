#pragma once

#include "Util/CS3Debug.h"
#include "CS3Base/CS3EntityInterface.h"
#include "RoleCampInterface.generated.h"

/*
* �ļ����ƣ�RoleCampInterface.h
* ����˵���������Ӫ
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-12-25
*/
/**
 * �����Ӫ�ӿ���
 */

UCLASS(BlueprintType)
class  CHUANGSHI_API URoleCampInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleCampInterface();
	~URoleCampInterface();
	static FString GetName() { return TEXT("RoleCampInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleCampInterface.BP_RoleCampInterface_C'"); } //��ȡ��ͼ����·��


	/**
	*Define Method
	*BlueprintNativeEvent,��Ӫ���˸ı�ص�
	*
	*@param: newCampMorale  ������
	*@param: oldCampMorale  ������
	*@param: otherCampMorale  ������Ӫ����
	*@param: buffID  
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleQuestInterface")
		void CLIENT_onMoraleChange(const FString& newCampMorale, const FString& oldCampMorale, const FString& otherCampMorale, const int32& buffID);

	/**
	*Define Method
	*BlueprintNativeEvent,��ѯ��Ӫ���ݻص�
	*
	*@param: taoismMorale  �ɵ�����
	*@param: demonMorale  ħ������
	*@param: taoismVenName  �ɵ���������
	*@param: demonVenName  ħ����������
	*@param: isGetCampReward  �Ƿ���ȡ������false��δ��ȡ�� true������ȡ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleQuestInterface")
		void CLIENT_OnQueryCampUIData(const FString& taoismMorale, const FString& demonMorale, const FString& taoismVenName, const FString& demonVenName, uint8 isGetCampReward);

	/**
	*Define Method
	*BlueprintNativeEvent,��ѯ��Ӫ���ݻص�
	*@param: OpenSwitch  ����
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleQuestInterface")
		void CLIENT_SetClientCampSwitch(uint8 OpenSwitch);

	virtual void InitBlueCB() override;

	/**
	*�Ƿ����Ӫ����
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleQuestInterface")
		bool IsOpenCampSwitch();

	/**
	*��������Ӫ��UI����
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_RquestQueryCampUIData();

	/**
	*��������Ӫ���˽���
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_rquestCampMoraleReward();

private:
	bool IsOpenSwitch = false;
};
