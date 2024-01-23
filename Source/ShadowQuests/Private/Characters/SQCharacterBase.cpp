// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "Characters/SQCharacterBase.h"

// Sets default values
ASQCharacterBase::ASQCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASQCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASQCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASQCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

