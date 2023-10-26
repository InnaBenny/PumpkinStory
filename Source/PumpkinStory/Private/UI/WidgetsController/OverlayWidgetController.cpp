// Copyright PumpkinStory


#include "UI/WidgetsController/OverlayWidgetController.h"

#include "AbilitySystem/StoryAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UStoryAttributeSet* StoryAttributeSet = CastChecked<UStoryAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(StoryAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(StoryAttributeSet->GetMaxHealth());

	//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(StoryAttributeSet->GetHealthAttribute()).AddUObject(this,)
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UStoryAttributeSet* StoryAttributeSet = CastChecked<UStoryAttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(StoryAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(StoryAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
