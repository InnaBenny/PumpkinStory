// Copyright PumpkinStory


#include "UI/WidgetsController/OverlayWidgetController.h"

#include "AbilitySystem/StoryAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UStoryAttributeSet* StoryAttributeSet = CastChecked<UStoryAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(StoryAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(StoryAttributeSet->GetMaxHealth());
}
