// (C) 2023 eggers-bhv


#include "CLGameInstanceSubsystem.h"
#include "CLRootLayout.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "CommonActivatableWidget.h"
#include "CLGameplayTags.h"

void UCLGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	
}

void UCLGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();

}

void UCLGameInstanceSubsystem::ActivateLayout(TSubclassOf<UCLRootLayout> RootWidgetClass)
{
	if (RootWidget) return;

	if (RootWidgetClass)
	{
		if (UWorld* World = GetWorld())
		{
			if (APlayerController* Controller = World->GetFirstPlayerController())
			{
				RootWidget = CreateWidget<UCLRootLayout>(Controller, RootWidgetClass);
				RootWidget->AddToViewport();
			}
		}
	}

	if (RootWidget)
	{
		WidgetContainers.Add(TAG_Layout_Layer_Game, RootWidget->GameLayer_Stack);
		WidgetContainers.Add(TAG_Layout_Layer_GameInfo, RootWidget->GameInfoLayer_Stack);
		WidgetContainers.Add(TAG_Layout_Layer_GameMenu, RootWidget->GameMenuLayer_Stack);
		WidgetContainers.Add(TAG_Layout_Layer_Menu, RootWidget->MenuLayer_Stack);
		WidgetContainers.Add(TAG_Layout_Layer_Modal, RootWidget->ModalLayer_Stack);
	}
}

UCommonActivatableWidget* UCLGameInstanceSubsystem::GetActiveWidget(FGameplayTag LayerTag)
{
	if (RootWidget)
	{
		if (UCommonActivatableWidgetStack* Stack = *WidgetContainers.Find(LayerTag))
		{
			return Stack->GetActiveWidget();
		}
	}
	return nullptr;
}

void UCLGameInstanceSubsystem::DeactivateLayout()
{
	if (RootWidget)
	{
		RootWidget->RemoveFromParent();
		RootWidget = nullptr;
	}
}

UCLRootLayout* UCLGameInstanceSubsystem::GetRootLayout()
{
	return RootWidget;
}

UCommonActivatableWidget* UCLGameInstanceSubsystem::PushToLayer(TSubclassOf<UCommonActivatableWidget> WidgetToRegister, FGameplayTag LayerTag)
{
	if (RootWidget)
	{
		if (UCommonActivatableWidgetStack* Stack = *WidgetContainers.Find(LayerTag))
		{
			Stack->ClearWidgets();
			return Stack->AddWidget(WidgetToRegister);
		}
	}
	return nullptr;
}
