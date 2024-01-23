// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SQPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API ASQPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	// Server only
	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnRep_PlayerState() override;
};
