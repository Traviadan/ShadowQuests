// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "Characters/Heroes/SQHeroCharacter.h"
#include "Player/SQPlayerState.h"
#include "Characters/Abilities/SQAbilitySystemComponent.h"

void ASQHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASQHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	ASQPlayerState* PS = GetPlayerState<ASQPlayerState>();
	if (PS)
	{
		// Set the ASC on the Server. Clients do this in OnRep_PlayerState()
		AbilitySystemComponent = Cast<USQAbilitySystemComponent>(PS->GetAbilitySystemComponent());

		// AI won't have PlayerControllers so we can init again here just to be sure. No harm in initing twice for heroes that have PlayerControllers.
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);

		// Set the AttributeSetBase for convenience attribute functions
		//AttributeSetBase = PS->GetAttributeSetBase();

		// If we handle players disconnecting and rejoining in the future, we'll have to change this so that possession from rejoining doesn't reset attributes.
		// For now assume possession = spawn/respawn.
		//InitializeAttributes();


		// Respawn specific things that won't affect first possession.

		// Forcibly set the DeadTag count to 0
		//AbilitySystemComponent->SetTagMapCount(DeadTag, 0);

		// Set Health/Mana/Stamina to their max. This is only necessary for *Respawn*.
		//SetHealth(GetMaxHealth());
		//SetMana(GetMaxMana());
		//SetStamina(GetMaxStamina());

		// End respawn specific things
		//AddStartupEffects();

		//AddCharacterAbilities();

		//AGDPlayerController* PC = Cast<AGDPlayerController>(GetController());
		//if (PC)
		//{
			//PC->CreateHUD();
		//}

		//InitializeFloatingStatusBar();
	}
}
