// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "Characters/SQCharacterBase.h"
#include "SQHeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API ASQHeroCharacter : public ASQCharacterBase
{
	GENERATED_BODY()
	
public: 
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Only called on the Server. Calls before Server's AcknowledgePossession.
	virtual void PossessedBy(AController* NewController) override;
};
