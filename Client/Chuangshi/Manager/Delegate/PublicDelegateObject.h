// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "GameData/AuctionDefineData.h"
#include "PublicDelegateObject.generated.h"

/**
 * ����ί����������
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOpenTestWindow, int32, isOpen);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddHasStoreAppearance, int32, ItemID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddStoreAppearance, int32, ItemID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveStoreAppearance, int32, ItemID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddStoreTryAppearance, int32, PartType, int32, GoodsID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRemoveStoreTryAppearance, int32, PartType, int32, GoodsID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClearStoreTryAppearance);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShowStartBillingWnd, int32, Level, int32, CountDownTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHideStartBillingWnd);
//----���۷���
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOpenAuctionPickWnd, int32, DropBoxType, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCloseAuctionPickWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddDropBoxAuction, int32, DropBoxType, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnAuctionBid, int32, DropBoxID, FString, UID, int32, Money, FString, PlayerDBID, FString, CountDownTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAuctionAbandon, int32, DropBoxID, FString, UID, FString, PlayerDBID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAuctionItemEnd, int32, DropBoxID, FString, UID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAddAuctionMessage, int32, DropBoxID, FString, UID, FAUCTIONMESSAGE, AuctionMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRecvAuctionHistoryData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddAuctionHistory, UAuctionHistroy*, AuctionHistroy);
//----���۷���end
//----ʰȡ
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTongUpdatePickUpWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamUpdatePickUpWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPickUpSuccessed, int32, DropBoxID, const FString&, ItemUid);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClosedPickUpWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateTeamDicePickWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClosedTeamDicePickWnd);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTeamRollPickupResult, int32, DropBoxID, const FString&, ItemUid, int32, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateTeamPickWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClosedTeamPickWnd, int32, DropBoxID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPickUpByCaptainSuccessed, const FString&, uid, const FString&, playerName);
//----ʰȡend
//----�����ؾ�
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetDismountVehicleVisibility, bool, IsVisibility);
//----�����ؾ�end
UCLASS()
class CHUANGSHI_API UPublicDelegateObject : public UCS3Object
{
	GENERATED_BODY()
public:
#pragma region	/** gm��ĳ�������֪ͨ�¼� */
	//�򿪴�������
	UPROPERTY(BlueprintAssignable, Category = "GM|TestWindow")
		FOnOpenTestWindow OnOpenTestWindowByGM;
#pragma endregion

#pragma region	/** ʰȡ�����֪ͨ�¼� */
	//����������ʰȡ����
	UPROPERTY(BlueprintAssignable, Category = "Allocation|Tong|PickupWnd")
		FOnTongUpdatePickUpWnd OnTongUpdatePickUpWnd;
	//�����������ʰȡ����
	UPROPERTY(BlueprintAssignable, Category = "Allocation|Team|PickupWnd")
		FOnTeamUpdatePickUpWnd OnTeamUpdatePickUpWnd;
	//����ʰȡ�ɹ�
	UPROPERTY(BlueprintAssignable, Category = "Allocation|Team|PickupWnd")
		FOnPickUpSuccessed OnPickUpSuccessed;
	//�ر�ʰȡ����
	UPROPERTY(BlueprintAssignable, Category = "Allocation|PickupWnd")
		FOnClosedPickUpWnd OnClosedPickUpWnd;
	//���¶�������ʰȡ����
	UPROPERTY(BlueprintAssignable, Category = "Allocation|Team|DicePickupWnd")
		FOnUpdateTeamDicePickWnd OnUpdateTeamDicePickWnd;
	//�رն�������ʰȡ����
	UPROPERTY(BlueprintAssignable, Category = "Allocation|Team|DicePickupWnd")
		FOnClosedTeamDicePickWnd OnClosedTeamDicePickWnd;
	//����������Ʒ���շ���֪ͨ
	UPROPERTY(BlueprintAssignable, Category = "Allocation|Team|DicePickupWnd")
		FOnTeamRollPickupResult OnTeamRollPickupResult;
	//���¶ӳ������������
	UPROPERTY(BlueprintAssignable, Category = "Allocation|Team|TeamPickWnd")
		FOnUpdateTeamPickWnd OnUpdateTeamPickWnd;
	//�رնӳ��������
	UPROPERTY(BlueprintAssignable, Category = "Allocation|Team|TeamPickWnd")
		FOnClosedTeamPickWnd OnClosedTeamPickWnd;
	//�ӳ�����ɹ�
	UPROPERTY(BlueprintAssignable, Category = "Tong|Allocation")
		FOnPickUpByCaptainSuccessed OnPickUpByCaptainSuccessed;
#pragma endregion

#pragma region	/** �̳� */
	//����ӵ�����
	UPROPERTY(BlueprintAssignable, Category = "AppearMall")
		FOnAddHasStoreAppearance OnAddHasStoreAppearance;
	//�����̳����
	UPROPERTY(BlueprintAssignable, Category = "AppearMall")
		FOnAddStoreAppearance OnAddStoreAppearance;
	//�ѵ��̳����
	UPROPERTY(BlueprintAssignable, Category = "AppearMall")
		FOnRemoveStoreAppearance OnRemoveStoreAppearance;
	//�Դ��̳����
	UPROPERTY(BlueprintAssignable, Category = "AppearMall")
		FOnAddStoreTryAppearance OnAddStoreTryAppearance;
	//ȡ���Դ��̳����
	UPROPERTY(BlueprintAssignable, Category = "AppearMall")
		FOnRemoveStoreTryAppearance OnRemoveStoreTryAppearance;
	//ȡ�������Դ��̳����
	UPROPERTY(BlueprintAssignable, Category = "AppearMall")
		FOnClearStoreTryAppearance OnClearStoreTryAppearance;
#pragma endregion

#pragma region	/** ��Ϸ���� */
	//��ʾ����ʱ�����ڽ���
	UPROPERTY(BlueprintAssignable, Category = "TopUp")
		FOnShowStartBillingWnd OnShowStartBillingWnd;
	//���ظ���ʱ�����ڽ���
	UPROPERTY(BlueprintAssignable, Category = "TopUp")
		FOnHideStartBillingWnd OnHideStartBillingWnd;
#pragma endregion

#pragma region	/** ���۷��� */
	//��ʾ���۽���
	UPROPERTY(BlueprintAssignable, Category = "Auction")
		FOnOpenAuctionPickWnd OnOpenAuctionPickWndEvent;
	//�رվ��۽���
	UPROPERTY(BlueprintAssignable, Category = "Auction")
		FOnCloseAuctionPickWnd OnCloseAuctionPickWndEvent;
	//׷�Ӿ��ı���
	UPROPERTY(BlueprintAssignable, Category = "Auction")
		FOnAddDropBoxAuction OnAddDropBoxAuctionEvent;
	//����
	UPROPERTY(BlueprintAssignable, Category = "Auction")
		FOnAuctionBid OnAuctionBidEvent;
	//��������
	UPROPERTY(BlueprintAssignable, Category = "Auction")
		FOnAuctionAbandon OnAuctionAbandonEvent;
	//��Ʒ���Ľ���
	UPROPERTY(BlueprintAssignable, Category = "Auction")
		FOnAuctionItemEnd OnAuctionItemEndEvent;
	//�յ�������ʷ�б�����ķ������ݣ�
	UPROPERTY(BlueprintAssignable, Category = "Auction")
		FOnRecvAuctionHistoryData OnRecvAuctionHistoryDataEvent;
	//����һ����ʷ�б�
	UPROPERTY(BlueprintAssignable, Category = "Auction")
		FOnAddAuctionHistory OnAddAuctionHistoryEvent;
	//����һ��������Ϣ
	UPROPERTY(BlueprintAssignable, Category = "Auction")
		FOnAddAuctionMessage OnAddAuctionMessageEvent;
#pragma endregion

#pragma region	/** �����ؾ� */
	//��ʾ���ض����ؾ����ؾ߰�ť
	UPROPERTY(BlueprintAssignable, Category = "MoveVehicle")
		FOnSetDismountVehicleVisibility OnSetDismountVehicleVisibility;
#pragma endregion
};
