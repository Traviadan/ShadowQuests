// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SQAbilitySystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceivedDamageDelegate, USQAbilitySystemComponent*, SourceASC, float, UnmitigatedDamage, float, MitigatedDamage);

/**
 * 
 */
UCLASS()
class SHADOWQUESTS_API USQAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
	bool bCharacterAbilitiesGiven = false;
	bool bStartupEffectsApplied = false;

	FReceivedDamageDelegate ReceivedDamage;

	// Called from GDDamageExecCalculation. Broadcasts on ReceivedDamage whenever this ASC receives damage.
	virtual void ReceiveDamage(USQAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage);
};
