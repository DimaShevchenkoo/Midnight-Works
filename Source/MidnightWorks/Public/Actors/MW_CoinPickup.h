// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/MW_BasePickup.h"
#include "MW_CoinPickup.generated.h"

UCLASS()
class MIDNIGHTWORKS_API AMW_CoinPickup : public AMW_BasePickup
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void PickupOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
private:
	UPROPERTY()
	AMW_GameState* GS;
};
