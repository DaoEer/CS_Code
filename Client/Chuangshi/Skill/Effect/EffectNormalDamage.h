#pragma once
#include "EffectSkillBase.h"
#include "EffectNormalDamage.generated.h"

/*
* �ļ����ƣ�EffectNormalDamage.h
* ����˵������׼�˺�Ч��
* �ļ����ߣ�xuyongqi
* Ŀǰά����all
* ����ʱ�䣺2019-12-9
*/

UCLASS(BlueprintType)
class CHUANGSHI_API UEffectNormalDamage : public UEffectSkillBase
{
	GENERATED_BODY()
public:
	UEffectNormalDamage();
	~UEffectNormalDamage();

public:
	/*��ȡ��������*/
	virtual void init(FHIT_EFFECT dictDat, USkill* skill);
	/*Ч����Ӽ��*/
	virtual bool canEffect(USkill* skill, CS3Entity* caster, CS3Entity* receiver);
	/*����Ч��*/
	virtual void onReceive(USkill* skill, CS3Entity* caster, CS3Entity* receiver);


private:
	int32 CustomAttrC(FString propertyStr, int32 propertyValue);

	int32 CustomAttrR(FString propertyStr, int32 propertyValue);

private:
	int32 _damageType = 1;  ///<�˺�����
	float _skillRadio = 0.0;  ///<����Ч��
	int32 _skillValue = 0;    ///<���̶ܹ�ֵ
	float _skillGangQiRadio = 0.0;  ///<���������������
	int32 _skillGangQiValue = 0;    ///<��������˺��̶�ֵ
	int32 _deadEffect = 0;      ///<����ʱ���Ƿ񲥷�����Ч������ʬ��
	bool _isSkipEvent = false;
	TMap<FString, int32> _customAttrC;  ///<ʩ�������������б�
	TMap<FString, int32> _customAttrR;  ///<���������������б�
};