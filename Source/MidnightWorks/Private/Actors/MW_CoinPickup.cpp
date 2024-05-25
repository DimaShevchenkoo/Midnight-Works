// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MW_CoinPickup.h"

#include "Characters/MW_PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Controllers/MW_PlayerController.h"
#include "GameState/MW_GameState.h"
#include "Kismet/GameplayStatics.h"

void AMW_CoinPickup::BeginPlay()
{
	Super::BeginPlay();

	GS = Cast<AMW_GameState>(UGameplayStatics::GetGameState(this));
	if (!GS) return;
	GS->AddCoinToArray(this);

	PickupBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::PickupOnOverlapBegin);
}

void AMW_CoinPickup::PickupOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		PlayerCharacter = PlayerCharacter ? PlayerCharacter : Cast<AMW_PlayerCharacter>(OtherActor);
		if (!PlayerCharacter) return;

		PC = PC ? PC : Cast<AMW_PlayerController>(PlayerCharacter->GetController());
		if (!PC) return;

		PC->DecreaseCoinsCountTextBlockValue(1);
		//TODO play animation

		if (!GS) return;
		GS->RemoveCoinFromArray(this);

		Destroy();
	}
}
