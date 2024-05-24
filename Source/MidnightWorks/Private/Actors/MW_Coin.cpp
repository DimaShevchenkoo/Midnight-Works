// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MW_Coin.h"

#include "Characters/MW_PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Controllers/MW_PlayerController.h"

AMW_Coin::AMW_Coin()
{
	PrimaryActorTick.bCanEverTick = true;

	PickupBoxCollision = CreateDefaultSubobject<UBoxComponent>("Pickup Box Collision");
	RootComponent = PickupBoxCollision;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("Coin Mesh");
	CoinMesh->SetupAttachment(GetRootComponent());
}

void AMW_Coin::BeginPlay()
{
	Super::BeginPlay();

	PickupBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::PickupCoinOnOverlapBegin);
}

void AMW_Coin::PickupCoinOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		auto PlayerCharacter = Cast<AMW_PlayerCharacter>(OtherActor);
		if (!PlayerCharacter) return;

		auto PC = Cast<AMW_PlayerController>(PlayerCharacter->GetController());
		if (!PC) return;

		PC->DecreaseCoinsCountTextBlockValue(1);
		//TODO play animation

		Destroy();
	}
}
