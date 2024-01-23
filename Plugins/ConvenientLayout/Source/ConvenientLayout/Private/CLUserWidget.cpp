// (C) 2023 eggers-bhv


#include "CLUserWidget.h"

void UCLUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();


}

void UCLUserWidget::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = GameplayTagContainer;
}
