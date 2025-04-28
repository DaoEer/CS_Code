#pragma once
#include "CoreMinimal.h"
#include "Actor/Monster/MonsterCharacter.h"
#include "MonsterGhostEyeCharacter.generated.h"

/*
* �ļ����ƣ�MonsterGhostEye.h
* ����˵������֮ͫ��
* �ļ����ߣ�liyuxia
* Ŀǰά����liyuxia
* ���� 2020/4/2
*/

class USpringArmComponentEX;
class UCS3CameraComponent;
class UPosSyncComponent;

UCLASS(BlueprintType, Blueprintable)
class CHUANGSHI_API AMonsterGhostEyeCharacter : public AMonsterCharacter
{
	GENERATED_BODY()


public:
	AMonsterGhostEyeCharacter();
	virtual void BeginPlay()override;
	virtual void OnCreateApperanceOver() override;
	virtual void OnBindToEntity()override;
	virtual void OnUnBindActorCallBack()override;
	virtual void InitCharacterComponent()override;

private:
	bool SwitchControlToCharacter();
	bool SwitchControlToPlayer();
	void SetCharacterMovementActive(bool bNewActive);
	void InitCameraComponent();//��ʼ����������
	void InitPosSyncComponent();//��ʼ��λ��ͬ�����

public:
	UPROPERTY()
	USpringArmComponentEX* SpringArmCompent;
	UPROPERTY()
	UCS3CameraComponent* CameraComponent;
	UPROPERTY()
	UPosSyncComponent* PosSyncComp;
};