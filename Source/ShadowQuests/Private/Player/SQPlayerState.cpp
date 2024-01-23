// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "Player/SQPlayerState.h"
#include "Characters/Abilities/SQAbilitySystemComponent.h"

ASQPlayerState::ASQPlayerState()
{
	// Create ability system component, and set it to be explicitly replicated
	AbilitySystemComponent = CreateDefaultSubobject<USQAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// Mixed mode means we only are replicated the GEs to ourself, not the GEs to simulated proxies. If another GDPlayerState (Hero) receives a GE,
	// we won't be told about it by the Server. Attributes, GameplayTags, and GameplayCues will still replicate to us.
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Set PlayerState's NetUpdateFrequency to the same as the Character.
	// Default is very low for PlayerStates and introduces perceived lag in the ability system.
	// 100 is probably way too high for a shipping game, you can adjust to fit your needs.
	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* ASQPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASQPlayerState::BeginPlay()
{
	Super::BeginPlay();
}
