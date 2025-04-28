#pragma once

#include "UObjectArray.h"

/*
* �ļ����ƣ�CS3Listener.h
* ����˵������Ҫ���þ����������´���UObject��ɾ��UObjectʱ��һЩ���飬Ŀǰ�������һ����־��
* �ļ����ߣ�lizhenghui
* Ŀǰά����wuxiaoou
* ����ʱ�䣺2017-10-24
*/

class CS3CreateListener : public FUObjectArray::FUObjectCreateListener
{
	virtual void NotifyUObjectCreated(const class UObjectBase *Object, int32 Index) override;
};

class CS3DeleteListener : public FUObjectArray::FUObjectDeleteListener
{
	virtual void NotifyUObjectDeleted(const class UObjectBase *Object, int32 Index) override;
};