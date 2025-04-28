// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtDisposableInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtDisposableInterface.h
* ����˵����һ���Ե���ӹ���
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2020-11-10
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtDisposableInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtDisposableInterface();
	~UMonsterExtDisposableInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtDisposableInterface'"); } //��ȡ��ͼ����·��

	//��ȡ�����������ҵ�ID
	int32 GetOwnerID();

};
