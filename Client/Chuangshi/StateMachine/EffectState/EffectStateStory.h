#pragma once
#include "EffectStateBase.h"

class EffectStateStory :public EffectStateBase
{
public:
	EffectStateStory();
	virtual ~EffectStateStory();
	virtual void Add(AActor* _Actor)override;///< �ս���ʱ����
	virtual void Del(AActor* _Actor)override;///< �뿪ʱ����
};

