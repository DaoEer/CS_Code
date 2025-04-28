// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/Monster/MonsterInterface.h"
#include "GameData/Shape/BaseShape.h"
#include "GameData/CharacterData.h"
#include "MonsterExtAttackCityLadderInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtAttackCityLadderInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2020-02-14
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtAttackCityLadderInterface : public UMonsterInterface
{
	GENERATED_BODY()
	typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtAttackCityLadderInterface();

	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_MonsterExtAttackCityLadderInterface.BP_MonsterExtAttackCityLadderInterface_C'"); } //��ȡ��ͼ����·��

	UFUNCTION(BlueprintCallable)
		void AddTrap();

	void OnPlayerBeginOverlap();
	void OnPlayerEndOverlap();

	// ����������
	UFUNCTION(BlueprintCallable)
		void OperationLadder(const int32& EntityID_);

	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_CancelTrap();

	//������֪ͨ:�������ƶ���ǽ��-�ƶ�����֪ͨ
	UFUNCTION(BlueprintNativeEvent)
		void CLIENT_LadderMoveFinish(const FString& actionID);

	virtual void InitBlueCB() override;
private:
	UBaseShape* pShape; //��������
};