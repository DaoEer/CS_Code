// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Camera/CameraComponent.h"
#include "Engine/StreamableManager.h"
#include "StoryCameraActor.generated.h"

UCLASS()
class CHUANGSHI_API AStoryCameraActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStoryCameraActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

   //If true, actor is ticked even if TickType == LEVELTICK_ViewportsOnly
	virtual bool ShouldTickIfViewportsOnly() const override;

	//�������Ե������
	void OutLineEffectToCamera();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	///��ͷ�������� ����ͼ����������ʼ�� ��Ϊ��ǰ��������ͷ�������ԭ�����԰ɴ���������ͼ������ 
	UPROPERTY(BlueprintReadWrite, Category = "StoryCameraActor")
		UCameraComponent* StoryCameraComponent;
	UPROPERTY()
		USceneCaptureComponent2D* SceneCapture;///<������׽���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Interp)
		FLinearColor OutLineColor = FLinearColor(0, 1, 1, 0);///��Ե����ɫ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Interp)
		float OutlineWidth = 5.0f;///��Ե����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Interp)
		bool OpenOutLine = false;///������Ե��Ч��
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<AActor*> ActorRef;///��Ե��Actor
	UPROPERTY( BlueprintReadWrite)
		TSoftObjectPtr<UMaterialInterface> PostMaterial;

	int32 DepthTexSize = 512;///��ͼ��С
	FLinearColor InLineColor = FLinearColor(0, 1, 1, 0);

private:

	UPROPERTY(Category = CameraActor, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* SceneComponent;

	FStreamableManager StreamManager;///<��Դ��������

	void SetDynamicMaterial(UMaterialInstanceDynamic* material);

};
