// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface/SpellBox/SpellBoxInterface.h"
#include "SpellBoxAdvancedInterface.generated.h"

/*
* �ļ����ƣ�SpellBoxAdvancedInterface.h
* ����˵����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2018-05-17
*/
UCLASS()
class CHUANGSHI_API USpellBoxAdvancedInterface : public USpellBoxInterface
{
	GENERATED_BODY()
	typedef USpellBoxInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()

public:
	USpellBoxAdvancedInterface();
	~USpellBoxAdvancedInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.SpellBoxAdvancedInterface'"); } //��ȡ��ͼ����·��

	void CELL_reqInterruptInteractive();
	
	void CELL_reqStartInteractive();
};
