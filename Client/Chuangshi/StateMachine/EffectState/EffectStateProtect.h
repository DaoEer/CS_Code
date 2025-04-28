﻿#pragma once

#include "EffectStateBase.h"

/*
* 文件名称：EffectStateProtect.h
* 功能说明：保护效果
* 文件作者：xuyongqi
* 目前维护：xuyongqi
* 创建时间：2017-07-25
*/

class EffectStateProtect : public EffectStateBase
{
public:
	EffectStateProtect();
	virtual ~EffectStateProtect();

	virtual void Add(AActor* _Actor)override;///< 刚进入时调用
	virtual void Del(AActor* _Actor)override;///< 离开时调用
};

