#pragma once

#include "KBEngine.h"
#include "Entity/Trap/Trap.h"

/*
* �ļ����ƣ�TrapSymbolJade.h
* ����˵����
* �ļ����ߣ�chendongyong
* Ŀǰά����chendongyong
* ����ʱ�䣺2020-05-19
*/

/**
�������
*/
class TrapSymbolJade : public Trap
{
	KBE_DECLARE_ENTITY_MAP();

	typedef Trap Supper;

public:
	TrapSymbolJade();
	~TrapSymbolJade();
public:
	virtual UClass* GetEntityModelClassAsset() override;

};
