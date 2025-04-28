// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface/Monster/MonsterCopyRoleModelInterface.h"
#include "MonsterExtTiShenInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtTiShenInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2018-04-23
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtTiShenInterface : public UMonsterCopyRoleModelInterface
{
	GENERATED_BODY()
	typedef UMonsterCopyRoleModelInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtTiShenInterface();
	~UMonsterExtTiShenInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtTiShenInterface'"); } //��ȡ��ͼ����·��

};
