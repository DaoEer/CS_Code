#pragma once
#include "Interface/NPC/NPCInterface.h"
#include "GameData/NPCShopData.h"
#include "Entity/Alias.h"
#include "NPCExtMysteriousShopInterface.generated.h"

/*
* �ļ����ƣ�NPCExtMysteriousShopInterface.h
* ����˵����
* �ļ����ߣ�QRN
* Ŀǰά����QNR
* ����ʱ�䣺2020-08-18
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UNPCExtMysteriousShopInterface : public UNPCInterface
{
	GENERATED_BODY()
	typedef UNPCInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UNPCExtMysteriousShopInterface();
	~UNPCExtMysteriousShopInterface();
	static FString GetName() { return TEXT("NPCExtMysteriousShopInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_NPCExtMysteriousShopInterface.BP_NPCExtMysteriousShopInterface_C'"); } //��ȡ��ͼ����·��

	//��ȡ�������˳��۵���Ʒ��Ϣ
	UFUNCTION(BlueprintCallable, Category = "CS3|MysteriousShopNPC")
		void RequestShopData();

	//������������˴�����ָ����Ʒ
	UFUNCTION(BlueprintCallable, Category = "CS3|MysteriousShopNPC")
		void RequestBuyShopItem(int32 slotID, int32 amount);

	//���յ��������˳��۵���Ʒ��Ϣ
	void recvMysteriousShopData(const FVariant& datas);
	UFUNCTION(BlueprintImplementableEvent, Category = "CS3|MysteriousShopNPC")
		void onRecvMysteriousShopData();

	//����ɹ�
	void onSuccessBuyShopItem(const int32& slotID, const int32& amount);
	UFUNCTION(BlueprintImplementableEvent, Category = "CS3|MysteriousShopNPC")
		void onSuccessBuyShopItemEvent();

	void InitShopDatas();

	UFUNCTION(BlueprintCallable, Category = "CS3|MysteriousShopNPC")
		TMap<int32, FMysteriousShopData> getShopDatas() { return ShopDatas; }

	virtual void InitBlueCB() override;

private:
	TMap<int32, FMYSTERIOUSSHOPDATA_MAP> ShopSVRDatas;			// ��¼��Ʒʣ����Ŀ{ slotID �� ��Ʒ���� }
	TMap<int32, FMysteriousShopData> ShopDatas;					// ��¼��Ʒ�۸����������{ slotID �� configData }
};
