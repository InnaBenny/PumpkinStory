// Copyright PumpkinStory


#include "Player/StoryPlayerState.h"

#include "AbilitySystem/StoryAttributeSet.h"

AStoryPlayerState::AStoryPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UStoryAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UStoryAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AStoryPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
