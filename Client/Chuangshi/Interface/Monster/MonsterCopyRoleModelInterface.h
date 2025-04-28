// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/Monster/MonsterInterface.h"
#include "MonsterCopyRoleModelInterface.generated.h"

/*
* �ļ����ƣ�MonsterCopyRoleModelInterface.h
* ����˵����������ħ����������ȹ���Copy��ҵ�ģ�ͣ�ʱװ��������
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020/12/9
*/

UCLASS()
class CHUANGSHI_API UMonsterCopyRoleModelInterface : public UMonsterInterface
{
	GENERATED_BODY()
	
public:
	//��ȡ�����������ҵ�ID
	int32 GetOwnerID();
	// ���������һ�û�����ã����ӳٴ���
	void DelayCreateApperance();


private:
	FTimerHandle DelayCreateAppearHandle;
	int8 WaitTime;					// �ȴ�copy����Ĵ�����10�Σ�10�룩ģ�;ʹ���ʧ���� 			
};
