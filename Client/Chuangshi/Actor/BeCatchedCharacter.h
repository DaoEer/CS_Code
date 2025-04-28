// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/GameCharacter.h"
#include "BeCatchedCharacter.generated.h"

/*
* �ļ����ƣ�BeCatchedCharacter.h
* ����˵����
* �ļ����ߣ�yanghan
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2018-02-08
*/
UCLASS()
class CHUANGSHI_API ABeCatchedCharacter : public AGameCharacter
{
	GENERATED_BODY()
public:
	ABeCatchedCharacter();
	virtual void BeginPlay()override;

	virtual void SetInitAction() override;///<��дSetInitAction

										  //������ϻص�
	virtual void OnCreateApperanceOver()override;

	//void InitAppearanceComponent();///<��дInitBaseComponent
public:
	//������Ϻ�Ҫ���ŵĶ���
	FName m_AnimId;
	
};
