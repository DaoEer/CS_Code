// Fill out your copyright notice in the Description page of Project Settings.


#include "DecalManager.h"
#include "GameDevelop/CS3GameInstance.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleEmitter.h"
#include"Chuangshi.h"
CONTROL_COMPILE_OPTIMIZE_START

UDecalManager* UDecalManager::Instance = nullptr;

UDecalManager::UDecalManager()
{
}

UDecalManager::~UDecalManager()
{
	if (CurDecalData)
	{
		delete CurDecalData;
		CurDecalData = nullptr;
	}
}

UDecalManager* UDecalManager::GetInstance()
{
	//��Ϸ������
	if (UUECS3GameInstance::Instance)
	{
		//�����Ϸʵ����ֵ���ô�ֵ�������������Instance���ܱ�����
		if (UUECS3GameInstance::Instance->DecalManager)
		{
			return UUECS3GameInstance::Instance->DecalManager;
		}

		//��������Ч�����Ǳ༭�������ľ�������´���
		if (!IsValid(Instance))
		{
			CS3_Warning(TEXT("-->Null Pointer error: UDecalManager::GetInstance: Instance !"));
			Instance = nullptr;
		}
		else if(!Instance->bOnGame)
		{
			Instance->RemoveFromRoot();
			Instance = nullptr;
		}
		//����������������Ϊ��Ϸ״̬�´�����
		if (!Instance)
		{
			Instance = NewObject<UDecalManager>();
			Instance->bOnGame = true;
		}
	}
	//��Ϸδ����
	else
	{
		if (!IsValid(Instance))
		{
			Instance = NewObject<UDecalManager>();

	//��Ϸδ����ʱ���������δ��������ᵼ��ָ�뱻�������գ����Ǿ�̬������Ȼ�����ڴ��У������ڴ治������
#if WITH_EDITOR
			Instance->AddToRoot();
#endif 

		}
	}

	return Instance;
	//return NewObject<UDecalManager>();
}

void UDecalManager::ClearInstance()
{
	Instance = nullptr;
}

void UDecalManager::BeginDestroy()
{
	for (int i = 0; i < Decals.Num(); i++)
	{
		Decals[i]->Destroy();
	}
	Decals.Empty();
	Super::BeginDestroy();
}

TArray<ADecalEffect*> UDecalManager::CreateDecalEffect(UParticleSystem* ParticleSys, USceneComponent* Parent)
{
	LastCreate.Empty();

	if (!ParticleSys)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UDecalManager::CreateDecalEffect : ParticleSys!"));
		return LastCreate;
	}

	TArray<class UParticleEmitter*> emitters = ParticleSys->Emitters;
	for (int i = 0; i < emitters.Num(); i++)
	{
		UParticleEmitter* emit = emitters[i];
		if (emit->EmitterName.ToString().Contains("Decal"))
		{
			FEmitterData emitterData(emit);
			
			//�ڱ༭��ģʽ��Ҫ�ڵ�һ��Tick��ִ����������󶨵����Ӹ����
			if (UUECS3GameInstance::Instance && (!Parent || (Parent->GetWorld() == UUECS3GameInstance::Instance->GetWorld())))
			{
				emitterData.bOnMesh = false;
			}
			else
			{
				emitterData.bOnMesh = true;
			}

			//emitterData.InitialHeight = Height;
			ADecalEffect* decal = _BuildDecalEffect(&emitterData, Parent);
			if (decal)
				LastCreate.Add(decal);
		}
	}
	return LastCreate;
}

void UDecalManager::DestroyDecalEffect(ADecalEffect* DecalEffect)
{
	int idx = 0;
	if (Decals.Find(DecalEffect, idx))
	{
		Decals[idx]->Destroy();
		Decals.RemoveAt(idx);
	}
}

ADecalEffect* UDecalManager::_BuildDecalEffect(const FEmitterData* DecalData, USceneComponent* Parent)
{
	if (!DecalData->DecalMaterial)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UDecalManager::_BuildDecalEffect : DecalData->DecalMaterial!"));
		return NULL;
	}

	UWorld* World = Parent ? Parent->GetWorld() : GetWorld();
	if (!World)
	{
		CS3_Warning(TEXT("-->Null Pointer error:UDecalManager::_BuildDecalEffect : World!"));
		return NULL;
	}

	//��������ǰ��������һ��
	if (CurDecalData)
	{
		delete CurDecalData;
		CurDecalData = nullptr;
	}

	CurDecalData = new FEmitterData(DecalData);//UDecalManager::_BuildDecalEffect��UDecalManager::~UDecalManager���ͷ�

	ADecalEffect* Decal = World->SpawnActor<ADecalEffect>(ADecalEffect::StaticClass());

	//Decal->Init(DecalData, LocationOffset, DecalData->Delay, Attached, Parent, AttachPointName);
	//����������Ч��ֱ�ӷ��أ������ڲ���ȥ�Լ�����󶨺ͳ�ʼ������
	Decals.Add(Decal);
	return Decal;
}

CONTROL_COMPILE_OPTIMIZE_END

