// Fill out your copyright notice in the Description page of Project Settings.

#include "..\..\Public\Actors\MW_BasePickup.h"
#include "Characters/MW_PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Controllers/MW_PlayerController.h"
#include "GameState/MW_GameState.h"
#include "Kismet/GameplayStatics.h"

AMW_BasePickup::AMW_BasePickup()
{
	PrimaryActorTick.bCanEverTick = true;

	PickupBoxCollision = CreateDefaultSubobject<UBoxComponent>("Pickup Box Collision");
	RootComponent = PickupBoxCollision;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("Pickup Mesh");
	PickupMesh->SetupAttachment(GetRootComponent());
}
