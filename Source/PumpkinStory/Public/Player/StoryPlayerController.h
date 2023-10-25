// Copyright PumpkinStory

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "StoryPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class INPCInterface;


/**
 * 
 */
UCLASS()
class PUMPKINSTORY_API AStoryPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AStoryPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> StoryContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
/*
	void CursorTrace();
	INPCInterface* LastActor;
	INPCInterface* ThisActor;
	*/
};
