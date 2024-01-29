// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "SQAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API USQAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	static USQAssetManager& Get();

	/** Starts initial load, gets called from InitializeObjectReferences */
	virtual void StartInitialLoading() override;
};
