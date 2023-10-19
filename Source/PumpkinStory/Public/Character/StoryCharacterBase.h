// Copyright PumpkinStory

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StoryCharacterBase.generated.h"

UCLASS(Abstract)
class PUMPKINSTORY_API AStoryCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AStoryCharacterBase();

protected:
	virtual void BeginPlay() override;
	

};
