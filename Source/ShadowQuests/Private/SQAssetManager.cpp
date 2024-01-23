// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "SQAssetManager.h"
#include "AbilitySystemGlobals.h"

USQAssetManager& USQAssetManager::Get()
{
	USQAssetManager* Singleton = Cast<USQAssetManager>(GEngine->AssetManager);

	if (Singleton)
	{
		return *Singleton;
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Invalid AssetManager in DefaultEngine.ini, must be SQAssetManager!"));
		return *NewObject<USQAssetManager>();	 // never calls this
	}
}

void USQAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	UAbilitySystemGlobals::Get().InitGlobalData();
}
