// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MW_JumpBooster.h"

#include "Characters/MW_PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Controllers/MW_PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

AMW_JumpBooster::AMW_JumpBooster()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMW_JumpBooster::BeginPlay()
{
	Super::BeginPlay();

	PickupBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::PickupOnOverlapBegin);
}

void AMW_JumpBooster::PickupOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		PlayerCharacter = PlayerCharacter ? PlayerCharacter : Cast<AMW_PlayerCharacter>(OtherActor);
		if (!PlayerCharacter) return;
		
		if (PlayerCharacter->GetJumpBoosterInUse() == true)
		{
			return;
		}

		PlayerCharacter->SetJumpBoosterInUse(true);

		PickupMesh->SetVisibility(false);

		BaseJumpHeight = PlayerCharacter->GetCharacterMovement()->JumpZVelocity;
		PlayerCharacter->GetCharacterMovement()->JumpZVelocity = BaseJumpHeight * 5.f;

		PC = PC ? PC : Cast<AMW_PlayerController>(PlayerCharacter->GetController());
		if (!PC) return;
		PC->ShowJumpBoosterVisibility(true, BoosterApplyTime);

		FTimerHandle ReverseJumpTimerHandle;
		GetWorld()->GetTimerManager().SetTimer(ReverseJumpTimerHandle, FTimerDelegate::CreateWeakLambda(this, [this]()
		{
			PlayerCharacter->GetCharacterMovement()->JumpZVelocity = BaseJumpHeight;
			PlayerCharacter->SetJumpBoosterInUse(false);

			PC->ShowJumpBoosterVisibility(false, BoosterApplyTime);

			Destroy();
		}), BoosterApplyTime, false);
	}
}



