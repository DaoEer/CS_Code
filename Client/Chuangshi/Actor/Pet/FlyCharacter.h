#pragma once

#include "Actor/GameCharacter.h"
#include "FlyCharacter.generated.h"

/*
* �ļ����ƣ�AFlyCharacter.h
* ����˵����
* �ļ����ߣ�huting
* Ŀǰά����huting
* ����ʱ�䣺2018-07-11
*/

DECLARE_DELEGATE(FFlyCharacterOnCreateModelOverDelegate);//ģ�ͼ��ؽ���֪ͨ

/**
* ���л���
*/
UCLASS(BlueprintType)
class CHUANGSHI_API AFlyCharacter : public AGameCharacter
{
	GENERATED_BODY()
public:
	AFlyCharacter();
	virtual void BeginPlay()override;

	virtual void SetInitAction() override;///<��дSetInitAction

	virtual void OnCreateModelOver() override;
public:
	FFlyCharacterOnCreateModelOverDelegate FlyCharacterOnCreateModelOver;
protected:
	virtual void InitBaseComponent() override;
};
