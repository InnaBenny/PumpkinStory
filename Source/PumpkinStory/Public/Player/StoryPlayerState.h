// Copyright PumpkinStory

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/StoryAbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "StoryPlayerState.generated.h"

class UStoryAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class PUMPKINSTORY_API AStoryPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AStoryPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
protected:
	UPROPERTY()
	TObjectPtr<UStoryAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	UAttributeSet* AttributeSet;
};
