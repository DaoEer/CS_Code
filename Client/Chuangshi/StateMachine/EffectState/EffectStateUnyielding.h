#pragma once
#include "EffectStateBase.h"

/*
* �ļ����ƣ�EffectStateUnyielding.h
* ����˵��������Ч��
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-08-06
*/

class EffectStateUnyielding : public EffectStateBase
{
public:
	EffectStateUnyielding();
	virtual ~EffectStateUnyielding();

	virtual void Add(AActor* _Actor)override;///< �ս���ʱ����
	virtual void Del(AActor* _Actor)override;///< �뿪ʱ����
};

