// (C) 2023 eggers-bhv


#include "CLCommonActivatableWidget.h"

TOptional<FUIInputConfig> UCLCommonActivatableWidget::GetDesiredInputConfig() const
{
	switch (InputConfig)
	{
	case ECLWidgetInputMode::GameAndMenu:
		return FUIInputConfig(ECommonInputMode::All, GameMouseCaptureMode);
	case ECLWidgetInputMode::Game:
		return FUIInputConfig(ECommonInputMode::Game, GameMouseCaptureMode);
	case ECLWidgetInputMode::Menu:
		return FUIInputConfig(ECommonInputMode::Menu, EMouseCaptureMode::NoCapture);
	case ECLWidgetInputMode::Default:
	default:
		return TOptional<FUIInputConfig>();
	}
}
