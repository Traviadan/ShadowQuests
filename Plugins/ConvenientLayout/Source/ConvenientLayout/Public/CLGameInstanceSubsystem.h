// (C) 2023 eggers-bhv

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "CLGameInstanceSubsystem.generated.h"

class UCLRootLayout;
class UCommonActivatableWidget;
class UCommonActivatableWidgetStack;

/**
 * 
 */
UCLASS(meta = (DisplayName = "Layout System"))
class CONVENIENTLAYOUT_API UCLGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
    // Begin USubsystem
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    // End USubsystem

    UFUNCTION(BlueprintCallable)
    void ActivateLayout(TSubclassOf<UCLRootLayout> RootWidgetClass);

    UFUNCTION(BlueprintCallable)
    void DeactivateLayout();

    UFUNCTION(BlueprintCallable)
    UCommonActivatableWidget* GetActiveWidget(FGameplayTag LayerTag);

    UFUNCTION(BlueprintCallable)
    UCLRootLayout* GetRootLayout();

    UFUNCTION(BlueprintCallable)
    UCommonActivatableWidget* PushToLayer(TSubclassOf<UCommonActivatableWidget> WidgetToRegister, FGameplayTag LayerTag);

private:
    UCLRootLayout* RootWidget;

    TMap<FGameplayTag, UCommonActivatableWidgetStack*> WidgetContainers;
};
