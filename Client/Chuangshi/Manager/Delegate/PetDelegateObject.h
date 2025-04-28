#pragma once

#include "CoreMinimal.h"
#include "Manager/Delegate/RelationDelegateObject.h"
#include "PetDelegateObject.generated.h"

/**
 * ����ϵͳ ί����������
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdatePetShenTongSkill, FString, PetUID);

UCLASS()
class CHUANGSHI_API UPetDelegateObject : public URelationDelegateObject
{
	GENERATED_BODY()
public:
#pragma region	/** ������ͨ���� */
	//���»�����ͨ���ܣ����ӡ�ɾ�������´�����
	UPROPERTY(BlueprintAssignable, Category = "Pet")
		FOnUpdatePetShenTongSkill OnUpdatePetShenTongSkillEvent;
#pragma endregion
};
