#pragma once
#include "EffectStateBase.h"

/*
* �ļ����ƣ�EffectStateFreeze.h
* ����˵��������Ч��
* �ļ����ߣ�xuyongqi
* Ŀǰά����xuyongqi
* ����ʱ�䣺2018-08-06
*/

class EffectStateFreeze : public EffectStateBase
{
public:
	EffectStateFreeze();
	virtual ~EffectStateFreeze();

	virtual void Add(AActor* _Actor)override;///< �ս���ʱ����
	virtual void Del(AActor* _Actor)override;///< �뿪ʱ����
};

