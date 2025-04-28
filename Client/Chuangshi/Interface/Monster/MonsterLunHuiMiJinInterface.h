// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterLunHuiMiJinInterface.generated.h"

/*
* �ļ����ƣ�MonsterLunHuiMiJinInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2019-12-24
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterLunHuiMiJinInterface : public UMonsterInterface
{
	GENERATED_BODY()
		typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()

public:
	UMonsterLunHuiMiJinInterface();
	~UMonsterLunHuiMiJinInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterLunHuiMiJinInterface'"); } //��ȡ��ͼ����·��

	virtual void InitBlueCB() override;
};
