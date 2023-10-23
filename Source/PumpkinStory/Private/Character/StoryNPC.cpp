// Copyright PumpkinStory


#include "Character/StoryNPC.h"

#include "AbilitySystem/StoryAbilitySystemComponent.h"
#include "AbilitySystem/StoryAttributeSet.h"

AStoryNPC::AStoryNPC()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	AbilitySystemComponent = CreateDefaultSubobject<UStoryAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UStoryAttributeSet>("AttributeSet");
}

void AStoryNPC::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250.f);
}

void AStoryNPC::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
}

void AStoryNPC::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

