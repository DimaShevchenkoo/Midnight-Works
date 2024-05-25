// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MW_BasePickup.h"
#include "GameFramework/Actor.h"
#include "MW_JumpBooster.generated.h"

class UBoxComponent;

UCLASS()
class MIDNIGHTWORKS_API AMW_JumpBooster : public AMW_BasePickup
{
	GENERATED_BODY()
	
public:	
	AMW_JumpBooster();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void PickupOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep,
								  const FHitResult& SweepResult);

private:
	float BaseJumpHeight;

	UPROPERTY(EditAnywhere)
	float JumpHeightMultiplier = 5.f;
};
