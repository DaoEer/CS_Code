#pragma once

#include "Util/CS3Debug.h"
#include "CS3Base/CS3EntityInterface.h"
#include "GameData/Skill/SkillUIData.h"
#include "RoleShenTongInterface.generated.h"

/*
* �ļ����ƣ�RoleShenTongInterface.h
* ����˵������ͨ����
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-3-21
*/
/**
 * �����ͨ���ܽӿ���
 */

UCLASS(BlueprintType)
class CHUANGSHI_API URoleShenTongInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleShenTongInterface();
	~URoleShenTongInterface();
	static FString GetName() { return TEXT("RoleShenTongInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleShenTongInterface.BP_RoleShenTongInterface_C'"); } //��ȡ��ͼ����·��

	virtual void InitBlueCB() override;

	/**
	*���뾫����ͨ����
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_RquestComminution(const FString & Suid, const FString & ItemList);
	/**
	*Define method
	*BlueprintNativeEvent �򿪾��н���
	*
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleShenTongInterface")
		void CLIENT_rquestComminution(const int32& npcID);

	/**
	*Define method
	*BlueprintNativeEvent ������ͨ��Ʒ�Ķ�̬����
	*@Param Suid			��ͨ��ƷUID
	*@Param SkillID			��ͨ��Ʒ����ID
	*@Param Level			��ͨ��Ʒʹ�õȼ�
	*@Param PreExp			��ͨ��Ʒ��ǰ���о���
	*@Param ReduceUseLevel	��ͨ��Ʒ����ʹ�õȼ�
	*@Param isComminution	��ͨ��Ʒ�Ƿ���Ծ���
	*@return ��
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "RoleShenTongInterface")
		void CLIENT_UpdateShenTongDynamic(const FString& Suid, const int32& SkillID, const int32& Level, const int32& PreExp, const int32& ReduceUseLevel, const uint8& isComminution);
	UFUNCTION(BlueprintImplementableEvent, Category = "RoleShenTongInterface")
		void OnUpdateShenTongDynamic(const FString& Suid);

	/**
	*Define method
	*@Param SkillID			��ͨ����ID
	*@Param Times			����ͨ���ܿ�ʹ�ô���
	*@Param isAdd			�Ƿ�Ϊ������ͨ����
	*
	*/
	void UpdateShenTongSKill(const int32& SkillID, const int32& Times, const uint8 isAdd);

	/**
	*Define method  ���������ͨ��ͨ����
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		TMap<int32, int32> GetShenTongSKills();

	/**
	*BlueprintCallable  ���������ͨ���ܣ�Ĭ�ϣ�������˳��
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleShenTongInterface")
		TArray<int32> GetShenTongSKillsSortByIndex();
	/**
	*BlueprintCallable  ���������ͨ���ܣ����ȼ�����
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleShenTongInterface")
		TArray<int32> GetShenTongSKillsSortByLevel();
	/**
	*BlueprintCallable  ���������ͨ���ܣ���ʣ���������
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleShenTongInterface")
		TArray<int32> GetShenTongSKillsSortByRemainTimes();
	/**
	*BlueprintCallable  ���������ͨ���ܴ���
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleShenTongInterface")
	int32 GetShenTongSKillTimes(const int32& SkillID);

	/**
	*BlueprintCallable �����ͨ������������
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleShenTongInterface")
		FSKILL_SHEN_TONG_TREE_CONFIG GetShenTongSKillCfgBySkillID(int32 SkillID);

	/**
	*BlueprintCallable  ��û�����ͨ������������
	*/
	UFUNCTION(BlueprintCallable, Category = "RoleShenTongInterface")
		FSKILL_SHEN_TONG_TREE_CONFIG GetPetShenTongSKillCfgBySkillID(int32 SkillID);

	/**
	*����ѧϰ������ͨ����
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_LearnPetShenTongSkill(FString PetUid, FString ItemUid);


	/**
	*���뾫����ͨ����
	*/
	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_DelPetShenTongSkill(FString PetUid, int32 SkillID);

private:
	/**
	*	���������ͨ����
	*/
	TArray<int32> GetShenTongSKillIDs();

private:
	UPROPERTY()
	TMap<int32, int32> ShenTongSkills;	//����ID�����ܴ���
};
