// (C) 2023 eggers-bhv

#pragma once

#include "CoreMinimal.h"
#include "CLUserWidget.h"
#include "CLRootLayout.generated.h"

class UCommonActivatableWidgetStack;

/**
 * 
 */
UCLASS()
class CONVENIENTLAYOUT_API UCLRootLayout : public UCLUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCommonActivatableWidgetStack* GameLayer_Stack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCommonActivatableWidgetStack* GameInfoLayer_Stack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCommonActivatableWidgetStack* GameMenuLayer_Stack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCommonActivatableWidgetStack* MenuLayer_Stack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCommonActivatableWidgetStack* ModalLayer_Stack;
};
