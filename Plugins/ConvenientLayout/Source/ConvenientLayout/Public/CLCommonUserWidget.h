// (C) 2023 eggers-bhv

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "CLCommonUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CONVENIENTLAYOUT_API UCLCommonUserWidget : public UCommonUserWidget, public IGameplayTagAssetInterface
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer GameplayTagContainer;
};
