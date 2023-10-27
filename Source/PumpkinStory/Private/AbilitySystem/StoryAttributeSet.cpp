// Copyright PumpkinStory


#include "AbilitySystem/StoryAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Character/StoryCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"

UStoryAttributeSet::UStoryAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
}

void UStoryAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UStoryAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UStoryAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UStoryAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UStoryAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UStoryAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
}

void UStoryAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
	Cast<AStoryCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0))->Health = GetHealthAttribute().GetNumericValue(this);

		if(Health.GetBaseValue()<=0.f)
		{
			UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
			ASC->SetNumericAttributeBase(GetHealthAttribute(), 50.f);
		}
	}
	
	
}

void UStoryAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UStoryAttributeSet, Health, OldHealth);
}

void UStoryAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UStoryAttributeSet, MaxHealth, OldMaxHealth);
}

void UStoryAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UStoryAttributeSet, Mana, OldMana);
}

void UStoryAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UStoryAttributeSet, MaxMana, OldMaxMana);
}
