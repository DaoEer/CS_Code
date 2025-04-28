// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CS3Base/CS3EntityInterface.h"
#include "GameData/LBCTaskDatas.h"
#include "RoleLbcTaskInterface.generated.h"


/*
* �ļ����ƣ�RoleLbcTaskInterface.h
* ����˵����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2020-07-06
*/

/**
 * �����������������
 */

UCLASS(BlueprintType)
class CHUANGSHI_API URoleLbcTaskInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleLbcTaskInterface() {};

	static FString GetName() { return TEXT("RoleLbcTaskInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleLbcTaskInterface.BP_RoleLbcTaskInterface_C'"); } //��ȡ��ͼ����·��
	//���������
	UFUNCTION(BlueprintCallable, Category = "RoleLbcTaskInterface")
	void OpenLbcTaskUI(int32 type);
	//��������
	UFUNCTION(BlueprintCallable, Category = "RoleLbcTaskInterface")
	void AcceptLbcTask();
	//��ʾ��ʼ��������
	void ShowLbcStartTrainWnd();
	//������ ��ʼ����
	UFUNCTION(BlueprintCallable, Category = "RoleLbcTaskInterface")
	void LbcTaskStartPlay();
	//����ƶ���ָ��λ��
	void RoleMoveToLocation(const  KBEngine::FVariantArray& posList, const float& moveSpeed, const float& dis);
	//������������������
	void StartRoleLbcTaskOperation(const float& armLength, const FVector& cameraRotation);
	//�˳���������������ģʽ
	void EndRoleLbcTaskOperation();
	//����ʬ��
	void LbcTaskCreateBody(const FString& model, const int32& amount, const float& radius, const FVector& centerPos);
	UFUNCTION(BlueprintImplementableEvent, Category = "cs3|RoleLbcTaskInterface")
	void LbcTaskCreateBodyBP(const FString& model, const int32& amount, const float& radius, const FVector& centerPos);
	//��ʾ�������
	void ShowLbcTaskResult(const int32& result, const FString& fistGuardScriptID, const int32& exp, const int32& addExp, const int32& lossNum, const FString& cmdrerScriptID);

	void RPC_RoleMoveToLocationOver();

	virtual void InitBlueCB() override;
	virtual void onLeaveWorld() override;
private:
	void LoadLBCTaskDatas();
	void RoleMoveToPoint(bool firstOne,bool IsNext = true);
	
private:
	float CurPlayerCameraArmLength;
	FVector CurSocketOffset;
	float CurPlayerMoveSpeed;
	TArray<FLBCTASKDATA*> LBCTaskDatas;
	int32 posIndex = 0;
	TArray<FVector> pointList;
	float rolemoveSpeed;
	FTimerHandle DelayMoveEventHandle;///<���QTE�¼���ʱ��
	float NewarmLength;
	FVector NewcameraRotation;
	float RoleDistance;
};