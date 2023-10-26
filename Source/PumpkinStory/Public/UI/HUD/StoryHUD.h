// Copyright PumpkinStory

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Widgets/StoryUserWidget.h"
#include "StoryHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UStoryUserWidget;
class UOverlayWidgetController;
struct FWidgetControllerParams;


/**
 * 
 */
UCLASS()
class PUMPKINSTORY_API AStoryHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStoryUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UStoryUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
