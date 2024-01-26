// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "Assets/SQPrimaryDataAsset.h"
#include "POIDataAsset.generated.h"

class APOISQActor;
/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API UPOIDataAsset : public USQPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPOIDataAsset();

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn Info", meta = (AssetBundles = "Actor"))
	//TSubclassOf<APOISQActor> POIClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info", meta = (AssetBundles = "UI"))
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info", meta = (AssetBundles = "UI"))
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info", meta = (AssetBundles = "UI"))
	TAssetPtr<UTexture2D> IconPtr;
};
