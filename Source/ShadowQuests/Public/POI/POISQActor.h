// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "SQActor.h"
#include "POISQActor.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API APOISQActor : public ASQActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "POI")
	FName MapId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "POI")
	FPrimaryAssetId AssetId;
};
