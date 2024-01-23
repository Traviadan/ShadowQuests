// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "Characters/Abilities/SQAbilitySystemComponent.h"

void USQAbilitySystemComponent::ReceiveDamage(USQAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage)
{
	ReceivedDamage.Broadcast(SourceASC, UnmitigatedDamage, MitigatedDamage);
}
