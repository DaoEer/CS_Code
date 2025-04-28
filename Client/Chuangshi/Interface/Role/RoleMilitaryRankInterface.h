#include "CS3Base/CS3EntityInterface.h"
#include "RoleMilitaryRankInterface.generated.h"
/*
* �ļ����ƣ�RoleMilitaryRankInterface.h
* ����˵����
* �ļ����ߣ�lintongbin
* Ŀǰά����lintongbin
* ����ʱ�䣺2020-02-29
*/
UCLASS(BlueprintType)
class CHUANGSHI_API URoleMilitaryRankInterface : public UCS3EntityInterface
{
	GENERATED_BODY()
		typedef UCS3EntityInterface Supper;
	CS3_DECLARE_INTERFACE_MAP()
public:
	URoleMilitaryRankInterface();
	~URoleMilitaryRankInterface();
	
	static FString GetName() { return TEXT("RoleMilitaryRankInterface"); } //��ȡ�ӿ�����
	static FString GetClassPath() { return TEXT("BlueprintGeneratedClass'/Game/BluePrints/Entity/Interface/BP_RoleMilitaryRankInterface.BP_RoleMilitaryRankInterface_C'"); } //��ȡ��ͼ����·��

	virtual void InitBlueCB() override;
	/**
	*��Ҿ���ֵ
	*
	*@return int32, ����ֵ
	*/
	UFUNCTION(BlueprintCallable, Category = "cs3|RoleMilitaryRankInterface")
		int32 GetExploit();
	/**
	*��Ҿ��εȼ�
	*
	*@return int32, ����ֵ
	*/
	UFUNCTION(BlueprintCallable, Category = "cs3|RoleMilitaryRankInterface")
		int32 GetMilitaryRank();

	void onUpdataExploit(const int32& exploit, const int32& militaryRank);

	UFUNCTION(BlueprintNativeEvent, Category = "cs3|RoleMilitaryRankInterface")
		void onBPUpdataExploit(const int32& exploit, const int32& militaryRank);

	UFUNCTION(BlueprintCallable, Category = "Game|RPC")
		void RPC_updataExploit();
};