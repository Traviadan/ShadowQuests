// (C) 2023 eggers-bhv

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CLCommonActivatableWidget.generated.h"

struct FUIInputConfig;

UENUM(BlueprintType)
enum class ECLWidgetInputMode : uint8
{
	Default,
	GameAndMenu,
	Game,
	Menu
};

/**
 * 
 */
UCLASS()
class CONVENIENTLAYOUT_API UCLCommonActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
	//~UCommonActivatableWidget interface
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;
	//~End of UCommonActivatableWidget interface

protected:
	/** The desired input mode to use while this UI is activated, for example do you want key presses to still reach the game/player controller? */
	UPROPERTY(EditDefaultsOnly, Category = Input)
	ECLWidgetInputMode InputConfig = ECLWidgetInputMode::Default;

	/** The desired mouse behavior when the game gets input. */
	UPROPERTY(EditDefaultsOnly, Category = Input)
	EMouseCaptureMode GameMouseCaptureMode = EMouseCaptureMode::CapturePermanently;
};
