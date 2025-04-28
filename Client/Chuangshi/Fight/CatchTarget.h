// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "CatchTarget.generated.h"

/*
* �ļ����ƣ�CatchTarget.h
* ����˵����
* �ļ����ߣ�yanghan
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-02-27
*/

UCLASS(Abstract)
class CHUANGSHI_API UCatchTarget : public UAnimNotifyState
{
	GENERATED_BODY()
	
protected:
	/**
	*Define method
	*BlueprintCallable��ץסĿ�꣨���м��ܣ�
	*
	*@param TargetID Ŀ��ID
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "CatchTarget")
		void CatchTarget(const int32 TargetID, AActor* CurActor, const FName AnimID);
	
	/**
	*Define method
	*BlueprintCallable���ͷ�Ŀ�꣨���м��ܣ�
	*
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "CatchTarget")
		void ReleaseTarget(AActor* CurActor);
};
