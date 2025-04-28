// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "KBEngine.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"

#include "CS3InterfaceDeclare.h"

#include "GameData/CS3Object.h"
#include "CS3EntityInterface.generated.h"


/**
 * 
 */
class CS3Entity;

UCLASS(Blueprintable, BlueprintType)
class CHUANGSHI_API UCS3EntityInterface : public UCS3Object
{
	GENERATED_BODY()

public:
	UCS3EntityInterface();
	virtual ~UCS3EntityInterface();

	//entity��ʼ����ɵĻص�
	virtual void __init__() {};

	/**
	* Called after the C++ constructor and after the properties have been initialized, including those loaded from config.
	* mainly this is to emulate some behavior of when the constructor was called after the properties were initialized.
	*/
	virtual void PostInitProperties() override;

	/**
	*��ȡActor
	*
	*@return AActor * OwnerActor
	*/
	UFUNCTION(BlueprintCallable, Category = "CS3EntityInterface")
		AActor *GetActor();

	/**
	*����OwnerActor
	*
	*@param Actor ����Actor
	*
	*@return bool ����OwnerActor����TRUE
	*/
	UFUNCTION(BlueprintCallable, Category = "CS3EntityInterface")
		bool SetActor(const AActor *Actor);

	/**
	*����cell����
	*
	*@param methodname ������
	*@param arguments ��������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "CS3EntityInterface")
		void CellCallWithBp(const FString &methodname, const TArray<FString> &arguments);
	void CellCall(const FString& name, const KBEngine::FVariantArray& args=KBEngine::FVariantArray());
	void BaseCall(const FString& name, const KBEngine::FVariantArray& args = KBEngine::FVariantArray());

	/**
	*����cell����������ΪInt����
	*
	*@param methodname ������
	*@param arguments ��������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "CS3EntityInterface")
		void CellCallWithIntList(const FString &methodname, const TArray<int32> &arguments);

	/**
	*����cell����������ΪString����
	*
	*@param methodname ������
	*@param arguments ��������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "CS3EntityInterface")
		void CellCallWithFStringList(const FString &methodname, const TArray<FString> &arguments);

	/**
	*����Base����
	*
	*@param methodname ������
	*@param arguments ��������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "CS3EntityInterface")
		void BaseCallWithBp(const FString &methodname, const TArray<FString> &arguments);
	void BaseCall(const FString& name, KBEngine::FVariantArray& args);

	/**
	*����Base����������ΪInt����
	*
	*@param methodname ������
	*@param arguments ��������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "CS3EntityInterface")
		void BaseCallWithIntList(const FString &methodname, const TArray<int32> &arguments);

	/**
	*����Base����������ΪString����
	*
	*@param methodname ������
	*@param arguments ��������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "CS3EntityInterface")
		void BaseCallWithFStringList(const FString &methodname, const TArray<FString> &arguments);


	/**
	*��ȡ�ӿ�
	*
	*@param FString �ӿ���
	*
	*@return CS3EntityInterface* �ӿڶ���
	*/
	UFUNCTION(BlueprintCallable, Category = "CS3EntityInterface")
		UCS3EntityInterface* GetInterfaceByName(FString interfacname);


	virtual void onEnterWorld();///< ��Entity��������ʱ���˷���������
	virtual void onLeaveWorld(); ///< ��Entity�뿪���磨������ʱ��ʱ���˷���������
	virtual void OnEnterScenes() {};///<��ʼ����
	virtual void OnLeaveScenes() {};///<�뿪����

	UFUNCTION(BlueprintImplementableEvent, Category = "CS3EntityInterface")
		void BP_onEnterWorld();///<BlueprintImplementableEvent�� ��Entity��������ʱ���˷���������
	UFUNCTION(BlueprintImplementableEvent, Category = "CS3EntityInterface")
		void BP_onLeaveWorld();///< BlueprintImplementableEvent����Entity�뿪���磨������ʱ��ʱ���˷���������

	/**
	*��ȡEntity
	*
	*@return KBEngine::Entity*  Entity
	*/
	KBEngine::Entity *GetEntity();

	CS3Entity *GetMyEntity();
	
	//template< typename TT >




	/**
	*����Entity
	*
	*@param ent Entity
	*
	*@return bool ����EntityΪent����TRUE
	*/
	bool SetEntityID(int32 entID);

	/**
	*���ؽӿ�
	*
	*@param KBEEntities ���м̳�CS3EntityInterface�Ľӿ�
	*@param name �ӿ���
	*@param type �ӿ�����
	*@param ent �ӿ�Entity
	*@param entid �ӿ�EntityID
	*
	*@return ��
	*/

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CS3EntityInterface")
		int32 EntityID;///<EntityID

private:
	UPROPERTY()
		AActor *OwnerActor;///<OwnerActor

		//KBEngine::Entity *Entity;///<Entity


//���������Իص�����ͼ����
protected:
	TArray<FString> ArrBlueFunc;
	TArray<FString> ArrBluePropertyCB;

public:
	virtual void InitBlueCB();

//����Զ�̽ӿڵ���
public:
	//����ص�����
	virtual void OnUpdateProperty(const FString &name, const FVariant &newVal, const FVariant &oldVal);
	virtual void OnRemoteMethodCall(const FString &name, const TArray<FVariant> &args);

public:
	static CS3_INTERFACE_METHOD_MAP _thisMethodMap;
	static CS3_INTERFACE_PROPERTY_MAP _thisPropertyMap;
	static void InitMethodMap() { _thisMethodMap.Add(TEXT(""), nullptr); }
	static void InitPropertyMap() { _thisPropertyMap.Add(TEXT(""), nullptr); }
protected:
	virtual void CallDefineMethod(const FString &name, const TArray<FVariant> &args) {};
	virtual void NotifyDefineProperty(const FString &name, const FVariant &newVal, const FVariant &oldVal) {};

public:
	static FString GetName() { return TEXT(""); } 
	static FString GetBlueprintClassPath() { return TEXT(""); } 
};
