#pragma once

#include "Actor/GameCharacter.h"
#include "GameData/CharacterData.h"
#include "GameData/SpaceDynamicEffectData.h"
#include "SceneCharacter.generated.h"

/*
* �ļ����ƣ�SceneCharacter.h
* ����˵�����������ͻ���entityЧ����Ӧ�����š���
* �ļ����ߣ�huting
* Ŀǰά����huting
* ����ʱ�䣺2017-08-8
*/


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSceneCreateApperanceOverDelegate, AGameCharacter*, SceneCharacter);
/*
* ����Character
*/
UCLASS(BlueprintType)
class CHUANGSHI_API ASceneCharacter :public AGameCharacter
{
	GENERATED_BODY()
public:
	ASceneCharacter();///<���캯��
	virtual void BeginPlay()override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void CreateActorData(FCREATE_ENTITY_EFFECT_DATA EntityEffectData);

	void SetActionData(TArray<FString> actionName, TArray<float> actionInterval, bool bIsRandom = false);//���ö������ݲ����´����Ŷ���

	void SetEffectData(TArray<FString> effectID, TArray<float> effectInterval, bool bIsRandom = false);//���ù�Ч���ݲ����´����Ŷ���

	void SetDestroyAction(FString actionName);///<������������

	void SetDestroyEffect(FString effectID);///<����������Ч

	UFUNCTION(BlueprintImplementableEvent)
		void InitEffectData(const FSPACEDYNAMICEFFECT_DATA dictData);

	void ClearActionData();//�����������
	void ClearEffectData();//�����Ч����

	UFUNCTION(BlueprintNativeEvent)
	void OnBeginDestroyActor();///<��ʼ����֮ǰ�Ĳ���

	UFUNCTION()
	void CheckPlayEffect();///<��Ч�����¼�
	UFUNCTION()
	void OnPlayDestroyEffectOver();///<����ʱ��Ч�����¼�
private:
	virtual void InitBaseComponent() override;///<��дInitBaseComponent		
	virtual void OnCreateApperanceOver() override;
	virtual void OnChangePartOver() override;

	void SetModelScale(const float &newValue);
	void SetCollisionType(const FString &newValue);

	void PlayMultiAction();	///<���Ŷ���
	void CheckPlayAction(ACharacter *RoleChar, FACTION_DATA InActionData);///<��ⲥ�Ŷ���
	void OnPlayDestroyActionOver(ACharacter *RoleChar, FACTION_DATA InActionData);

	void PlayMultiEffect();	///<���Ź�Ч
	void SetMeshCollisionType(ECollisionEnabled::Type CollisionTYpe);
	void SetCollisionCollisionTypeAndResponseToChannel(UMeshComponent* SKComp, ECollisionEnabled::Type CollisionTYpe);

	int GetRandomIndex(int MaxRandomIndex);///<��ȡ�����
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ModelNumber;
	float ModelScale;
	FSceneCreateApperanceOverDelegate SceneCreateApperanceOver;

protected:
	//UPROPERTY()
	//	AEffectEmitter* CurEffect;///<��ǰ���ڲ��ŵĹ�Ч

	int32 CurEffectUID = -1;///<��ǰ���ŵĹ�Ч��UID
private:
	bool bIsRandomAction = false;///<�Ƿ�������Ŷ���
	bool bIsRandomEffect = false;///<�Ƿ�������Ź�Ч
	FString CollisionType;
	bool bAffectNavigation;///<���Դ���Ѱ·
	bool bCameraCollision = false;///<�Ƿ��������������ײ	
	bool bVisibilityCollision = false;///<�Ƿ���ɼ��Ķ�������ײ	
	TArray<FString> ActionNames;///<����ID
	TArray<float> ActionIntervals;///<���Ŷ��������ʱ���� 
	TArray<FString> EffectIDs;///<��ЧID
	TArray<float> EffectIntervals;///<���Ŷ����Ч��ʱ���� 
	FString DeathActionID;///<��������ID
	FString DeathEffectID;///<������ЧID
	FTimerHandle DelayHandle;///<������ʱ��
	FTimerHandle DelayEffectHandle;///<��Ч��ʱ��
};