// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/Monster/MonsterInterface.h"
#include "GameFramework/Character.h"
#include "GameData/CharacterData.h"
#include "Actor/Monster/MonsterCharacter.h"
#include "MonsterExtAerialLadderInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtAerialLadderInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-02-25
*/
UENUM(BlueprintType)
enum class AERIAL_LADDER_STATE : uint8
{
	AERIAL_LADDER_STATE_FOLLOWER = 0, ///����
	AERIAL_LADDER_STATE_BUILD = 1, ///���
	AERIAL_LADDER_STATE_BUILD_SUCCESS = 2, ///��ɹ�
};
UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtAerialLadderInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtAerialLadderInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtAerialLadderInterface'"); } //��ȡ��ͼ����·��
	/**
	*BlueprintNativeEvent ���շ�����:�����ƶ���ϣ�׼���
	*
	*@param actionID �����ݶ���ID
	*@param LeaveTopOffset ��Ҷ����뿪����ƫ����
	*@param ClimbLadderSpeed ������������ٶ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_AerialLadderMoveFinish(const FString& actionID, float LeaveTopOffset, float ClimbLadderSpeed);

	//���շ���������AOI����ִ�����ݴ���ܣ������Ŷ�����ֱ�Ӽ����ݼ��������� 
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_EnterAerialLadderAOI(float LeaveTopOffset, float ClimbLadderSpeed);

	//֪ͨ�����������ݴ���
	UFUNCTION(BlueprintCallable)
		void CELL_LadderBuildComplete();

	//���շ�����������׼���Ƶ�
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_AerialLadderReadyToFall(const FString& actionID);

	//֪ͨ�����������ݵ���ʱ��������������entityID
	UFUNCTION(BlueprintCallable)
		void CELL_LadderFallAllEntity(TArray<int32> LadderEntityList);

	//֪ͨ�����������ݵ��¶����������
	UFUNCTION(BlueprintCallable)
		void CELL_LadderFallActionFinish();

	//֪ͨ����������Entity��������(������������)
	UFUNCTION(BlueprintCallable)
		void CELL_EntityEnterLadder(int32 EnterEntityId);

	//֪ͨ����������Entity�˳�����(�ָ�����������)
	UFUNCTION(BlueprintCallable)
		void CELL_EntityExitLadder(int32 EnterEntityId);

	//֪ͨ�����������׼����ʼ������(��ͼ������:��F������)
	UFUNCTION(BlueprintCallable)
		void CELL_RoleReadyClimbLadder(int32 EnterEntityId);

	virtual void InitBlueCB() override;

private:
	//�����ݵĶ����������
	void CloudLadderActionFinish(ACharacter* Character, FACTION_DATA InActionData);

	//�Ƶ����ݵĶ����������
	void FallLadderActionFinish(ACharacter* Character, FACTION_DATA InActionData);
};