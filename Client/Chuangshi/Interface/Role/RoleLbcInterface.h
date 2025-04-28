// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CS3Base/CS3EntityInterface.h"
#include "GameData/LbcData.h"
#include "RoleLbcInterface.generated.h"


/*
* �ļ����ƣ�RoleLbcInterface.h
* ����˵����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2020-08-20
*/

/**
 * ����������ӿ���
 */

UCLASS(BlueprintType)
class CHUANGSHI_API URoleLbcInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleLbcInterface();

	static FString GetName() { return TEXT("RoleLbcInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleLbcInterface.BP_RoleLbcInterface_C'"); } //��ȡ��ͼ����·��
	virtual void InitBlueCB() override;

	///��ʼ������
	void InitData();

	///�������������ͼ����
	UFUNCTION(BlueprintCallable, Category = "RoleLbcInterface")
		void ReqOpenLbcMapUI();
	///����������ͼ����
	void OpenLbcMapUI(const FVariant& occupyInfo, const FVariant& declareInfo, const FVariantArray& statusList);

	///����ǰ��������
	UFUNCTION(BlueprintCallable, Category = "RoleLbcInterface")
	void ReqGotoLbc(uint8 line, int32 index);
	
	///��ȡĳ�����ߵ�����
	UFUNCTION(BlueprintCallable, Category = "RoleLbcInterface")
	TMap<int32, FRoleLbcData> GetLineDatas(uint8 line);

	///����ָ���ȼ�ָ��������ʿ��
	void LbcOccupyCost(const int32& level, const int32& amount, const int32& money, const FVariantArray& scriptIDList);

	///�ύѡ�񽻸���ʿ��
	UFUNCTION(BlueprintCallable, Category = "RoleLbcInterface")
		void ReqSubmitOccupyCost(FString soldierScriptID);
	
	///������ս
	UFUNCTION(BlueprintCallable, Category = "RoleLbcInterface")
		void ReqCancelDeclareLbc();

	//����ռ����Ϣ
	void UpdateOccupyInfo(const FVariant& occupyInfo);
	//������ս��Ϣ
	void UpdateDeclareInfo(const FVariant& declareInfo);
	//���±���ս��Ϣ
	void UpdateBeDeclaredInfo(const FVariant& declareInfo);
	//������������״̬��Ϣ 
	void UpdateLbcStatusInfo(const FVariant& statusInfo);
	//֪ͨ��ս�߽�ս��
	void NotifyDeclarerFight(const int32& countDown, const uint8& line, const int32& index, const FVariant& declareInfo);
	//֪ͨռ���߽�ս��
	void NotifyOccupierFight(const int32& countDown, const uint8& line, const int32& index, const FVariant& declareInfo);
	//��ս�߷�������
	UFUNCTION(BlueprintCallable, Category = "RoleLbcInterface")
	void DeclarerGiveUpFight(uint8 line, int32 index);
	//ռ���߷�������
	UFUNCTION(BlueprintCallable, Category = "RoleLbcInterface")
	void OccupierGiveUpFight(uint8 line, int32 index);

public:
	///����������
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		uint8 MaxLineNum;

	TMap<uint8, TMap<int32, FRoleLbcData>> roleLbcData; //���������� <line��<index,data>> 

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLBC_OCCUPY_INFO OccupyInfo; //��ռ���������

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLBC_DECLARE_INFO DeclareInfo; //����ս��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLBC_DECLARE_INFO BeDeclaredInfo; //�ұ�������ս��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FString> ScriptIDs;	//���������ı���
};