// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "World/LegworkSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "POI/POISQActor.h"
#include "World/LegworkDataAsset.h"
#include "SQAssetManager.h"

DEFINE_LOG_CATEGORY(LogLegworkSubsystem);

void ULegworkSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	USQAssetManager& SQAssetManager = USQAssetManager::Get();
	TArray<FPrimaryAssetId> AssetIDs;
	if (SQAssetManager.GetPrimaryAssetIdList(TEXT("LegworkDataAsset"), AssetIDs))
	{
		FStreamableDelegate Delegate = FStreamableDelegate::CreateUObject(this, &ULegworkSubsystem::OnLegworkAssetsLoaded, AssetIDs.Num());
		TArray<FName> Bundles;
		SQAssetManager.LoadPrimaryAssets(AssetIDs, Bundles, Delegate);
	}
}

void ULegworkSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void ULegworkSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	UE_LOG(LogLegworkSubsystem, Log, TEXT("MapName: %s"), *InWorld.OriginalWorldName.ToString());
}

TArray<ULegworkDataAsset*> ULegworkSubsystem::GetLegworkDataAssets(FPrimaryAssetId TargetId) const
{
	if (!TargetId.IsValid()) return TArray<ULegworkDataAsset*>();

	TArray<ULegworkDataAsset*> LegworkDataAssets;
	USQAssetManager& SQAssetManager = USQAssetManager::Get();
	TArray<FPrimaryAssetId> AssetIDs;
	if (SQAssetManager.GetPrimaryAssetIdList(TEXT("LegworkDataAsset"), AssetIDs))
	{
		for (FPrimaryAssetId Id : AssetIDs)
		{
			ULegworkDataAsset* LegworkDA = SQAssetManager.GetPrimaryAssetObject<ULegworkDataAsset>(Id);
			if (LegworkDA->IsInformationAboutTarget(TargetId))
			{
				LegworkDataAssets.Add(LegworkDA);
			}
		}
	}
	return LegworkDataAssets;
}

void ULegworkSubsystem::OnLegworkAssetsLoaded(int32 AssetsCount)
{
	UE_LOG(LogLegworkSubsystem, Log, TEXT("Loaded Assets Count: %d"), AssetsCount);
}
