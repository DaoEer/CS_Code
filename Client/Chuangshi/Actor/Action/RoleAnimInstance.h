#pragma once
#include "BaseAnimInstance.h"
#include "RoleAnimInstance.generated.h"

/*
* �ļ����ƣ�RoleAnimInstance.h
* ����˵����
* �ļ����ߣ�ranyuan
* Ŀǰά����ranyuan
* ����ʱ�䣺2017-02-23
*/
UCLASS(Blueprintable, hideCategories = RoleAnimInstance, BlueprintType, meta = (BlueprintThreadSafe), Within = SkeletalMeshComponent)
class CHUANGSHI_API URoleAnimInstance : public UBaseAnimInstance
{
	GENERATED_BODY()
public:
	URoleAnimInstance();
	~URoleAnimInstance();
	void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void PlayShouDaoAction(const FActionOverDelegate& InActionOverDelegate = FActionOverDelegate())override;
	virtual void PlayBaDaoAction(const FActionOverDelegate& InActionOverDelegate = FActionOverDelegate())override;
	virtual void PlayClimbLadderAction()override;

protected:
	virtual bool IsInWater()override;
	virtual void UpdateMoveDirection()override;
	virtual FName GetMontageSectionId(FACTION_DATA& InActionData)override;///��ȡ�����̫��Ƭ��ID

private:
	void UpdateAimOffsetDirction();

public:

protected:
	UPROPERTY(BlueprintReadOnly, Category = "RoleAnimInstance")
		float CurAimOffsetYaw;///��׼ƫ��ƽ��yawֵ

	UPROPERTY(BlueprintReadOnly, Category = "RoleAnimInstance")
		float CurAimOffsetPitch;///��׼ƫ������Pitchֵ

private:
	bool IsInJumpAir;//�Ƿ���Ծ������
	bool IsOnLandingFromJumpAir;//�Ƿ����Ծ������½
};

