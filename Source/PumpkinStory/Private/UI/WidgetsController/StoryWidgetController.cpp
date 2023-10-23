// Copyright PumpkinStory


#include "UI/WidgetsController/StoryWidgetController.h"

void UStoryWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UStoryWidgetController::BroadcastInitialValues()
{
	
}

void UStoryWidgetController::BindCallbacksToDependencies()
{
	
}
