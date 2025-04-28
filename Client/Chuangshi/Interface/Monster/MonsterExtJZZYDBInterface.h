#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtJZZYDBInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtJZZYDBInterface.h
* ����˵����
* �ļ����ߣ�qiurunan
* Ŀǰά����qiurunan
* ����ʱ�䣺2020-03-11
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtJZZYDBInterface : public UMonsterInterface
{
	GENERATED_BODY()
		typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtJZZYDBInterface();
	~UMonsterExtJZZYDBInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtJZZYDBInterface'"); } //��ȡ��ͼ����·��

	/**
	*������֪ͨ������һ�鿪ʼ��������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UMonsterExtJZZYDBInterface")
		void onStartOccupy();

	/**
	*������֪ͨ������һ���������
	*
	@param isPlayerOccupy:�Ƿ������ռ��
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UMonsterExtJZZYDBInterface")
		void onEndOccupy(bool isPlayerOccupy);

	//֪ͨ������������ײ��
	UFUNCTION(BlueprintCallable, Category = "UMonsterExtJZZYDBInterface")
		void RPC_onCollisionZYDB(FVector pos);

	//֪ͨ����������ҽ��뱾����
	UFUNCTION(BlueprintCallable, Category = "UMonsterExtJZZYDBInterface")
		void RPC_onEnterZYDBScope();

	//֪ͨ������������뿪������
	UFUNCTION(BlueprintCallable, Category = "UMonsterExtJZZYDBInterface")
		void RPC_onLeaveZYDBScope();
	
	virtual void InitBlueCB() override;
private:
	bool mIsStartOccupy = false;
	int8 mOccupyStatus = 0;		//0:δ��ռ��  1�����ռ��  2��bossռ��
};
