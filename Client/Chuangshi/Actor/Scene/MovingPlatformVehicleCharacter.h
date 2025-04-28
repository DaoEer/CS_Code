#pragma once
#include "CoreMinimal.h"
#include "Actor/Scene/MovingPlatformCharacter.h"
#include "../../Component/CS3LightComponent.h"
#include "MovingPlatformVehicleCharacter.generated.h"

/*
* �ļ����ƣ�MovingPlatformVehicleCharacter.h
* ����˵�������˿��ƶ����
* �ļ����ߣ�liyuxia
* Ŀǰά����liyuxia
* ���� 2020/9/8
*/

class USpringArmComponentEX;
class UCS3CameraComponent;
class UPosSyncComponent;

UCLASS(BlueprintType, Blueprintable)
class AMovingPlatformVehicleCharacter : public AMovingPlatformCharacter
{
	GENERATED_BODY()
public:
	AMovingPlatformVehicleCharacter();
	virtual void BeginPlay()override;
	virtual void OnCreateApperanceOver() override;
	virtual void OnBindToEntity()override;
	virtual void OnUnBindActorCallBack()override;
	virtual void InitCharacterComponent()override;
	virtual float GetMoveSpeed() override;
	virtual bool IsActiveMoveing()override;
	bool SwitchControl(bool InIsControl);
	bool SwitchMoveVehicleMode(bool IsActive);
	void CreateVehicleAppearance(FString CarrierModelId);//�����ؾ����
	void SwitchCamera( bool IsActive);

private:
	void SetMovementActive(bool bNewActive);
	void InitCameraComponent();//��ʼ����������
	void InitPosSyncComponent();//��ʼ��λ��ͬ�����
	void InitLightComponent();///<��ʼ���������

public:
	UPROPERTY()
	USpringArmComponentEX* SpringArmCompent;
	UPROPERTY()
	UCS3CameraComponent* CameraComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCS3LightComponent* CS3LightComponent;///<�������
	UPROPERTY()
	UPosSyncComponent* PosSyncComp;
	bool bIsControl;
};
