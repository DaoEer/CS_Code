#pragma once
#include "GameData/CS3Object.h"
#include "UIFixerManager.generated.h"

/*
* �ļ����ƣ�UIFixerManager.h
* ����˵��������λ�ù�����
* �ļ����ߣ�zhangdan
* Ŀǰά����zhangdan
* ����ʱ�䣺2017-06-14
*/

class UBaseWindow;

UCLASS(Blueprintable, BlueprintType)
class CHUANGSHI_API UUIFixerManager : public UCS3Object
{
	GENERATED_BODY()
		UUIFixerManager();
	~UUIFixerManager();

public:

	static UUIFixerManager* GetInstance();
	/**
	*�����ô�������ʱ����ʼ�������λ��
	*
	*@param UBaseWindow* ���洰��
	*
	*@return ��
	*/
	void OnWindowInit(UBaseWindow* window);

	/**
	*�����ʱ���ý���λ�ã���ʼλ�ã�
	*
	*@param window ��ʾ�Ľ���
	*
	*@return ��
	*/
	void OnRecovery(UBaseWindow* window);
	
	/**
	*���ô���DockStyle
	*
	*@param window ���õĽ���
	*
	*@return ��
	*/
	void UpdateDockStyle(UBaseWindow* window);

	/**
	*����ɫ��������ʱ���ý���λ��
	*
	*@param UBaseWindow* ���洰��
	*
	*@return ��
	*/
	void OnRoleEnterWorld();

	/**
	*���ֱ��ʸı�ʱ������
	*
	*@param preReso �ɷֱ���
	*
	*@return ��
	*/
	void OnResolutionChanged(FVector2D preReso, float PreScale, FVector2D NewReso);

private:
	/**
	*��ʼ�������λ��
	*
	*@param UBaseWindow* ���洰��
	*
	*@return ��
	*/
	void FirstInitFix(UBaseWindow* window);
	/**
	*���ֱ��ʸı�ʱ�������������� ui ��λ��
	*
	*@param preReso �ɷֱ���
	*@param UBaseWindow* ���洰��
	*
	*@return ��
	*/
	void AdaptDock(FVector2D preReso, float PreScale, FVector2D newReso, UBaseWindow* window);
/*
private:
	static UUIFixerManager* Instance;*/
};
