#pragma once
#include "Blueprint/UserWidget.h"
#include "CS3Base/CS3UserWidget.h"
#include "CS3TipsInfoWidget.generated.h"

/*
* �ļ����ƣ�TipsInfoWidget.h
* ����˵����
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2019-01-03
*/

class UTipsManager;

UCLASS(BlueprintType)
class CHUANGSHI_API UCS3TipsInfoWidget : public UCS3UserWidget
{
	GENERATED_BODY()
public:

	/**
	*BlueprintNativeEvent����ʼ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3TipsInfoWidget")
		void InitInfo();

	/**
	*BlueprintNativeEvent����ʾ��ͨ��Ϣ��ʾ����
	*
	*@param  Infos ��ͨ��Ϣ��ʾ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3TipsInfoWidget")
		void ShowToolTips(const FString& Infos);

	/**
	*BlueprintNativeEvent����ʾ��Ʒ��Ϣ��ʾ����
	*
	*@param  ItemInfo ��Ʒ��Ϣ��ʾ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3TipsInfoWidget")
		void ShowItemInfo(const UItemInfo* ItemInfo);

	/**
	*BlueprintNativeEvent����ʾװ����Ϣ��ʾ����
	*
	*@param  EquipInfo װ����Ϣ��ʾ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3TipsInfoWidget")
		void ShowEquipInfo(const UEquipInfo* EquipInfo);

	/**
	*BlueprintNativeEvent����ʾ��Ʒ��Ϣ��ʾ����
	*
	*@param  GoodsInfo ��Ʒ��Ϣ��ʾ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3TipsInfoWidget")
		void ShowGoodsInfo(const UGoodsInfo* GoodsInfo);


	/**
	*BlueprintNativeEvent����ʾ������Ϣ��ʾ����
	*
	*@param  GoodsInfo ������Ϣ��ʾ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3TipsInfoWidget")
		void ShowSkillInfo(const USkillInfo* SkillInfo);

	/**
	*BlueprintNativeEvent����ʾBuff��Ϣ��ʾ����
	*
	*@param  BuffInfo Buff��Ϣ��ʾ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3TipsInfoWidget")
		void ShowBuffInfo(const UBuffInfo* BuffInfo);

	/**
	*BlueprintNativeEvent����ʾͼֽ��Ϣ��ʾ����
	*
	*@param  EquipInfo ͼֽ��Ϣ��ʾ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3TipsInfoWidget")
		void ShowBlueprintInfo(const UBlueprintInfo* BlueprintInfo);

	/**
	*BlueprintNativeEvent����ʾ���Ʒװ����Ϣ��ʾ����
	*
	*@param  EquipInfo ���Ʒװ����Ϣ��ʾ��
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "CS3TipsInfoWidget")
		void ShowEquipPartInfo(const UEquipPartInfo* EquipPartInfo);
};