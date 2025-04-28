// Fill out your copyright notice in the Description page of Project Settings.


#include "DecalEffectNewEmitter.h"
#include "ParticleEmitterInstances.h"
#include "Particles/ParticleModule.h"
#include "Particles/ParticleEmitter.h"
#include "Particles/ParticleLODLevel.h"
#include "Particles/ParticleSystemComponent.h"
#include "ParticleModuleEx/ParticleModuleTypeDataDecal.h"
#include "ParticleModuleEx/ParticleDecalEmitterInstances.h"
#include "Components/DecalComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

void ADecalEffectNewEmitter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ADecalEffectNewEmitter::StartPlay()
{	
	this->GetParticleSystemComponent()->ActivateSystem(true);
	Super::StartPlay();

	UParticleSystemComponent* psComp = this->GetParticleSystemComponent();

	// ��ȡ�������������
	if (psComp->EmitterInstances.Num())
	{
		for (int32 i = 0; i < psComp->EmitterInstances.Num(); i++)
		{
			// �������ӷ�����
			FParticleEmitterInstance* Instance = psComp->EmitterInstances[i];
			if (!Instance || !Instance->SpriteTemplate)
				continue;
			
			// �ж�����������Ƿ�������������
			//UParticleLODLevel* LODLevel = Instance->SpriteTemplate->GetLODLevel(0);
			UParticleLODLevel* LODLevel = Instance->SpriteTemplate->GetCurrentLODLevel(Instance);
			if (!LODLevel)
				continue;

			UParticleModuleTypeDataDecal* DecalTypeData = Cast<UParticleModuleTypeDataDecal>(LODLevel->TypeDataModule);
			if (!IsValid(DecalTypeData))
				continue;

			// �ѷ�����תΪ�������ͷ���������������洢�������������
			FParticleDecalEmitterInstance* Inst = static_cast<FParticleDecalEmitterInstance*>(Instance);
			if (Inst == nullptr)
				continue;

			// ��ȡ��������
			for (int32 j = 0; j < Inst->Decals.Num(); j++)
			{
				UMaterialInterface* Mat = Inst->Decals[j]->GetDecalMaterial();

				UMaterialInstanceDynamic* dyMaterial = Cast<UMaterialInstanceDynamic>(Mat);
				if (!dyMaterial)
					continue;

				//�������ò��ʵ���ɫ
				//FLinearColor Color;
				//dyMaterial->SetVectorParameterValue(TEXT("ColorParamEX"), Color);
				//�������ò��ʵ�Ť������G���ܽ⡪��A
				FLinearColor Dynamic;
				dyMaterial->GetVectorParameterValue(TEXT("DynamicParamEX"), Dynamic);

				dyMaterial->SetVectorParameterValue(TEXT("DynamicParamEX"), Dynamic);
			}
		}
	}
}
