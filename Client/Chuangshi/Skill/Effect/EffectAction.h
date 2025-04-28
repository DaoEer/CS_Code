#pragma once
#include "EffectSkillBase.h"
#include "EffectAction.generated.h"

/*
* �ļ����ƣ�EffectAction.h
* ����˵�����ܻ�����Ч�����ܻ���������Ч����Ч��
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UEffectAction : public UEffectSkillBase
{
	GENERATED_BODY()
public:
	UEffectAction();
	~UEffectAction();

public:
	/*��ȡ��������*/
	virtual void init(FHIT_EFFECT dictDat, USkill* skill);
	/*����Ч��*/
	virtual void onReceive(USkill* skill, CS3Entity* caster, CS3Entity* receiver);

private:
	TArray<FString> _actionID;
	TArray<FString> _actionBeginTime;
	FString _effectID;
	FString _soundID;
	bool _isLocal = false;
};

