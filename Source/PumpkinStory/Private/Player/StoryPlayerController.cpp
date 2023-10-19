// Copyright PumpkinStory


#include "Player/StoryPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/NPCInterface.h"


AStoryPlayerController::AStoryPlayerController()
{
	bReplicates = true;
}

void AStoryPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
	
}

void AStoryPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(StoryContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(StoryContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AStoryPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AStoryPlayerController::Move);
}
void AStoryPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AStoryPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if(!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<INPCInterface>(CursorHit.GetActor());

	/**
	 * Line trace for cursor. There are several scenarios:
	 * A. LastActor is null && ThisActor is null
	 *		- Do nothing.
	 *	B. LastActor is null && ThisActor is valid
	 *		- Highlight ThisActor.
	 *	C. LastActor is valid && ThisActor is null
	 *		- UnHighlight LastActor.
	 *	D. Both actors are valid, but LastActor != ThisActor
	 *		- UnHighlight LastActor, and Highlight ThisActor.
	 *	E. Both actors are valid, and are the same actor
	 *		- Do nothing.
	 */

	if (LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			//Case B
			ThisActor->HighlightActor();
		}
		else
		{
			//both are null, do nothing - Case A
		}
	}
	else // LastActor is Valid
		{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		}
		else // both actors are valid
			{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case E - do nothing
			}
			}
		}
}
