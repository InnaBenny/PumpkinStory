// Copyright PumpkinStory


#include "Actor/StoryEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
//#include "AbilitySystemInterface.h"
//#include "AbilitySystem/StoryAbilitySystemComponent.h"


AStoryEffectActor::AStoryEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}


void AStoryEffectActor::BeginPlay()
{
	Super::BeginPlay();

}

void AStoryEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle =  TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}

void AStoryEffectActor::OnOverlap(AActor* TargetActor)
{
	
}

void AStoryEffectActor::OnEndOverlap(AActor* TargetActor)
{
	
}



