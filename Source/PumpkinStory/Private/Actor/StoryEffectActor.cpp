// Copyright PumpkinStory


#include "Actor/StoryEffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/StoryAttributeSet.h"
// Sets default values
AStoryEffectActor::AStoryEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AStoryEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UStoryAttributeSet* StoryAttributeSet = Cast<UStoryAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UStoryAttributeSet::StaticClass()));
		
		UStoryAttributeSet* MutableStoryAttributeSet = const_cast<UStoryAttributeSet*>(StoryAttributeSet);
		MutableStoryAttributeSet->SetHealth(StoryAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AStoryEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}


void AStoryEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AStoryEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AStoryEffectActor::EndOverlap);
}



