// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/StateInterface.h"
#include "PetStateInterface.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API UPetStateInterface : public UStateInterface
{
	GENERATED_BODY()

		typedef UStateInterface Supper;
	
public:

	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.PetStateInterface'"); } //��ȡ��ͼ����·��
																																			   
																																					   /**
	*virtual,��ɫ״̬�ı�
	*
	*@param NewState �µ�״ֵ̬
	*@param OldState �ɵ�״ֵ̬
	*
	*@return ��
	*/
	virtual void OnStateChanged(const int32& NewState, const int32& OldState)override;
};
