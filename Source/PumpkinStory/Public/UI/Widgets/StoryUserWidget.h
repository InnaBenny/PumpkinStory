// Copyright PumpkinStory

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StoryUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUMPKINSTORY_API UStoryUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	
protected:
	
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
