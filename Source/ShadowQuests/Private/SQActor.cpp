// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "SQActor.h"

// Sets default values
ASQActor::ASQActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASQActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASQActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

