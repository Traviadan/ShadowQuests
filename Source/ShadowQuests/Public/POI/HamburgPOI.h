// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "POI/POIDataAsset.h"
#include "HamburgPOI.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API UHamburgPOI : public UPOIDataAsset
{
	GENERATED_BODY()
	
public:
	UHamburgPOI();

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
