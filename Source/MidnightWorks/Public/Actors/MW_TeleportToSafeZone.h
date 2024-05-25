// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MW_TeleportToSafeZone.generated.h"

class UBoxComponent;

UCLASS()
class MIDNIGHTWORKS_API AMW_TeleportToSafeZone : public AActor
{
	GENERATED_BODY()
	
public:	
	AMW_TeleportToSafeZone();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OverlapWithKillZoneBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep,
								  const FHitResult& SweepResult);

private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollision;

};
