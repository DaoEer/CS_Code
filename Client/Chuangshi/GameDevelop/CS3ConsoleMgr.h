// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "FileManager.h"
#include "Map.h"
#include "UObject/Object.h"
#include "UnrealString.h"
#include "Util/CS3Debug.h"
#include "CS3ConsoleMgr.generated.h"

/*
* �ļ����ƣ�CS3ConsoleMgr.h
* ����˵����
* �ļ����ߣ�wuxiaoou
* Ŀǰά����zhangyuxing
* ����ʱ�䣺2018-04-28
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHUANGSHI_API UCS3ConsoleMgr : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCS3ConsoleMgr();

	//�Ե�ǰ����������Ϣ�����Զ�������
	UFUNCTION(Exec)
		void CS3_SampleLevel(bool isConfig = false, float xDelta = 4000, float yDelta = 4000, float sampleTime = 0.5);

	/*��������*/
//------------------GameState-------------------

//��ǰ��Ϸ״̬
	UFUNCTION(Exec)
		void CS3_CurrGameState();

	/**
	*�����͹ر���Ļ�����־
	*	@param	isToggled:	���ΪTrue����ʹ�ÿ���/�ر�ģʽ����������isEnabled������ر����
	*/
	UFUNCTION(Exec)
		static void CS3_SetScreenPrintLog(bool isToggled = true, bool isEnabled = true);

	//------------------Level-------------------

	//��ǰ�ؿ�
	UFUNCTION(Exec)
		void CS3_CurrLevel();

	//------------------Entity-------------------

	//Entity������ʾ
	UFUNCTION(Exec)
		void CS3_EntityNumber();

	//��Χ�ڵ�Entity��ʾ
	UFUNCTION(Exec)
		void CS3_EntityInRange(float Range);

	//entity λ��
	UFUNCTION(Exec)
		void CS3_Pos(int32 EntityID);

	//------------------Actor-------------------	

	//GameActor������ʾ _____________________________***
	UFUNCTION(Exec)
		void CS3_GameActorNumber();

	//��ѯActor�Ŀɼ��Բ���entityID
	UFUNCTION(Exec)
		void CS3_QueryActorVS(int32 entityid);

	//------------------Player-------------------	

	//Player����
	UFUNCTION(Exec)
		void CS3_PlayerNumber();

	//����
	UFUNCTION(Exec)
		void CS3_SwitchFly();

	///����/�رյ���
	UFUNCTION(Exec)
		void CS3_SwitchFish();

	//------------------Monster-------------------	

	//Monster����
	UFUNCTION(Exec)
		void CS3_MonsterNumber();


	//------------------NPC-------------------	

	//NPC����
	UFUNCTION(Exec)
		void CS3_NPCNumber();

	//------------------Monster-------------------	

					/*�������ܵ���*/
	//------------------����-------------------	

	UFUNCTION(Exec)
		void CS3_TestCallCell(const int32&  entityID, const FString &methodname, const FString& argument);

	UFUNCTION(Exec)
		void CS3_TestCallClient(const int32& entityID, const FString& methodname, const FString& argument);

	UFUNCTION(Exec)
		void CS3_TestCallBase(const int32&  entityID, const FString &methodname, const FString& argument);

	//------------------��־-------------------	


	//------------------����-------------------	

	//������������
	UFUNCTION(Exec)
		void CS3_TestAsyncLoadAllMesh(const FString& Args);

	//------------------����-------------------	

	//������������
	UFUNCTION(Exec)
		void CS3_TestLoadParticles();

	UFUNCTION(Exec)
		void CS3_PlayParticles(FString EffectId);

	//------------------��¼-------------------	

	//���ķ�����IP
	UFUNCTION(Exec)
		void CS3_ChangeServerIP(const FString& ServerIP);

	//���ĵ�¼��ʽ	����0��ֱ�ӵ�¼��1ѡ���ɫ��¼
	UFUNCTION(Exec)
		void CS3_ChangeLoginMode(int32 Type);

	//------------------����-------------------	

	//������������Ҫ��������·��
	UFUNCTION(Exec)
		void CS3_PlaySound(const FString& AudioPath);

	//�����ղŲ��ŵ�����
	UFUNCTION(Exec)
		void CS3_StopSound();

	//�л��򿪹ر���Чϵͳ
	UFUNCTION(Exec)
		void CS3_TogglePlayAudioSystem();

	//------------------����-------------------	

	//���ž��飬��Ҫ����ID 	/** �ͻ��˲��ž�����Դ */
	UFUNCTION(Exec)
		void CS3_PlayStory(const FString& SequenceId);

	//�����ղŲ��ŵľ���
	UFUNCTION(Exec)
		void CS3_StopStory();

	//------------------ý����Ƶ-------------------	

	//����ý����Ƶ����Ҫý����ƵID 
	UFUNCTION(Exec)
		void CS3_PlayMedia(const FString& MediaId);

	//�����ղŲ��ŵ�ý����Ƶ
	UFUNCTION(Exec)
		void CS3_StopMedia();

	//------------------����-------------------	

	//��ѯ���п��Ӵ���
	UFUNCTION(Exec)
		void CS3_QueryVSWnd();

	//			  /*��Ϸ���ܵ���*/
	////------------------����-------------------	

	////------------------����-------------------	
	//�Ƿ���ʾ�ͷż���������ʾ
	UFUNCTION(Exec)
		void CS3_SetIsPromptSkillName(bool IsPromptSkillName);

	////------------------��Ʒ-------------------	

	////��ʾ��Ʒ��Ϣ����Ҫ������ţ���Ʒ�ڱ�����λ�ã�
	UFUNCTION(Exec)
		void CS3_ItemInfo(int32 order);

	//------------------ս��-------------------	

	//��ѯս����ϵ
	UFUNCTION(Exec)
		void CS3_QueryRelation();


	/*��Ϸ���ܵ���*/
//------------------����-------------------	


//------------------����-------------------	

			  /*��Ϸ���ܵ���*/
//------------------����-------------------	

///����
	UFUNCTION(Exec)
		void CS3_Test(const FString& FunctionName);

	//��ʼ�Զ�����
	UFUNCTION(Exec)
		void CS3_StartAT(const FString& FunctionName);

	/**	��ѯ��ǰ����״̬
	*	@IT_Type	:	��������(eg. 0:����/ 1:����/ 2:��/ 3:���/ 4:���)
	*	@IT_Key		:	�������ֵ(eg. K/L/... )
	*/
	UFUNCTION(Exec)
		void CS3_SearchInputState(int32 IT_Type, FName IT_Key);

	///��ѯentity��ǰ���ŵĶ���
	UFUNCTION(Exec)
		void CS3_CurrEntityAnimation();


	///�ָ����
	UFUNCTION(Exec)
		void CS3_TestLG();

	///<ȫ����
	UFUNCTION(Exec)
		void CS3_SwitchHomingSpellAtt();

	///<�븨��
	UFUNCTION(Exec)
		void CS3_SwitchHalfHomingSpellAtt();

	///<�޸���
	UFUNCTION(Exec)
		void CS3_SwitchNullAtt();

	//	����ָ��
	UFUNCTION(Exec)
		void CS3_Trigger(const int32& Type, const FString& Param1, const FString& Param2);

	///<��ȡActor����
	UFUNCTION(Exec)
		void CS3_GetAllActorsNum();

	///<��ȡActor���ͼ�����������
	UFUNCTION(Exec)
		void CS3_GetAllActorsTypeAndNum();

	///<��һ����Χ�ڵ�Actor����
	UFUNCTION(Exec)
		void CS3_GetAllActorsInRangeTypeAndNum(float Range);

	///<��ȡEntity����
	UFUNCTION(Exec)
		void CS3_GetAllEntitiesNum();

	///<��ȡEntity����
	UFUNCTION(Exec)
		void CS3_GetAllEntitiesTypeAndNum();

	///<��һ����Χ�ڵ�entity����
	UFUNCTION(Exec)
		void CS3_GetAllEntitiesInRangeTypeAndNum(float Range);

	///<��ȡentity��def����
	UFUNCTION(Exec)
		void CS3_GetEntityDefProperty(int32 EntityID, FString Attr);

	///����̨�л�������ҿ���̨����
	UFUNCTION(Exec)
		void CS3_SwtichGameMode();

	UFUNCTION(Exec)
		void CS3_ModelsProfile(int32 modelnumer);

	UFUNCTION(Exec)
		void CS3_CreateFile(bool ModelorEffect);

	UFUNCTION(BlueprintCallable, Category = "consoleMgr")
		void CS3_WriteFile(TArray<FString> content, bool ModelorEffect);

	UFUNCTION(BlueprintCallable, Category = "consoleMgr")
		void CS3_WriteText(FString content, bool Peer);

	UFUNCTION(Exec)
		void CS3_TestShieldText();

	UFUNCTION(Exec)
		void CS3_SetIsUseShield(bool UseShield);

	///����̨�������ػ���ʾȫ������,���������ڲ߻�¼����ʱ����
	UFUNCTION(Exec)
		void CS3_HideOrShowVSWindows(bool bIsHide);
	///����̨�������ػ���ʾ��¼����,���������ڲ߻�¼����ʱ����
	UFUNCTION(Exec)
		void CS3_HideOrShowLoginWindow(bool bIsHide);
	///��ѯEffect�ļ���ȡ������Ч��Դ��д�����
	UFUNCTION(Exec)
		void CS3_GetAssetsByEffect();

	UFUNCTION(Exec)
		void CS3_GetAssetsByRoleLight();

	UFUNCTION(Exec)
		void CS3_TestAutoNavigate(const FVector& DstPosition);

	UFUNCTION(Exec)
		void CS3_TestQuestNavigate(const FString& NPCScriptID, FString DstSpaceName = "");

	UFUNCTION(Exec)
		void CS3_TestSpaceAllQuestNavigate(const FString& DstSpaceName);

	//����һ����������ң��л����ƵĽ�ɫ�����ã�
	UFUNCTION(Exec)
		void CS3_CreateClientPlayer();

	//�л����Ƶ�player��ѡ��һ��playerCharacter�ٵ��ã�
	UFUNCTION(Exec)
		void CS3_SwitchControlPlayer();

	///����ָ������ǰ��ҵ���������ͱ�������
	UFUNCTION(Exec)
		void CS3_GetPlayerPos();

	///����ָ������ǰ�������������ײ��λ�ø߶�
	UFUNCTION(Exec)
		void CS3_GetPlayerFloorTracePos();

	UFUNCTION(Exec)
		void CS3_ForceGarbageCollection();

	UFUNCTION(BlueprintCallable)
		TArray<FString> CS3_StringSort(TArray<FString> stringarray);

	UFUNCTION(Exec)
		void CS3_SwitchEmptyLogicLevel();

	UFUNCTION(Exec)
		void CS3_ChangeSubLebelLoadMode(int32 LoadMode);

	///��ʾ��ǰ�����Ŀ��ľ���
	UFUNCTION(Exec)
		void CS3_TargetDistanceDIsplay();

	///���ص�ǰ�����Ŀ��ľ���
	UFUNCTION(Exec)
		void CS3_TargetDistanceHiding();

	///��ͣ��ɫģ�Ͷ���
	UFUNCTION(Exec)
		void CS3_PauseActorAnims(bool bIsPause, float FindRangle);

	///��ͣ��ɫģ�Ͳ��ϼ���
	UFUNCTION(Exec)
		void CS3_PauseActorCloth(bool bIsPause, float FindRangle);

	///��ͣ��ɫģ�Ͳ��ϼ���
	UFUNCTION(Exec)
		void CS3_OpenScope();

	///�л��������ͷģʽ
	UFUNCTION(Exec)
		void CS3_CareamModeChange();
	///�л�����������ٶ�
	UFUNCTION(Exec)
		void CS3_ChangeFlySpeed (float MaxSpeed);
	///Χ��Ŀ����ת Ŀ�굥λΪ��ǰ���ѡ��Ŀ��
	UFUNCTION(Exec)
		void CS3_RotateRroundToTarget(float Speed, float Disatance, float Height, float angle);
	///ֹͣΧ��Ŀ����ת
	UFUNCTION(Exec)
		void CS3_StopRotateRroundToTarget();
	///�������ת����������� CST-7541
	UFUNCTION(Exec)
		void CS3_OpenLookCamera();
	///<�ı���Ҳ���
	UFUNCTION(Exec)
		void CS3_ChangePart(int32 PartType, FString PartId);
	///<�л�������
	UFUNCTION(Exec)
		void CS3_ChangeRidePet(FString CarrideId);
	///<�л���һ����Ч
	UFUNCTION(Exec)
		void CS3_ChangeBodyLightEffect(FString EffectId);
	///<�л���һ����Ч
	UFUNCTION(Exec)
		void CS3_ShowControllerModeInfo();

	///<�첽��������
	UFUNCTION(Exec)
		void CS3_AsyncPlay3DSound(FString AudioId, int32 count=1);

	///<����첽��������
	UFUNCTION(Exec)
	void CS3_AsyncPlay3DSoundRandomCount(int32 count, int32 times);
	



	//------------------���ڵ��Ի����ܲ���-------------------
	UFUNCTION(Exec)
		void CS3_SetComponentTickState(FString& ComponentName, bool NewTickState);
	UFUNCTION(Exec)
		void CS3_SetPlayerAllComponentTickState(bool NewTickState);
	UFUNCTION(Exec)
		void CS3_SetPlayerVisibleState(bool NewVisibleState);
	UFUNCTION(Exec)
		void CS3_RetainPlayerSkeletalMesh();
	UFUNCTION(Exec)
		void CS3_ToggleEntityServerPos(bool bIsPlayer);
	UFUNCTION(Exec)
		void CS3_Debug(bool isDebug);
	UFUNCTION(Exec)
		void CS3_DebugByName(FString& CS3DebugTypeName, bool isDebug);
	UFUNCTION(Exec)
		void CS3_NotEnablePhysics();
	UFUNCTION(Exec)
		void CS3_NotHair();
	UFUNCTION(Exec)
		void CS3_NotModel();
	UFUNCTION(Exec)
		void CS3_ChangeJobCreateRoleLevel(int32 Job);//�л�������ɫ��ְҵ�ؿ�
	UFUNCTION(Exec)
		void CS3_SetModelHide(FString ScriptId);//����ģ�ͣ����治�����ǻָ����ص�ģ�ͣ�
	UFUNCTION(Exec)
		void CS3_StopModeCurAction(FString ScriptId);//ֹͣ��ǰ����
	UFUNCTION(Exec)
		void CS3_CancelStopModeCurAction(FString ScriptId);//ȡ��ֹͣ��ǰ����
	UFUNCTION(Exec)
		void CS3_StopModelAnim(FString ScriptId);//ֹͣ������������ͼ
	UFUNCTION(Exec)
		void CS3_CancelStopModelAnim(FString ScriptId);//ȡ��ֹͣ������������ͼ
	void ExectModelActionSetup(int32 type, FString ScriptId);
	UFUNCTION(Exec)
		void CS3_LedgesJumpDrawDebug(int32 DrawType);//������ײ������ʾ
	UFUNCTION(Exec)
		void CS3_DisplayStoryLog(bool isDebug);//��ʾ��ͷ��־

	void DisplayStoryLog(FString StoryID, bool bIsPlay);//��ʾ��ͷ��־
	//-----------------------------------------

	/** ��������¼��Ƿ񼤻� // @NOTE �ô��ж϶��״̬���в������򲻼�������� */
	UFUNCTION(BlueprintPure, Category = "CS3layerController|Input")
		bool CheckBindKeyActive(FKey Key);
	UFUNCTION(BlueprintPure, Category = "CS3PlayerController|Input")
		bool CheckBindActionActive(FName Name);
	UFUNCTION(BlueprintPure, Category = "CS3PlayerController|Input")
		bool CheckBindAxisActive(FName Name);
	UFUNCTION(BlueprintPure, Category = "CS3PlayerController|Input")
		bool CheckBindAxisKeyActive(FKey Key);

	void SetEnableEntityServerPos(bool bEnabled) { bEnableEntityServerPos = bEnabled; };
	bool GetEnableEntityServerPos() { return bEnableEntityServerPos; };
	void SetEnablePlayerServerPos(bool bEnabled) { bEnablePlayerServerPos = bEnabled; };
	bool GetEnablePlayerServerPos() { return bEnablePlayerServerPos; };

	///<����AudioMananger��Actor �ؿ��л�������
	void SetEnableAudioSystem(bool bEnabled) { bEnableAudioSystem = bEnabled; };
	bool GetEnableAudioSystem() { return bEnableAudioSystem; };
	AActor* oldPlayer;

public:
	bool isArmLimit;//�Ƿ�������������� CST-CST-7046

private:
	TArray<FString> CacheModelIds;
	bool bEnableEntityServerPos = true;
	bool bEnablePlayerServerPos = true;
	bool bEnableAudioSystem = true;
	bool bEnableDisplayStoryLog = false;
};
