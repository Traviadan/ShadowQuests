// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "Player/SQPlayerController.h"
#include "AbilitySystemComponent.h"
#include "Player/SQPlayerState.h"

void ASQPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ASQPlayerState* PS = GetPlayerState<ASQPlayerState>();
	if (PS)
	{
		// Init ASC with PS (Owner) and our new Pawn (AvatarActor)
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, InPawn);
	}
}

void ASQPlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// For edge cases where the PlayerState is repped before the Hero is possessed.
	//CreateHUD();
}
