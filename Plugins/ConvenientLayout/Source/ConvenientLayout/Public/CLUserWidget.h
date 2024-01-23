// (C) 2023 eggers-bhv

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "CLUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CONVENIENTLAYOUT_API UCLUserWidget : public UUserWidget, public IGameplayTagAssetInterface
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer GameplayTagContainer;
};
