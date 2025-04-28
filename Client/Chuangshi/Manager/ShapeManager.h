// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "ShapeManager.generated.h"

/*
* �ļ����ƣ�ShapeManager.h
* ����˵����
* �ļ����ߣ�zhangfudong
* Ŀǰά����zhangfudong
* ����ʱ�䣺2018-12-22
*/

class UBaseShape;

DECLARE_DELEGATE(FShapeDelegate);
DECLARE_DYNAMIC_DELEGATE(FShapeDynamicDelegate);


UENUM(BlueprintType)
enum class SHAPE_TYPE: uint8
{
	CYLINDER = 1		UMETA(DisplayName = "CYLINDER"),	///<Բ��		XY����СֵΪ�뾶��ZΪ�߶�
	BOX = 2				UMETA(DisplayName = "BOX"),			///<����		XYZΪ�����
	SHPERE = 3			UMETA(DisplayName = "SHPERE"),		///<��			XYZ����СֵΪ�뾶
	SECTOR = 4			UMETA(DisplayName = "SECTOR"),		///<����		XΪ�뾶��YΪ�Ƕȣ�ZΪ�߶�
	CAPSULE = 5			UMETA(DisplayName = "CAPSULE"),		///<������		XY����СֵΪ�뾶��ZΪ���
};


UCLASS(BlueprintType)
class CHUANGSHI_API UShapeManager : public UCS3Object
{
	GENERATED_BODY()

public:
	
	UShapeManager();

	/**
	 * ����Shape
	 *
	 * @param OwnerActor	 ӵ�������Actor	
	 * @param Type			 �������
	 * @param Bounds		 ����߽�
	 * @param BeginOverlap	 ��ʼ�ص��¼�
	 * @param EndOverlap	 �����ص��¼�
	 *
	 *@return �����������
	 */
	UFUNCTION(BlueprintCallable)
	UBaseShape* CreateShapeBindEvent(AActor* OwnerActor, SHAPE_TYPE Type, FVector Bounds, FShapeDynamicDelegate BeginOverlap, FShapeDynamicDelegate EndOverlap);


	/**
	 * ����Shape
	 *
	 * @param OwnerActor		 ӵ�������Actor
	 * @param Object			 this
	 * @param Type				 �������
	 * @param Bounds			 ����߽�
	 * @param BeginOverlapName	 ��ʼ�ص���������
	 * @param EndOverlapName	 �����ص���������
	 *
	 *@return �����������
	 */
	UFUNCTION(BlueprintCallable)
	UBaseShape* CreateShapeBindFunction(AActor* OwnerActor, UObject* Object, SHAPE_TYPE Type, FVector Bounds, FString BeginOverlapName, FString EndOverlapName);

	/**
	 * ����Shape
	 *
	 * @param OwnerActor		 ӵ�������Actor
	 * @param Object			 this
	 * @param Type				 �������
	 * @param Bounds			 ����߽�
	 * @param BeginOverlap		 ��ʼ�ص�����
	 * @param EndOverlap		 �����ص�����
	 *
	 *@return �����������
	 */
	template<class UserClass>
	UBaseShape* CreateShape(AActor* OwnerActor, UserClass* Object, SHAPE_TYPE Type, FVector Bounds, typename FShapeDelegate::TUObjectMethodDelegate<UserClass>::FMethodPtr BeginOverlap, typename FShapeDelegate::TUObjectMethodDelegate<UserClass>::FMethodPtr EndOverlap)
	{
		return InternalCreateShapeByDelegate(OwnerActor, Type, Bounds, FShapeDelegate::CreateUObject(Object, BeginOverlap), FShapeDelegate::CreateUObject(Object, EndOverlap));
	}
	
	///��ȡʵ��
	static UShapeManager* GetInstance();

private:
	///����Shape,�ڲ�����
	UBaseShape* InternalCreateShape(AActor* OwnerActor, SHAPE_TYPE Type, FVector Bounds, FShapeDynamicDelegate BeginOverlapDelegate, FShapeDynamicDelegate EndOverlapDelegate);
	UBaseShape* InternalCreateShapeByDelegate(AActor* OwnerActor, SHAPE_TYPE Type, FVector Bounds, FShapeDelegate BeginOverlapDelegate, FShapeDelegate EndOverlapDelegate);
public:
	///�������е�Shape����ֹ��GC
	UPROPERTY()
	TArray<UBaseShape*> ShapeList;

private:
	///������״��map
	TMap<SHAPE_TYPE, UClass*> TypeMapping;

};
