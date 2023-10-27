// Copyright PumpkinStory

#pragma once

#include "CoreMinimal.h"
#include "Character/StoryCharacterBase.h"
#include "StoryCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PUMPKINSTORY_API AStoryCharacter : public AStoryCharacterBase
{
	GENERATED_BODY()
public:
	AStoryCharacter();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Health = 999;
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
private:
	void InitAbilityActorInfo();
};
