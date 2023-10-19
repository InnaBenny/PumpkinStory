// Copyright PumpkinStory

#pragma once

#include "CoreMinimal.h"
#include "Character/StoryCharacterBase.h"
#include "Interaction/NPCInterface.h"
#include "StoryNPC.generated.h"

/**
 * 
 */
UCLASS()
class PUMPKINSTORY_API AStoryNPC : public AStoryCharacterBase, public INPCInterface
{
	GENERATED_BODY()
public:
	AStoryNPC();
	
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
protected:
	virtual void BeginPlay() override;
};
