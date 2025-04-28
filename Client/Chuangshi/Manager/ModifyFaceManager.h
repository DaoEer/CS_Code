// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData/CS3Object.h"
#include "GameData/ModifyFaceData.h"
#include "CfgManager.h"
#include "Actor/PinchFace/ModifyFaceCharacter.h"
#include "ModifyFaceManager.generated.h"

/**
 * 
 */
UCLASS()
class CHUANGSHI_API UModifyFaceManager : public UCS3Object
{

	GENERATED_BODY()
	
public:

	UModifyFaceManager();

	static UModifyFaceManager* GetInstance();

	// ���ù�������
	UFUNCTION(BlueprintCallable, Category = "ModifyFace|Function")
		void SetBoneRef(AGameCharacter* Actor);

	// �޸Ĺ����� Transform 
	UFUNCTION(BlueprintCallable, Category = "ModifyFace|Function")
		void SetBoneTrans(AGameCharacter* GameActor, FName BoneName, bool bIsSymBone, FTransform BoneTrans, bool IsMouse = true);

	UFUNCTION(BlueprintCallable, Category = "ModifyFace|Function")
		void SetTouchBone(int32 Index, int32 ModifyType = 0/*EModifyType Type = EModifyType::Part_Face*/);

	// ���ƹ����Ŀɵ��ڷ�Χ
	void LimitBoneTrans(FMODIFY_FACE_DATA* Bones, int32 ModifyType);

	// ��ȡ������� Transform
	UFUNCTION(BlueprintPure, Category = "ModifyFace|Fucntion")
	FTransform SymBoneTrans(FTransform BoneTrans);

	//��ȡ��ǰѡ�и���������
	UFUNCTION(BlueprintPure, Category = "ModifyFace|Fucntion")
		FName GetCurrentBoneName() const;

	UFUNCTION(BlueprintCallable, Category = "ModifyFace|Function")
		void SetCurrentBone();

	UFUNCTION(BlueprintCallable, Category = "ModifyFace|Function")
		void SetModifyData();

	UFUNCTION(BlueprintPure, Category = "ModifyFace|Function")
		TArray<FMODIFY_FACE_DATA>& GetBoneReference(int32 ModifyType = 0/*EModifyType Type = EModifyType::Part_Face*/);

	///��ȡ��ǰ����������
	UFUNCTION(BlueprintPure, Category = "ModifyFace|Fucntion")
		FName GetTouchBoneName() const;
	
	//������������
	UFUNCTION(BlueprintCallable, Category = "ModifyFace|ModifyFaceActor")
		FString SaveFileData(FString name);
	//������������
	UFUNCTION(BlueprintCallable, Category = "ModifyFace|ModifyFaceActor")
		FString LoadFileData();
	//��ǰ״̬
	UFUNCTION(BlueprintPure, Category = "ModifyFace|Function")
		bool GetFinishState();
	//�����沿����
	UFUNCTION(BlueprintCallable, Category = "ModifyFace|Function")
		void ResetFileData(AGameCharacter* GameActor);

	//��ȡ���������ļ���
	UFUNCTION(BlueprintCallable, Category = "ModifyFace|Function")
		TArray<FString> GetFaceFileName();

	//��ȡ���������ļ���
	UFUNCTION(BlueprintCallable, Category = "ModifyFace|Function")
		AModifyFaceCharacter* GetModifyFaceActor();

	//����ģ�͵���������
	UFUNCTION(BlueprintCallable, Category = "ModifyFace|Function")
		void SetModelFaceStyle(AGameCharacter* Target , FFACE_STYLE_DATA faceStyleData);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ModifyFace|ModifyFaceCharacter")
		UConfigTable* BoneDataTable;//�沿�������ݱ�

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ModifyFace|ModifyFaceCharacter")
		UConfigTable* BoneLimitTable;//�沿������Ϣ��

	void SetActorFaceData(AGameCharacter* Target, TArray<FMODIFY_FACE_DATA> ModifyFaceDatas, FFACE_STYLE_DATA FaceStyleDatas);

	bool SerialzeData(FString DataPath);

	bool DeserialzeData(FString DataPath);

private:
	TArray<FMODIFY_FACE_DATA> FaceBoneRef;
	TArray<FMODIFY_FACE_DATA> BodyBoneRef;//����������δ����
	TArray<FBONE_FACE_LIMIT> BoneLimitRef;

	bool bIsGetBone = false;
	FMODIFY_FACE_DATA* TouchBone;
	FMODIFY_FACE_DATA* CurrentBone;
	FMODIFY_FACE_DATA* SymBone;
	
};
