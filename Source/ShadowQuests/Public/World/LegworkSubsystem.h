// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "LegworkSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogLegworkSubsystem, Log, All);

class ULegworkDataAsset;

/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API ULegworkSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
    // Begin USubsystem
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    virtual void OnWorldBeginPlay(UWorld& InWorld) override;
    // End USubsystem

    UFUNCTION(BlueprintCallable)
    virtual TArray<ULegworkDataAsset*> GetLegworkDataAssets(FPrimaryAssetId TargetId) const;

private:
    void OnLegworkAssetsLoaded(int32 AssetsCount);
};
