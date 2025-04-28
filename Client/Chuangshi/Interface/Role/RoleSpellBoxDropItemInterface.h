// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CS3Base/CS3EntityInterface.h"
#include "GameData/Item/ItemBase.h"
#include "RoleSpellBoxDropItemInterface.generated.h"

/*
* �ļ����ƣ�RoleSpellBoxDropItemInterface.h
* ����˵����
* �ļ����ߣ�yikun
* Ŀǰά����yikun
* ����ʱ�䣺2019-10-24
*/

/**
 * ���SpellBoxʰȡ��Ʒ�ӿ�
 */
UCLASS(BlueprintType)
class CHUANGSHI_API URoleSpellBoxDropItemInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleSpellBoxDropItemInterface();
	~URoleSpellBoxDropItemInterface();

	static FString GetName() { return TEXT("RoleSpellBoxDropItemInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleSpellBoxDropItemInterface.BP_RoleSpellBoxDropItemInterface_C'"); } //��ȡ��ͼ����·��


	/**
	* Define method
	* ��SpellBox���佻���������ص����ͻ���ʰȡ��Ʒ��Ϣ�б�
	*
	* @return ��
	*/
	void SendSpellBoxPickItems(const int32& spellBoxEntityID, const FVariant& Var);

	TArray<UItemBase*> AnalyzeSpellBoxPickItems(const FVariant& Var);

	///<�������Actor�򿪱���ص�֪ͨ��ͼ��ʾʰȡ����
	UFUNCTION(BlueprintImplementableEvent, Category = "RoleSpellBoxDropItemInterface")
	void OnShowSpellBoxPickItems(const int32& spellBoxEntityID);

	/**
	* BlueprintCallable��֪ͨSpellBoxPickItem �������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleSpellBoxDropItemInterface")
	void NotifySpellBoxInteractiveOver(const int32& spellBoxEntityID);

	/**
	* BlueprintCallable��ʰȡ�����������Ʒ
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleSpellBoxDropItemInterface")
	void PickUpSpellBoxItem(const int32& spellBoxEntityID, const TArray<FString>& ItemUidList);

	/**
	* BlueprintCallable���رս���� �����������
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleSpellBoxDropItemInterface")
		void ClearPickUpSpellBoxItemData();

	/**
	* Define method
	* BlueprintNativeEvent��ʰȡ����Ʒ�Ļص�
	*
	* @return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleSpellBoxDropItemInterface")
	void OnPickUpSpellBoxItem(const int32& spellBoxEntityID,const FString& ItemUid);


	/**
	* Define method
	* ������֪ͨ�ͻ���ʰȡ��Ʒ����Ա
	*
	* @return ��
	*/
	void OnPickUpSpellBoxToMember(const int32& SpellBoxEntityID, const FString& UId, const FVariant& Members);

	UFUNCTION(BlueprintNativeEvent, Category = "RoleSpellBoxDropItemInterface")
		void OnPickUpSpellBoxToMember_BP(int32 SpellBoxEntityID,const FString& UId, const TMap<int32, FString>& MemberInfos); //
	/**
	* �ͻ���֪ͨ������ʰȡ��Ʒ����Ա
	*
	* @return ��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleSpellBoxDropItemInterface")
		void PickUpSpellBoxToMember(int32 SpellBoxEntityID, const FString ItemUId, const int32 DstEntityID);

	void OnSpellBoxPickItemDestroyed(const int32& spellBoxEntityID);

	///< �������ٻص���֪ͨ��ͼ�ر�ʰȡ���棩
	UFUNCTION(BlueprintImplementableEvent, Category = "RoleSpellBoxDropItemInterface")
	void BP_OnSpellBoxPickItemDestroyed(const int32& spellBoxEntityID);

	virtual void onLeaveWorld() override;
	virtual void InitBlueCB() override;
public:
	///<�������Ʒ�б�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RoleSpellBoxDropItemInterface")
	TArray<UItemBase*> SpellBox_ItemList;
};