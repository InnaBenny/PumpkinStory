// Copyright PumpkinStory


#include "Character/StoryCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/StoryPlayerController.h"
#include "Player/StoryPlayerState.h"
#include "UI/HUD/StoryHUD.h"



AStoryCharacter::AStoryCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;	
}

void AStoryCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	// Init ability actor info for the Server
	InitAbilityActorInfo();
	
}

void AStoryCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AStoryCharacter::InitAbilityActorInfo()
{
	AStoryPlayerState* StoryPlayerState = GetPlayerState<AStoryPlayerState>();
	check(StoryPlayerState);
	StoryPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(StoryPlayerState, this);
	AbilitySystemComponent = StoryPlayerState->GetAbilitySystemComponent();
	AttributeSet = StoryPlayerState->GetAttributeSet();

	if (AStoryPlayerController* StoryPlayerController = Cast<AStoryPlayerController>(GetController()))
	{
		if (AStoryHUD* StoryHUD = Cast<AStoryHUD>(StoryPlayerController->GetHUD()))
		{
			StoryHUD->InitOverlay(StoryPlayerController, StoryPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	
}
