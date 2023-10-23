// Copyright PumpkinStory


#include "UI/Widgets/StoryUserWidget.h"

void UStoryUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
