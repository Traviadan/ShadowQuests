// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "Pawns/SQPawn.h"

// Sets default values
ASQPawn::ASQPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASQPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASQPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASQPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

