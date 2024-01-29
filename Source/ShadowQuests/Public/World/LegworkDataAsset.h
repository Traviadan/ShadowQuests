// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "Assets/SQPrimaryDataAsset.h"
#include "SQTypes.h"
#include "LegworkDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API ULegworkDataAsset : public USQPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	ULegworkDataAsset();

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

	UFUNCTION(BlueprintCallable)
	virtual void GetInformationsByLevel(int32 Level, TArray<FSQWorldInformation>& OutInformations) const;

	UFUNCTION(BlueprintCallable)
	virtual bool BelongsToMap(FName Map) const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsInformationAboutTarget(FPrimaryAssetId TargetId) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName MapName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FPrimaryAssetId About;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FSQWorldInformation> WorldInformations;
};
