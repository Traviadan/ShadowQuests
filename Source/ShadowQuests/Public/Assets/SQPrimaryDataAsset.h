// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SQPrimaryDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API USQPrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	USQPrimaryDataAsset();

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FName AssetType;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FName AssetId;
};
