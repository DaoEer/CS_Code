#pragma once
#include "GameData/CS3Object.h"
#include "QTEBaseOperation.generated.h"

/*
* �ļ����ƣ�QTEBaseOperation.h
* ����˵����
* �ļ����ߣ�huting
* Ŀǰά����huting
* ����ʱ�䣺2018-07-17
*/



UCLASS(Abstract)
class CHUANGSHI_API UQTEBaseOperation : public UCS3Object
{
	GENERATED_BODY()

public:
	void Init();///<��ʼ��
	virtual float ExecuteOperation();///<ִ�в���,�Ƿ���ɲ���

	UFUNCTION(BlueprintImplementableEvent)
		void BP_ExecuteOperation();///<��ͼִ�в���
protected:
	/// �Ƿ���ִ��
	UFUNCTION(BlueprintCallable)
		virtual bool IsCanExecuteOperation();

	/// �Ƿ���ִ����ͼ����
	UFUNCTION(BlueprintNativeEvent)
		bool BP_IsCanExecuteOperation();

public:
	float Value = 0.0f;
};



UCLASS()
class CHUANGSHI_API UMouseQTEOperation : public UQTEBaseOperation
{
	GENERATED_BODY()

public:	
	virtual float ExecuteOperation();

private: 	
	float CurMousePostion = 0.0f;
	float OldMousePostion = 0.0f;
	float L_Postion = 0.0f;
	float R_Postion = 0.0f;
};
