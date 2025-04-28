// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface/Monster/MonsterCopyRoleModelInterface.h"
#include "MonsterExtFenShenInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtFenShenInterface.h
* ����˵����
* �ļ����ߣ�QRN
* Ŀǰά����QRN
* ����ʱ�䣺2020-09-07
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtFenShenInterface : public UMonsterCopyRoleModelInterface
{
	GENERATED_BODY()
	typedef UMonsterCopyRoleModelInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtFenShenInterface();
	~UMonsterExtFenShenInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtFenShenInterface'"); } //��ȡ��ͼ����·��

	

	void BeginPosSyncServer();
	void EndPosSyncServer();
	
	// ��������λ��ͬ��λ�õ�������������UMonsterPosSyncComponent��
	// ��Ϊ�ڲ������Ż���ֹ�ƶ������������ͬ��λ�á�
	void UpdateVolatileDataToServer();


private:
	FTimerHandle UpdateVolHandle;
};
