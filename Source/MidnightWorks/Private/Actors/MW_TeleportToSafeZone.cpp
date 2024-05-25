// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MW_TeleportToSafeZone.h"

#include "Characters/MW_PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Controllers/MW_PlayerController.h"

AMW_TeleportToSafeZone::AMW_TeleportToSafeZone()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	RootComponent = BoxCollision;
}

void AMW_TeleportToSafeZone::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapWithKillZoneBegin);
}

void AMW_TeleportToSafeZone::OverlapWithKillZoneBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		auto PlayerCharacter = Cast<AMW_PlayerCharacter>(OtherActor);
		if (!PlayerCharacter) return;

		auto PC = Cast<AMW_PlayerController>(PlayerCharacter->GetController());
		if (!PC) return;

		PC->ShowDeathTransition();

		FTimerHandle PlayAnimationBackwardsHandle;
		GetWorld()->GetTimerManager().SetTimer(PlayAnimationBackwardsHandle, FTimerDelegate::CreateWeakLambda(this, [PlayerCharacter]()
		{
			PlayerCharacter->SetActorLocation(PlayerCharacter->GetSpawnLocation());
		}), 0.4f, false);
	}
}


