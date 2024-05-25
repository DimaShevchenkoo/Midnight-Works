// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MW_SpeedBooster.h"
#include "Characters/MW_PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Controllers/MW_PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

AMW_SpeedBooster::AMW_SpeedBooster()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMW_SpeedBooster::BeginPlay()
{
	Super::BeginPlay();

	PickupBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::PickupOnOverlapBegin);
}

void AMW_SpeedBooster::PickupOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		PlayerCharacter = PlayerCharacter ? PlayerCharacter : Cast<AMW_PlayerCharacter>(OtherActor);
		if (!PlayerCharacter) return;

		if (PlayerCharacter->GetSpeedBoosterInUse() == true)
		{
			return;
		}

		PlayerCharacter->SetSpeedBoosterInUse(true);

		PickupMesh->SetVisibility(false);

		BaseCharacterSpeed = PlayerCharacter->GetCharacterMovement()->GetMaxSpeed();
		PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = BaseCharacterSpeed * SpeedBoostMultiplier;

		PC = PC ? PC : Cast<AMW_PlayerController>(PlayerCharacter->GetController());
		if (!PC) return;
		PC->ShowSpeedBoosterVisibility(true, BoosterApplyTime);

		FTimerHandle ReverseSpeedTimerHandle;
		GetWorld()->GetTimerManager().SetTimer(ReverseSpeedTimerHandle, FTimerDelegate::CreateWeakLambda(this, [this]()
		{
			PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = BaseCharacterSpeed;
			PlayerCharacter->SetSpeedBoosterInUse(false);

			PC->ShowSpeedBoosterVisibility(false, BoosterApplyTime);

			Destroy();
		}), BoosterApplyTime, false);
	}
}
