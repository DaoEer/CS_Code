// Fill out your copyright notice in the Description page of Project Settings.


#include "InWorldStreamLevel.h"
#include "Util/GolbalBPFunctionLibrary.h"
#include "Manager/LevelManager.h"
#include "Engine/LevelStreaming.h"
#include "Manager/CfgManager.h"
#include "Interface/Role/RoleSpaceInterface.h"
#include "Engine/LevelStreamingVolume.h"
#include "Manager/GameStatus.h"
#include "Util/CS3Debug.h"
#include "Util/ConvertUtil.h"
#include "Kismet/GameplayStatics.h"


CONTROL_COMPILE_OPTIMIZE_START


void AInWorldStreamLevel::BeginPlay()
{
	Super::BeginPlay();
	CurSubLevelName = TEXT("");///<��ǰ���ӹؿ�
	OldSubLevelName = TEXT("");///<ǰһ���ӹؿ�
	NextSubLevelName = TEXT("");///<��һ���ӹؿ�
	NewSubLevelName = TEXT("");///<�µ��ӹؿ�
	IsLoadNextSubLevelFinished = false;///<��һ���ӹؿ��Ƿ�������
	IsLoadSubLevelFinished = false; ///<��ǰ�ӹؿ��Ƿ�������
	IsLoadNextSubLevelFinished = false; ///<�¸��ӹؿ��Ƿ�������
	IsLoadStreamingLevel = false; ///<�Ƿ�������������ؿ�
	if (IsValid(UUECS3GameInstance::Instance) && IsValid(UUECS3GameInstance::Instance->GameStatus))
	{
		UUECS3GameInstance::Instance->GameStatus->InWorldLoadingOver.AddDynamic(this, &AInWorldStreamLevel::PostChangeInWorldOver);
	}
	LoadDefaultSubLevel();
}

void AInWorldStreamLevel::OnLoadLevelFinished()
{
	IsLoadLevelFinished = true;
	if (IsBlockLevelFinished && IsLoadSubLevelFinished)
	{
		CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::OnLoadLevelFinished ------"));
		UGolbalBPFunctionLibrary::LevelManager()->OnEndTeleportNormalLevel();
	}
}

void AInWorldStreamLevel::ChangeToNextSubLevel(FName LevelName)
{	
	if (!LevelName.Compare(TEXT(""))) return;
	///<�л��Ĺؿ�����һ���ӹؿ���һ��
	if ((LevelName.ToString()).Compare(NextSubLevelName)) 
	{
		NextSubLevelName = FNAME_TO_FSTRING(LevelName);
		NewSubLevelName = NextSubLevelName;
		CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::ChangeToNextSubLevel LevelName not Compare NextSubLevelName NextSubLevelName=%s"),*NextSubLevelName);
		LoadNextSubLevel(true);
	}
	else
	{
		///<��һ���ӹؿ��Ѽ������
		if (IsLoadNextSubLevelFinished)
		{
			NewSubLevelName = TEXT("");
			OldSubLevelName = CurSubLevelName;
			CurSubLevelName = NextSubLevelName;
			///< ��ȡ��һ���ӹؿ���
			SetNextSubLevelName();
			///<��ʾ��ǰ�ӹؿ�
			UpdateSubLevelVisiblity(FSTRING_TO_FNAME(CurSubLevelName), FSTRING_TO_FNAME(OldSubLevelName));
			IsLoadNextSubLevelFinished = false;
			IsLoadSubLevelFinished = true;
			CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::ChangeToNextSubLevel IsLoadNextSubLevelFinished=TRUE CurSubLevelName=%s NextSubLevelName=%s"), *CurSubLevelName,*NextSubLevelName);
		}
		else
		{
			CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::ChangeToNextSubLevel IsLoadNextSubLevelFinished=FALSE CurSubLevelName=%s NextSubLevelName=%s"), *CurSubLevelName, *NextSubLevelName);
			NewSubLevelName = NextSubLevelName;
		}
	}
}

void AInWorldStreamLevel::PostChangeInWorldOver()
{
	///<�ɵĹؿ�����һ���ؿ�һ���Ͳ��ü�����һ���ؿ���ж����һ���ؿ�
	if (!OldSubLevelName.Compare(NextSubLevelName) && NextSubLevelName.Compare(TEXT("")))
	{
		CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::PostChangeInWorldOver   OldSubLevelName Compare NextSubLevelName CurSubLevelName=%s NextSubLevelName=%s"), *CurSubLevelName, *NextSubLevelName);

		///<֪ͨ�Ѽ������
		LoadNextSubLevelFinished();
	}
	else
	{
		if (!NextSubLevelName.Compare(TEXT("")))
		{
			SetNextSubLevelName();
		}
		CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::PostChangeInWorldOver CurSubLevelName=%s NextSubLevelName=%s"), *CurSubLevelName, *NextSubLevelName);
		///<ж��֮ǰ���ӹؿ�
		//UnLoadSubLevelByLevelName(FSTRING_TO_FNAME(OldSubLevelName));
		///<������һ���ӹؿ�
		LoadNextSubLevel();		
	}
}

bool AInWorldStreamLevel::IsCompareLevelManagerSubStreamLevel(FName LevelName)
{
	if (!LevelName.IsNone()&&!UGolbalBPFunctionLibrary::LevelManager()->GetSubStreamLevelName().IsNone())
	{
		return !(LevelName.Compare(UGolbalBPFunctionLibrary::LevelManager()->GetCurrLevelName()));
	}
	return false;
}

void AInWorldStreamLevel::LoadLevelStreamingByLevelName(FName LevelName)
{
	UWorld* InWorld = GetWorld();
	if (InWorld && !LevelName.IsNone())
	{
		IsLoadStreamingLevel = true;
		FString LevelNameString = LevelName.ToString();
		LevelNameString.RemoveFromEnd("01");
		for (ULevelStreaming* LevelStreaming : InWorld->GetStreamingLevels())
		{
			FString FileName = FPaths::GetCleanFilename(LevelStreaming->GetWorldAssetPackageName());
			FString LevelStreamingName;
			if (!InWorld->StreamingLevelsPrefix.IsEmpty())
			{
				FString Left;
				FileName.Split(InWorld->StreamingLevelsPrefix, &Left, &LevelStreamingName);
			}
			else
			{
				LevelStreamingName = FileName;
			}
			if (LevelStreamingName.Contains(LevelNameString))
			{
				LoadSubLevelByLevelName(FName(*LevelStreamingName), false, false, TEXT(""));
			}
		}
	}
}

void AInWorldStreamLevel::UpdateStreamingVolume()
{
	UWorld* InWorld = GetWorld();
	if (InWorld)
	{
		TEnumAsByte<enum EStreamingVolumeUsage> StreamingVolumeUsage = IsCompareLevelManagerSubStreamLevel(FSTRING_TO_FNAME(CurSubLevelName))? (EStreamingVolumeUsage::SVB_LoadingAndVisibility) : (EStreamingVolumeUsage::SVB_LoadingNotVisible);
		
		for (ULevelStreaming* LevelStreaming : InWorld->GetStreamingLevels())
		{
			//<������������Ŀɼ���
			for (ALevelStreamingVolume* StreamingVolume : LevelStreaming->EditorStreamingVolumes)
			{
				StreamingVolume->bDisabled = false;
				StreamingVolume->StreamingUsage = StreamingVolumeUsage;
				if (StreamingVolumeUsage == EStreamingVolumeUsage::SVB_LoadingAndVisibility) 
				{				
					TArray<FName> StreamingLevelFileNames = StreamingVolume->StreamingLevelNames;
					for (int32 i = 0; i < StreamingLevelFileNames.Num(); i++)
					{
						TArray<FString> SplitStrings = UGolbalBPFunctionLibrary::SplitString(FNAME_TO_FSTRING(StreamingLevelFileNames[i]), false, "/");
						if (SplitStrings.Num() > 0)
						{
							LoadSubLevelByLevelName(FName(*(SplitStrings.Last())), true, true, TEXT(""));
						}
					}
				}
			}
		}
	}
}

void AInWorldStreamLevel::SetNextSubLevelName()
{
	NextSubLevelName = TEXT("");
	URoleSpaceInterface * RoleSpaceInterface = Cast<URoleSpaceInterface>(UGolbalBPFunctionLibrary::GetInterfaceByName(TEXT("RoleSpaceInterface")));

	if (RoleSpaceInterface&&RoleSpaceInterface->IsHZMGLevel() && UGolbalBPFunctionLibrary::LevelManager())
	{
		auto newlevelHash = UGolbalBPFunctionLibrary::LevelManager()->GetLevelHashMapData(FSTRING_TO_FNAME((RoleSpaceInterface->GetVideoLoadLevelData()).NextLevel));

		CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::SetNextSubLevelName() GetVideoLoadLevelData.NextLevel=%s"), *(RoleSpaceInterface->GetVideoLoadLevelData()).NextLevel);

		if (newlevelHash && !newlevelHash->SubStreamLevelName.IsNone())
		{
			NextSubLevelName = FNAME_TO_FSTRING(newlevelHash->SubStreamLevelName);
		}
	}
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::SetNextSubLevelName() CurSubLevelName=%s NextSubLevelName=%s"), *CurSubLevelName, *NextSubLevelName);

}

void AInWorldStreamLevel::LoadSubLevelByLevelName(const FName LevelName, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FName ExecutionFunction)
{
	CS3_Display(CS3DebugType::CL_Level, TEXT("AInWorldStreamLevel::LoadSubLevelByLevelName LevelName=%s,bMakeVisibleAfterLoad=%d,bShouldBlockOnLoad=%d,ExecutionFunction=%s"), *FNAME_TO_FSTRING(LevelName), bMakeVisibleAfterLoad, bShouldBlockOnLoad, *FNAME_TO_FSTRING(ExecutionFunction));

	if (!LevelName.IsNone())
	{
		FLatentActionInfo LatentInfo;
		LatentInfo.CallbackTarget = this;
		LatentInfo.ExecutionFunction = ExecutionFunction;
		LatentInfo.UUID = UGolbalBPFunctionLibrary::LevelManager()->GetUUID();
		LatentInfo.Linkage = 0;
		UGameplayStatics::LoadStreamLevel(this, LevelName, bMakeVisibleAfterLoad, bShouldBlockOnLoad, LatentInfo);
	}
}

void AInWorldStreamLevel::LoadDefaultSubLevel()
{
	IsLoadSubLevelFinished = true;
	auto newlevelHash = UGolbalBPFunctionLibrary::LevelManager()->GetLevelHashMapData(UGolbalBPFunctionLibrary::LevelManager()->spaceScriptID);

	if (newlevelHash)
	{
		///<��ȡ��ǰӦ���л����ӹؿ�
		if (!UGolbalBPFunctionLibrary::LevelManager()->GetSubStreamLevelName().IsNone())
		{
			CurSubLevelName = UGolbalBPFunctionLibrary::LevelManager()->GetSubStreamLevelName().ToString();
		}
	}

	if (CurSubLevelName.Compare(TEXT("")))
	{
		IsLoadSubLevelFinished = false;
		///<������������Ĳ���������ֱ�ӽ���ĳ�����������������ĵ���
		UpdateStreamingVolume();
		LoadSubLevelByLevelName(FName(*CurSubLevelName), true, true, TEXT("LoadDefaultSubLevelFinished"));
	}
	else
	{
		////<���ñ���û�����ݻ�ȡ��һ���ӹؿ�
		UWorld* InWorld = GetWorld();
		if (InWorld && InWorld->GetStreamingLevels().Num() > 0)
		{
			const ULevelStreaming* LevelStreaming = InWorld->GetStreamingLevels()[0];
			if (LevelStreaming)
			{
				FString FileName = FPaths::GetCleanFilename(LevelStreaming->GetWorldAssetPackageName());
				FString LevelName;
				if (!InWorld->StreamingLevelsPrefix.IsEmpty())
				{
					FString Left;
					FileName.Split(InWorld->StreamingLevelsPrefix, &Left, &LevelName);
				}
				else
				{
					LevelName = FileName;
				}
				CurSubLevelName = LevelName;
				IsLoadSubLevelFinished = false;
				///<������������Ĳ���������ֱ�ӽ���ĳ�����������������ĵ���
				UpdateStreamingVolume();
				LoadSubLevelByLevelName(FName(*CurSubLevelName), true, true, TEXT("LoadDefaultSubLevelFinished"));
			}
		}
	}
	 
	///< ��ȡ��һ���ӹؿ���
	SetNextSubLevelName();
}

void AInWorldStreamLevel::LoadDefaultSubLevelFinished()
{
	UpdateSubLevelVisiblity(FSTRING_TO_FNAME(CurSubLevelName),TEXT(""));

	///<��ʱ1.5s֪ͨ�ؿ��л���ɱ��⴩��
	UUECS3GameInstance::Instance->CustomTimerManager->SetTimer(DelayNotifyLoadFinishedHandle, this, &AInWorldStreamLevel::DelayNotifyLoadDefaultSubLevelFinished, 1.5f, false);
}

void AInWorldStreamLevel::DelayNotifyLoadDefaultSubLevelFinished()
{
	///<֪ͨ�������
	IsLoadSubLevelFinished = true;
	if (IsLoadLevelFinished)
	{
		OnLoadLevelFinished();
	}
}

void AInWorldStreamLevel::LoadNextSubLevel(bool bIsShow/* = false*/)
{
	if (NextSubLevelName.Compare(TEXT("")))
	{
		CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::LoadNextSubLevel() CurSubLevelName=%s NextSubLevelName=%s"), *CurSubLevelName, *NextSubLevelName);

		LoadSubLevelByLevelName(FName(*NextSubLevelName), bIsShow, false, TEXT("LoadNextSubLevelFinished"));
		if (IsCompareLevelManagerSubStreamLevel(FName(*NextSubLevelName)) && !IsLoadStreamingLevel)
		{
			LoadLevelStreamingByLevelName(FName(*NextSubLevelName));
		}
	}
}

void AInWorldStreamLevel::LoadNextSubLevelFinished()
{
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::LoadNextSubLevelFinished() CurSubLevelName=%s NextSubLevelName=%s"), *CurSubLevelName, *NextSubLevelName);

	IsLoadNextSubLevelFinished = true;
	LoadNextSubLevelFinishedDelegate.Broadcast(NextSubLevelName);

	///<֪ͨ�л���һ���ӹؿ�ʱ����һ���ӹؿ�û�м�����ɣ��ּ��������Ҫ�л��ؿ�
	if (!NewSubLevelName.Compare(NextSubLevelName))
	{
		ChangeToNextSubLevel(FSTRING_TO_FNAME(NewSubLevelName));
	}
}

void AInWorldStreamLevel::UpdateSubLevelVisiblity(FName VisibleLevelName, FName InvisibleLevelName)
{
	CS3_Display(CS3DebugType::CL_Level, TEXT("InWorldStreamLevel::UpdateSubLevelVisiblity VisibleLevelName=%s,InvisibleLevelName=%s"), *FNAME_TO_FSTRING(VisibleLevelName), *FNAME_TO_FSTRING(InvisibleLevelName));
	//��ʾ�ؿ�
	UWorld* InWorld = GetWorld();
	if (InWorld)
	{
		TEnumAsByte<enum EStreamingVolumeUsage> StreamingVolumeUsage = IsCompareLevelManagerSubStreamLevel(VisibleLevelName) ? (EStreamingVolumeUsage::SVB_LoadingAndVisibility) : (EStreamingVolumeUsage::SVB_Loading);

		FString InvisibleLevelNameString = InvisibleLevelName.ToString();
		InvisibleLevelNameString.RemoveFromEnd("01");
		FString VisibleLevelNameString = VisibleLevelName.ToString();
		VisibleLevelNameString.RemoveFromEnd("01");
		
		ALevelStreamingVolume* TempStreamingVolume = nullptr;
		TArray<AActor*> FindActors;
		UGameplayStatics::GetAllActorsOfClass(InWorld, ALevelStreamingVolume::StaticClass(), FindActors);
		if (FindActors.Num() > 0)
		{
			for (AActor* actor : FindActors)
			{  ///<����������������ͺ͵�ǰ��ʾ�������ؿ���ȡ���ϴ���ҽ�����ӵ��� TempStreamingVolume
				ALevelStreamingVolume* StreamingVolume = Cast<ALevelStreamingVolume>(actor);
				if (IsValid(StreamingVolume))
				{
					if (StreamingVolumeUsage == EStreamingVolumeUsage::SVB_LoadingAndVisibility&&LastEntitypostion != FVector::ZeroVector)
					{
						TempStreamingVolume = (TempStreamingVolume == nullptr) ? StreamingVolume : ((FVector::Distance(TempStreamingVolume->GetActorLocation(), LastEntitypostion) > FVector::Distance(StreamingVolume->GetActorLocation(), LastEntitypostion)) ? StreamingVolume : TempStreamingVolume);
					}
					if (StreamingVolume->StreamingUsage == EStreamingVolumeUsage::SVB_LoadingNotVisible&&StreamingVolumeUsage == EStreamingVolumeUsage::SVB_Loading)
					{
						continue;
					}
					StreamingVolume->StreamingUsage = StreamingVolumeUsage;
				}
			}
		}
		TArray<FString> StreamingLevelNames;
		if (IsValid(TempStreamingVolume))
		{
			TArray<FName> StreamingLevelFileNames = TempStreamingVolume->StreamingLevelNames;
			
			for (int32 i = 0; i < StreamingLevelFileNames.Num(); i++)
			{
				TArray<FString> SplitStrings = UGolbalBPFunctionLibrary::SplitString(FNAME_TO_FSTRING(StreamingLevelFileNames[i]), false, "/");
				if (SplitStrings.Num() > 0)
				{
					StreamingLevelNames.Add(SplitStrings.Last());
				}
			}			
		}
		ULevelStreaming* VisibleStreamingLevel = nullptr;
		ULevelStreaming* VisibleStreamingLevelByEntityPosition = nullptr;
		for (ULevelStreaming* LevelStreaming : InWorld->GetStreamingLevels())
		{
			if (!IsValid(LevelStreaming))
			{
				continue;
			}
			FString FileName = FPaths::GetCleanFilename(LevelStreaming->GetWorldAssetPackageName());
			FString LevelName;
			if (!InWorld->StreamingLevelsPrefix.IsEmpty())
			{
				FString Left;
				FileName.Split(InWorld->StreamingLevelsPrefix, &Left, &LevelName);
			}
			else
			{
				LevelName = FileName;
			}
			if (StreamingLevelNames.Num() > 0 && !(StreamingLevelNames[0].Compare(LevelName)))
			{
				CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::VisibleLevelNameByEntityPosition=%s "), *LevelName);
				VisibleStreamingLevelByEntityPosition = LevelStreaming;
			}			

			if (VisibleLevelName.Compare(TEXT("")) && !LevelName.Compare(VisibleLevelName.ToString()))
			{
				CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::VisibleLevelName=%s "), *LevelName);
				VisibleStreamingLevel = LevelStreaming;		
			}
			else if (InvisibleLevelName.Compare(TEXT("")) && FileName.Contains(InvisibleLevelNameString) && LevelStreaming->IsLevelVisible())
			{
				InvisibleStreamingLevels.Add(LevelStreaming);
			}			
		}	
		///<������ʾ�ϴ����λ�õ��ӹؿ�
		if(IsValid(VisibleStreamingLevelByEntityPosition) && 
			(!VisibleStreamingLevelByEntityPosition->IsLevelVisible())&&
			VisibleStreamingLevelByEntityPosition != VisibleStreamingLevel
			)
		{
			VisibleStreamingLevelByEntityPosition->SetShouldBeVisible(true);
		}

		float FinishedTime = 2.0f;
		if (IsValid(VisibleStreamingLevel) && (!VisibleStreamingLevel->IsLevelVisible()))
		{	///<��ǰ����������Ҫ�Ǳ����ӹؿ�û�м��غ�������ײû�е��½�ɫ��������
			VisibleStreamingLevel->SetShouldBeVisible(true);			
			//LoadSubLevelByLevelName(VisibleLevelName, true, false, TEXT("UpdateSubLevelVisiblityFinished"));//�÷������Ѽ�����ɵ������û�лص� ����һֱ�Ῠס������
			//UpdateSubLevelVisiblityFinished(4.2f);
			FinishedTime = 4.2f;
		}

		if (InvisibleStreamingLevels.Num() > 0)
		{	
			///<�ɵĹؿ���Ҫж��
			if (!(!OldSubLevelName.Compare(NextSubLevelName) && NextSubLevelName.Compare(TEXT("")))&&(InvisibleStreamingLevels.Num()==1))
			{
				//FinishedTime += 2.0f;
				UnLoadSubLevelByLevelName(InvisibleLevelName);
			}
			else
			{
				DelaySetInvisibleStreamingLevels();
				UpdateSubLevelVisiblityFinished(FinishedTime);
			}			
		}
		else 
		{
			UpdateSubLevelVisiblityFinished(FinishedTime);
		}
		

		KBEngine::Entity *entity = UUECS3GameInstance::pKBEApp->Player();
		if (entity)
		{
			LastEntitypostion = entity->Position();
		}
	}
}

void AInWorldStreamLevel::UpdateSubLevelVisiblityFinished(float FinishedTime/* = 2.0f*/)
{
	///<��ʱ2s֪ͨ�ؿ��л���ɱ��⴩��
	UUECS3GameInstance::Instance->CustomTimerManager->SetTimer(DelayNotifyLoadFinishedHandle, this, &AInWorldStreamLevel::OnLoadLevelFinished, FinishedTime, false);
}

void AInWorldStreamLevel::DelaySetInvisibleStreamingLevels()
{
	UWorld* World = UUECS3GameInstance::Instance->GetWorld();
	if (World)
	{
		TWeakObjectPtr<AInWorldStreamLevel> DelayThisPtr(this);
		World->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateLambda([DelayThisPtr]()
		{
			if (DelayThisPtr.IsValid())
			{
				AInWorldStreamLevel* InWorldStreamLevel = DelayThisPtr.Get();
				if (InWorldStreamLevel->InvisibleStreamingLevels.Num() > 0)
				{
					if (IsValid((InWorldStreamLevel->InvisibleStreamingLevels[0])))
					{
						(InWorldStreamLevel->InvisibleStreamingLevels[0])->SetShouldBeVisible(false);
					}
					InWorldStreamLevel->InvisibleStreamingLevels.RemoveAt(0);
					if (InWorldStreamLevel->InvisibleStreamingLevels.Num() > 0)
					{
						InWorldStreamLevel->DelaySetInvisibleStreamingLevels();
					}
				}
			}
		}));
	}
}

void AInWorldStreamLevel::UnLoadSubLevelByLevelName(FName LevelName)
{
	if (!LevelName.IsNone())
	{
		CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::UnLoadSubLevelByLevelName() LevelName=%s"), *FNAME_TO_FSTRING(LevelName));

		FLatentActionInfo LatentInfo;
		LatentInfo.CallbackTarget = this;
		LatentInfo.ExecutionFunction = FName(TEXT("UnLoadSubLevelFinished"));
		LatentInfo.UUID = UGolbalBPFunctionLibrary::LevelManager()->GetUUID();
		LatentInfo.Linkage = 0;
		UGameplayStatics::UnloadStreamLevel(this, LevelName, LatentInfo, false);
	}
}

void AInWorldStreamLevel::UnLoadSubLevelFinished()
{
	UpdateSubLevelVisiblityFinished(0.1f);
	CS3_Display(CS3DebugType::CL_Undefined, TEXT("AInWorldStreamLevel::UnLoadSubLevelFinished()"));
}

CONTROL_COMPILE_OPTIMIZE_END
