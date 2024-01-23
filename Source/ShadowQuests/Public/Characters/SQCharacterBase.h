// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "SQCharacterBase.generated.h"

UCLASS()
class SHADOWQUESTS_API ASQCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASQCharacterBase();

	// Implement IAbilitySystemInterface
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Instead of TWeakObjectPtrs, you could just have UPROPERTY() hard references or no references at all and just call
	// GetAbilitySystem() and make a GetAttributeSetBase() that can read from the PlayerState or from child classes.
	// Just make sure you test if the pointer is valid before using.
	// I opted for TWeakObjectPtrs because I didn't want a shared hard reference here and I didn't want an extra function call of getting
	// the ASC/AttributeSet from the PlayerState or child classes every time I referenced them in this base class.

	TWeakObjectPtr<class USQAbilitySystemComponent> AbilitySystemComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
