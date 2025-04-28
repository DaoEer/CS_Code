// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameData/CharacterData.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MonsterLadderMovementComponent.generated.h"


/*
* �ļ����ƣ�MonsterLadderMovementComponent.h
* ����˵�������������������ӹ���
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2020-03-20
*/
class AMonsterCharacter;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHUANGSHI_API UMonsterLadderMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMonsterLadderMovementComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void InitData(AMonsterCharacter *LadderCharacter);

	void StartClimbLadder(FVector LadderStartLocation, FVector LadderEndLocation, FRotator LadderRotation);//���￪ʼ������
	void StartFallToLadder();//���￪ʼ�����ӵ���
	void LadderResetPitch();//�ָ�����pitch�Ƕ�

protected:
	virtual void BeginPlay() override;

private:
	void ExitTop();//����<�Ӷ���>�뿪����
	void ExitFallLand();//����<�ӿ��е�����½>�뿪����
	void ClimbUpToLader(float DeltaSeconds);//������������tickģ�����
	void FallDownToLader(float DeltaSeconds);//�������µ���tickģ�����
	void ActionExitTopOver(ACharacter * Character, FACTION_DATA Action);

public:
	UPROPERTY(BlueprintReadOnly, Category = "LadderCustomMovementComponent")
		AMonsterCharacter* CurMonsterCharacter;///��ǰ����

	UPROPERTY(BlueprintReadOnly, Category = "LadderCustomMovementComponent")
		UCharacterMovementComponent* CurCharacterMovement;///��ǰ�����ƶ���� 

	UPROPERTY(BlueprintReadOnly, Category = "LadderCustomMovementComponent")
		AMonsterCharacter* CurLadderCharacter;///��ǰ����

private:
	bool IsAIEnterLadder = false;//�����Ƿ��������
	FVector AIMonsterStartLoaction;//����ĳ�ʼλ��
	FVector AIMonsterEndLoaction;//����Ľ���λ��
	FRotator AIMonsterRotation;

	bool IsLadderDownFalling = false;//�Ƿ�������ڴ������ϵ���
	FVector AIMonsterFallDownEndLoaction;//����ĵ���Ľ���λ�ã��ذ壩
	float AddSpeed = 0.0f;//��������ļ��ٶ�
		
};
