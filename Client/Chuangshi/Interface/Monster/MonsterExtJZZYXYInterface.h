#pragma once

#include "Interface/Monster/MonsterInterface.h"
#include "MonsterExtJZZYXYInterface.generated.h"

/*
* �ļ����ƣ�MonsterExtJZZYXYInterface.h
* ����˵����
* �ļ����ߣ�qiurunan
* Ŀǰά����qiurunan
* ����ʱ�䣺2020-03-11
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UMonsterExtJZZYXYInterface : public UMonsterInterface
{
	GENERATED_BODY()
		typedef UMonsterInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	UMonsterExtJZZYXYInterface();
	~UMonsterExtJZZYXYInterface();
	static FString GetName() { return TEXT("GameObjectInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("Class'/Script/Chuangshi.MonsterExtJZZYXYInterface'"); } //��ȡ��ͼ����·��

	//֪ͨ����������Ҳȵ�����Ӱ
	UFUNCTION(BlueprintCallable, Category = "UMonsterExtJZZYXYInterface")
		void RPC_onTreadZYXY();

	//֪ͨ����������Ҳ������
	UFUNCTION(BlueprintCallable, Category = "UMonsterExtJZZYXYInterface")
		void RPC_onTreadZYPoint();

	/**
	*������֪ͨ������һ�鿪ʼ��������
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UMonsterExtJZZYXYInterface")
		void onStartOccupy();

	/**
	*������֪ͨ������һ���������
	*
	@param isPlayerOccupy:�Ƿ������ռ��(bossռ�죬��ҪϨ�������Ѿ������ĵ�)
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UMonsterExtJZZYXYInterface")
		void onEndOccupy(bool isPlayerOccupy);

	//�жϵ�ǰ�Ƿ��ܵ�����Ӱ
	bool isCanLight(int32 entityID);
	//֪ͨ����������Ҳȵ�����Ӱ
	UFUNCTION(BlueprintCallable, Category = "UMonsterExtJZZYXYInterface")
	bool BP_isCanLight();

	//֪ͨ����������Ҳȵ�����Ӱ
	UFUNCTION(BlueprintCallable, Category = "UMonsterExtJZZYXYInterface")
		void BP_StarStepFloor(float Distance, FString effectID);

	//ֹͣ��Ҳȵ�����ӰSetTimer֪ͨ
	UFUNCTION(BlueprintCallable, Category = "UMonsterExtJZZYXYInterface")
		void BP_StopStepFloor();

	/**
	*������֪ͨ����ը����ʱ(��ըԤ��ʱ��)
	*
	@param time: -1:ȡ��Ԥ��   0����ըЧ��   >0����ը����ʱ
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UMonsterExtJZZYXYInterface")
		void onNotifyExplodeCountdown(int time);
	/**

	*������֪ͨϨ�𲿷��Ѿ������ĵ�
	*
	@param num:Ϩ�������,Ϊ0��ǰ�ֵĵ�ȫ��Ϩ��
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UMonsterExtJZZYXYInterface")
		void onExtinguishLight(int32 num);
	
	virtual void InitBlueCB() override;

	TArray<int32> EffectUIDs;///��Ч������
	TArray<FName> SaveSocketNmaes;
	TArray<FName> SocketNames;//��ǰ��Ҫ��̤���ܸ���
private:
	bool IsStepFloor = false;



	FTimerHandle CheckStepFloorventHandle;///<����ذ����ɻ���Ķ�ʱ��
	bool mIsStartOccupy = false;
	int8 mOccupyStatus = 0;		//0:δ��ռ��  1�����ռ��  2��bossռ��
};
