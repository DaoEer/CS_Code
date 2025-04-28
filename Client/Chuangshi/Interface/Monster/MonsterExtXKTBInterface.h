// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface/Monster/MonsterExtMachineInterface.h"
#include "MonsterExtXKTBInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtXKTBInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2020-04-23
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtXKTBInterface : public UMonsterExtMachineInterface
{
	GENERATED_BODY()
		typedef UMonsterExtMachineInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtXKTBInterface();
	~UMonsterExtXKTBInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtXKTBInterface'"); } //��ȡ��ͼ����·��

	///��ʾ����Ѫ���µ�����
	void DisplyCurrentText(const FString& currentText, const int32& state);

	///�������ͷ�ϵĶ�̬ͼ�꼰����������ʾ
	void CancelDisplyCurrentText();

};
