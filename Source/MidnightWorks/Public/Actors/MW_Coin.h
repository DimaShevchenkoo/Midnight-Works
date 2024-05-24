// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MW_Coin.generated.h"

class UBoxComponent;

UCLASS()
class MIDNIGHTWORKS_API AMW_Coin : public AActor
{
	GENERATED_BODY()

public:	
	AMW_Coin();

protected:
	UFUNCTION()
	void PickupCoinOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep,
	                              const FHitResult& SweepResult);

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(EditAnywhere)
	UBoxComponent* PickupBoxCollision;
};
