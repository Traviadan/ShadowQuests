// (C) 2023 eggers-bhv


#include "CLCommonUserWidget.h"

void UCLCommonUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

}

void UCLCommonUserWidget::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = GameplayTagContainer;
}
