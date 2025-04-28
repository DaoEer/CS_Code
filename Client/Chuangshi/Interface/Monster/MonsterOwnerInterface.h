// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CS3Base/CS3EntityInterface.h"
//#include "Delegate.h"
#include "MonsterOwnerInterface.generated.h"

/*
* �ļ����ƣ�MonsterOwnerInterface.h
* ����˵����
* �ļ����ߣ�liaojing
* Ŀǰά����liaojing
* ����ʱ�䣺2019-1-30
*/


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetBootyOwnerAssist, int32, SelfEntityID);

/*
* ��������Ȩ���ݽṹ��
*/
USTRUCT(BlueprintType)
struct CHUANGSHI_API FBootOwnerData
{
	GENERATED_BODY()
public:
	int32 type;
	int32 ownerID;
};


UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterOwnerInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
	typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterOwnerInterface();
	~UMonsterOwnerInterface();
	static FString GetName() { return TEXT("MonsterOwnerInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterOwnerInterface'"); } //��ȡ��ͼ����·��

public:

	//��ǰ����Ƿ�Ϊӵ����
	UFUNCTION(BlueprintCallable, Category = "MonsterOwnerInterface")
		bool PlayerIsOwner();

	/**
	* Define method
	* BlueprintCallable������Ȩ֪ͨ
	*
	* @param data ����������Ϣ
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "MonsterOwnerInterface")
		void CLIENT_OnSetBootyOwner(const FString& data);

	//�жϴ�ID����Ӧ���Ƿ���������
	UFUNCTION(BlueprintCallable, Category = "MonsterOwnerInterface")
		bool CheckOwner(int32 type, int32 id);

	UPROPERTY(BlueprintAssignable, Category = "MonsterOwnerInterface")
		FOnSetBootyOwnerAssist OnSetBootyOwnerAssist;

	//�жϴ�ID����Ӧ���Ƿ���������
	UFUNCTION(BlueprintCallable, Category = "MonsterOwnerInterface")
		bool hasOwner();


	virtual void InitBlueCB() override;

private:
	TArray<FBootOwnerData> bootOwnerList;	///<��������Ȩ��Ϣ�б�
	TArray<int32> bootOwnerIDList;
};
