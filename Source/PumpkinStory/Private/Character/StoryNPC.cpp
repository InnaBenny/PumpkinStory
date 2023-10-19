// Copyright PumpkinStory


#include "Character/StoryNPC.h"

AStoryNPC::AStoryNPC()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
	
}

