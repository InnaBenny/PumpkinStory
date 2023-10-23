// Copyright PumpkinStory


#include "Character/StoryCharacterBase.h"

AStoryCharacterBase::AStoryCharacterBase()
{
 		PrimaryActorTick.bCanEverTick = false;

}

UAbilitySystemComponent* AStoryCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AStoryCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

