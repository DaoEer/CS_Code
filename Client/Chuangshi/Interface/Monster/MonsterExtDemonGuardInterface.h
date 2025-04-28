// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtDemonGuardInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtChartletInterface.h
* ����˵������������30������������Ǳ�������������� ����
* �ļ�����: liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2019-4-12
*/
UCLASS()
class CHUANGSHI_API UMonsterExtDemonGuardInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtDemonGuardInterface'"); } //��ȡ��ͼ����·��

	//�������Ƿ�����Ұ��Χ��
	void CheckIsInView(int32 targetID);

	//��ȡ�ͻ��˵�����
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|UMonsterExtDemonGuardInterface")
		void CLIENT_GetClientNavPoint(FVector targetPos);
	
	//�����Ұ�������
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|UMonsterExtDemonGuardInterface")
		void CLIENT_CreateViewShapeTrap(float Range, float Angle, float Height);


	virtual void InitBlueCB() override;
public:
	UBaseShape* CreateViewShape(float Range, float Angle, float Height);
	void OnPlayerEnterViewRange(); ///��ҽ�����Ұ����
	void OnPlayerLeaveViewRange(); ///����뿪��Ұ����
private:
	FTimerHandle checkViewTimerHandle; //��Ұ���TimerHandle
	FTimerHandle delaySetViewTimerHandle; //��ʱ�Ƴ�checkViewTimerHandle
	FTimerHandle getNavPoint; //��ȡ������ ��Ҫʵʱ����Ƿ��ж�̬�ϰ����ǽ��

	UBaseShape* pViewShape; //��Ұ����
};
