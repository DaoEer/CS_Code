#pragma once
#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "AuctionDefineData.generated.h"

/**
* �ļ����ƣ�AuctionDefineData.h
* ����˵�������ķ��������ඨ��
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2020-11-26
*/

///������Ϣ
USTRUCT(BlueprintType)
struct CHUANGSHI_API FAUCTIONMESSAGE
{
	GENERATED_USTRUCT_BODY()
public:
	///���dbid
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString PlayerDBID;
	///��ҳ��۽�0��ʾ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 BidMoney;
};

///����
UCLASS(BlueprintType)
class CHUANGSHI_API UAuctionData : public UCS3Object
{
	GENERATED_BODY()
public:
	///< ����id
	UPROPERTY(BlueprintReadOnly)
		int32 dropboxID;

	///< ��Ʒuid
	UPROPERTY(BlueprintReadOnly)
		FString uid;

	///< ������dbid����������һ���˸���Ʒ����ң�Ĭ��Ϊ0
	UPROPERTY(BlueprintReadOnly)
		FString ownerDBID;

	///< ��Ʒ�Ƿ��ѷ��䣨0���� 1���ǣ�
	UPROPERTY(BlueprintReadOnly)
		uint8 isPickUp;

	///< ��ǰ������ߵ����dbid Ĭ��Ϊ0
	UPROPERTY(BlueprintReadOnly)
		FString maxAuctionDBID;

	///< ��ǰ��߳��� Ĭ��Ϊ-1
	UPROPERTY(BlueprintReadOnly)
		int32 maxAuctionMoney;

	///< ��ǰ������� -1����δ���� 0���������� Ĭ��Ϊ-1
	UPROPERTY(BlueprintReadOnly)
		int32 selfMoney;

	///< �������� Ĭ�ϵ�0�� (��ͳ���Ϊ�׼�)
	UPROPERTY(BlueprintReadOnly)
		int32 round;

	///< ��ǰ���뾺�ĵ����� Ĭ��Ϊ0
	UPROPERTY(BlueprintReadOnly)
		int32 curAuctionRoleAmount;

	///< ������Ϣ���� [[dbid, money], [dbid, money] ...]
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAUCTIONMESSAGE> auctionMessageData;
};

///������ʷ����
UCLASS(BlueprintType)
class CHUANGSHI_API UAuctionHistroy : public UCS3Object
{
	GENERATED_BODY()
public:
	///< ��Ʒid
	UPROPERTY(BlueprintReadOnly)
		FString id;

	///< �ɽ���
	UPROPERTY(BlueprintReadOnly)
		int32 money;

	///< ���
	UPROPERTY(BlueprintReadOnly)
		FString roleName;

	///< ���Ľ����0��ʧ�� 1���ɹ���
	UPROPERTY(BlueprintReadOnly)
		int32 result;
};