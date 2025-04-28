// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Manager/Delegate/MailDelegateObject.h"
#include "GameData/BHZBData.h"
#include "GameData/GameDeFine.h"
#include "TongDelegateObject.generated.h"

/**
 * ���ϵͳί����������
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveCandidateFromBHZB, FString, MemberDBID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInitBHZBNPCPointDatas);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdataToTongMemberClientProtectData, int32, groupTeamID, int32, pointIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdataToTongMemberClientAttackData, int32, groupTeamID, int32, pointIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdataNPCPointRestEndTime, int32, pointIndex, FString, restEndTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdataNPCPointReadyEndTime, int32, pointIndex, FString, readyEndTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdataNPCPointDeclareWarState, int32, pointIndex, uint8, declareWarState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdataNPCPointOccupyTongDBID, int32, pointIndex, FString, occupyTongDBID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpdataHomeBarracksMapDataToAllMember);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpdataMemberPositionToClient);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowExitPointSaveSpaceBtn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHideExitPointSaveSpaceBtn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdataMyGroupIDToClient, int32, groupID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdataBHZBPointJoinAttackMembers, int32, pointIndex, const TArray<FString>&, joinAttackMemberDBIDs);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdataBHZBPointJoinProtectMembers, int32, pointIndex, const TArray<FString>&, JoinProtectMemberDBIDs);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShowGroupIDAttackPointSign, int32, pointIndex, int32, groupID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHideGroupIDAttackPointSign, int32, pointIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShowBHZBIntegralRankWin, const TArray<FBHZBTONGINTEGRALDATA>&, rankDatas, int32, delayCloseTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlunderMemberChange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSetbhzbSignUpMembersIsActive, int32, groupID, bool, isActive, int32, pointIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdateBHZBWarDetailIntegralData, int32, integral, int32, rank);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateBHZBWarDetailOccupyNumber, int32, occupyPointAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnUpdateBHZBWarDetailTeamData, int32, teamNumber, int32, pointIndex, int32, pointState, FString, pointName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveBHZBWarDetailTeamData, int32, teamNumber);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdateBHZBWarDetailOccupyPointData, int32, pointIndex, int32, pointState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAddBHZBWarDetailOccupyPointData, int32, pointIndex, int32, pointState, FString, pointName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddBHZBWarMsgData, int32, statusID, FString, statusArgs);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveBHZBWarrDetailOccupyPoint, int32, pointIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnUpdateNPCPointAttackGroupTeamID, int32, pointIndex, int32, attackGroupTeamID, const FString&, declareTongDBID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdataBHZBPointJoinProtectTeamID, int32, pointIndex, int32, joinProtectTeamID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetTongBattleAllocation, TONG_PICKUP_TYPE, allocation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetTongPlunderAllocation, TONG_PICKUP_TYPE, allocation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOpenTongPickWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClosedTongPickWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOpenTongDicePickWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClosedTongDicePickWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPickUpByLeaderSuccessed, const FString&, uid, const FString&, playerName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTongRollRandomDropBoxResult, int32, DropBoxID, const FString&, ItemUid, int32, Roll);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnTongRollRandomMaxDropBox, int32, DropBoxID, const FString&, ItemUid, const FString&, PlayerName, int32, MaxRoll);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClearAllTongSignMemberData);
UCLASS()
class CHUANGSHI_API UTongDelegateObject : public UMailDelegateObject
{
	GENERATED_BODY()

public:
#pragma region	/** ������� */
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnRemoveCandidateFromBHZB  OnRemoveCandidateFromBHZB;
	/**
	* ������Ծݵ����ݸ������
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnInitBHZBNPCPointDatas OnInitBHZBNPCPointDatas;
	/**
	* ���·��ط�������
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataToTongMemberClientProtectData  OnUpdataToTongMemberClientProtectData;
	/**
	* ���½�����������
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataToTongMemberClientAttackData  OnUpdataToTongMemberClientAttackData;
	/**
	* ���¾ݵ�����ʱ��
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataNPCPointRestEndTime OnUpdataNPCPointRestEndTime;
	/**
	* ���¾ݵ�׼��ʱ��
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataNPCPointReadyEndTime OnUpdataNPCPointReadyEndTime;
	/**
	* ���¾ݵ���ս״̬
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataNPCPointDeclareWarState OnUpdataNPCPointDeclareWarState;
	/**
	* ���¾ݵ�ռ��İ����Ϣ
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataNPCPointOccupyTongDBID OnUpdataNPCPointOccupyTongDBID;
	/**
	* ���´�Ӫ��Ϣ
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataHomeBarracksMapDataToAllMember OnUpdataHomeBarracksMapDataToAllMember;
	/**
	* ���¶�����Ϣ��M���ͼ
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataMemberPositionToClient OnUpdataMemberPositionToClient;
	/**
	* ��ʾ�뿪�ݵ㰴ť
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnShowExitPointSaveSpaceBtn OnShowExitPointSaveSpaceBtn;
	/**
	* �����뿪�ݵ㰴ťM���ͼ
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnHideExitPointSaveSpaceBtn OnHideExitPointSaveSpaceBtn;
	/**
	* ����������ڶ����ŵ�����
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataMyGroupIDToClient OnUpdataMyGroupIDToClient;
	/**
	* ���¾ݵ㹥ռ��Ա
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataBHZBPointJoinAttackMembers OnUpdataBHZBPointJoinAttackMembers;
	/**
	* ���¾ݵ���س�Ա
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataBHZBPointJoinProtectMembers OnUpdataBHZBPointJoinProtectMembers;
	/**
	* ��ʾ�ݵ�������
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnShowGroupIDAttackPointSign OnShowGroupIDAttackPointSign;
	/**
	* ���ؾݵ�������
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnHideGroupIDAttackPointSign OnHideGroupIDAttackPointSign;
	/**
	* ���ؾݵ�������
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnShowBHZBIntegralRankWin OnShowBHZBIntegralRankWin;
	/**
        * ���ð�����Ա�����Ա����״̬
        */
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnSetbhzbSignUpMembersIsActive OnSetbhzbSignUpMembersIsActive;
	/**
	* ���°��ſ����ֺ�����
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdateBHZBWarDetailIntegralData OnUpdateBHZBWarDetailIntegralData;
	/**
	* ���°��ſ�ռ��ݵ�����
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdateBHZBWarDetailOccupyNumber OnUpdateBHZBWarDetailOccupyNumber;
	/**
        * ���°��ſ�ĳ��������Ϣ
        */
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdateBHZBWarDetailTeamData OnUpdateBHZBWarDetailTeamData;
	/**
	* �Ƴ����ſ�ĳ������
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnRemoveBHZBWarDetailTeamData OnRemoveBHZBWarDetailTeamData;
	/**
	* ���°��ſ�ĳ���ݵ�״̬����
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdateBHZBWarDetailOccupyPointData OnUpdateBHZBWarDetailOccupyPointData;
	/**
	* ���Ӱ��ſ��ݵ�����
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnAddBHZBWarDetailOccupyPointData OnAddBHZBWarDetailOccupyPointData;
	/**
	* �Ƴ����ſ��ݵ�����
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
                FOnRemoveBHZBWarrDetailOccupyPoint OnRemoveBHZBWarrDetailOccupyPoint;
	/**
        * ���Ӱ��ϵͳ��Ϣ
        */
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnAddBHZBWarMsgData OnAddBHZBWarMsgData;
	/**
	 * ���¾ݵ��������ID
	 */
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdateNPCPointAttackGroupTeamID OnUpdateNPCPointAttackGroupTeamID;
	/**
	* ���¾ݵ�ط�����ID
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnUpdataBHZBPointJoinProtectTeamID OnUpdataBHZBPointJoinProtectTeamID;
	/**
	* ������Խ����������������
	*/
	UPROPERTY(BlueprintAssignable, Category = "Tong|BHZB")
		FOnClearAllTongSignMemberData OnClearAllTongSignMemberData;

#pragma endregion
#pragma region	/** �Ӷ�ս */
	UPROPERTY(BlueprintAssignable, Category = "Tong|Plunder")
		FOnPlunderMemberChange OnPlunderMemberChange;
#pragma endregion

#pragma region	/** ���ʰȡ */
	//���ð�����Է���ģʽ
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
		FOnSetTongBattleAllocation OnSetTongBattleAllocation;
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
	//���ð���Ӷ����ģʽ
		FOnSetTongPlunderAllocation OnSetTongPlunderAllocation;
	//�򿪰����������
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
		FOnOpenTongPickWnd OnOpenTongPickWnd;
	//�رհ����������
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
		FOnClosedTongPickWnd OnClosedTongPickWnd;
	//�򿪰������������
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
		FOnOpenTongDicePickWnd OnOpenTongDicePickWnd;
	//�رհ������������
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
		FOnClosedTongDicePickWnd OnClosedTongDicePickWnd;
	//��������ɹ�
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
		FOnPickUpByLeaderSuccessed OnPickUpByLeaderSuccessed;
	//���������֪ͨ
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
		FOnTongRollRandomDropBoxResult OnTongRollRandomDropBoxResult;
	//������������ֵ֪ͨ
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
		FOnTongRollRandomMaxDropBox OnTongRollRandomMaxDropBox;
#pragma endregion
};
