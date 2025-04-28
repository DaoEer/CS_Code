#pragma once
#include "Entity/Alias.h"
#include "Interface/NPC/NPCInterface.h"
#include "NPCExtCaveHouseInterface.generated.h"

/*
* �ļ����ƣ�NPCExtCaveHouseInterface.h
* ����˵����
* �ļ����ߣ�wujiannan
* Ŀǰά����wujiannan
* ����ʱ�䣺2020-04-17
*/
UCLASS(BlueprintType)
class CHUANGSHI_API UNPCExtCaveHouseInterface : public UNPCInterface
{
	GENERATED_BODY()
		typedef UNPCInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UNPCExtCaveHouseInterface();
	~UNPCExtCaveHouseInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.NPCExtCaveHouseInterface'"); } //��ȡ��ͼ����·��
	virtual void InitBlueCB() override;

	// ���ý�����Ч
	void Set_lightWallID(const int32& newVal, const int32& oldVal);
	/**
	*Define Method
	*BlueprintNativeEvent,֪ͨ�򿪽���ͷ��UI
	*@param	endBuildTime  ����ʱ��
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "cs3|NPCExtCaveHouseInterface")
		void OnShowBuildUI(const FString& endBuildTime);

	// �������� ��ֲģ��
	void OnShowLingTian(const FVariant& Var);

	LINGTIAN_DATA GetLingTianDataByIndex(const int32& index);

	// ����
	UPROPERTY()
		TMap<int32, class APlantCharacter*> PlantCharacterMap;

protected:
	virtual void onEnterWorld() override;     ///< ��Entity��������ʱ���˷���������
	virtual void onLeaveWorld() override;     ///< ��Entity�뿪���磨������ʱ��ʱ���˷���������

private:
	int32 LightWallUID;				// ������ǽ��Ч

	LINGTIAN_DATA_ARR LTDatas;			// ��������
};
