// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MW_VictoryTriggerBox.h"

#include "Characters/MW_PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Controllers/MW_PlayerController.h"

AMW_VictoryTriggerBox::AMW_VictoryTriggerBox()
{
	PrimaryActorTick.bCanEverTick = true;

	EndGameTriggerBox = CreateDefaultSubobject<UBoxComponent>("EndGameTriggerBox");
	RootComponent = EndGameTriggerBox;

	DoorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("DoorMeshComponent");
	DoorMeshComponent->SetupAttachment(GetRootComponent());
}

void AMW_VictoryTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	EndGameTriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::EndGameTrigger);
}

void AMW_VictoryTriggerBox::EndGameTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		auto PlayerCharacter = Cast<AMW_PlayerCharacter>(OtherActor);
		if (!PlayerCharacter) return;

		auto PC = Cast<AMW_PlayerController>(PlayerCharacter->GetController());
		if (!PC) return;

		PC->CreateVictoryVidget();
	}
}

void AMW_VictoryTriggerBox::OpenDoor()
{
	DoorMeshComponent->DestroyComponent();
}
