#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtJiuZiZhenYanInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtJiuZiZhenYanInterface.h
* ����˵����
* �ļ����ߣ�qiurunan
* Ŀǰά����qiurunan
* ����ʱ�䣺2020-03-11
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtJiuZiZhenYanInterface : public UMonsterInterface
{
	GENERATED_BODY()
		typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtJiuZiZhenYanInterface();
	~UMonsterExtJiuZiZhenYanInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtJiuZiZhenYanInterface'"); } //��ȡ��ͼ����·��

	/**
	*������֪ͨ������һ�鿪ʼ����
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UMonsterExtJiuZiZhenYanInterface")
		void onStartOccupy();

	/**
	*������֪ͨ������һ���������
	*
	@param isPlayerOccupy:�Ƿ������ռ��(bossռ��)
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UMonsterExtJiuZiZhenYanInterface")
		void onEndOccupy(const uint8& isPlayerOccupy);

	/**
	*���Դ�ǽ������������������Ҷ�
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UMonsterExtJiuZiZhenYanInterface")
		void onPoundPlayer();

	virtual void InitBlueCB() override;

	void Set_zhenyanType(const int32& newVal, const int32& oldVal);///<1����:2����:3������4����:5����:6����:7����:8��ǰ:9����
	void Set_curCorrupt(const int32& newVal, const int32& oldVal);///<��ǰ����ֵ
	void Set_maxCorrupt(const int32& newVal, const int32& oldVal);///<��󸯻�ֵ

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "UMonsterExtJiuZiZhenYanInterface")
		int32 zhenyanType = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "UMonsterExtJiuZiZhenYanInterface")
		int32 curCorrupt = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "UMonsterExtJiuZiZhenYanInterface")
		int32 maxCorrupt = 0;
private:
	bool mIsStartOccupy = false;
	int8 mOccupyStatus = 0;		//0:δ��ռ��  1�����ռ��  2��bossռ��
};
