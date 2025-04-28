#pragma once
#include "Interface/NPC/NPCInterface.h"
#include "NPCDropFuDaiInterface.generated.h"

/*
* �ļ����ƣ�NPCDropFuDaiInterface.h
* ����˵����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-12-01
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UNPCDropFuDaiInterface : public UNPCInterface
{
	GENERATED_BODY()
	typedef UNPCInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UNPCDropFuDaiInterface();
	~UNPCDropFuDaiInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.NPCDropFuDaiInterface'"); } //��ȡ��ͼ����·��
	/**
	*֪ͨ�������������������Һ���ҵİ󶨹�Ч
	*
	*@Param int32 PlayID ��ҵ�EntityID
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "NPCDropFuDaiInterface|RPC")
	void RPC_onFuDaiCollisionBegin(const int32& PlayID);
	/**
	*֪ͨ�����������Ĺ�Ч�ɵ����������
	*
	*@Param int32 PlayID ��ҵ�EntityID
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "NPCDropFuDaiInterface|RPC")
	void RPC_onFuDaiCollisionPlayer(const int32& PlayID);
	/**
	*֪ͨ������������ȡ���������е��������º��Ѿ�¥�µĲƱ�
	*
	*@Param int32 MondterID �����EntityID
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "NPCDropFuDaiInterface|RPC")
	void RPC_onFuDaiCollisionMonster(const int32& MonsterID);
	

	virtual void InitBlueCB() override;

	/**
	* ֪ͨ�ͻ��˿�ʼ�ƶ�
	*@Param Resistance ����
	*@Param EffectID ��ý����Ĺ�Ч(û�й�Чʱ�ǵø���Ĭ�Ϲ�Ч)
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "NPCDropFuDaiInterface")
		void CLIENT_fuDaiStartMove(const float& Resistance, const FString& EffectID);

	/**
	* �ڶ�Ӧ����λ�ò���ѭ����Ч
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "NPCDropFuDaiInterface")
		void CLIENT_OnPlayFloorEffect(const FString& EffectID);

	/**
	*֪ͨ��ʾ���ģ���Ա���ʾ����
	*
	*@Param int32 moneyAmount �������
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "NPCDropFuDaiInterface|RPC")
		void NotifyIntegralAmount(const int32& moneyAmount);

public:

	UPROPERTY(BlueprintReadWrite)
		FString PickEffectID;

	UPROPERTY()
		class UTextRenderComponent* TextRenderComponent;///<������ʾ������������

private:
	///����λ�ö�ʱ��
	FTimerHandle SetPosTimer;
	void SetJinBiPosition();
};
