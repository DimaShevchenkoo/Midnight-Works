// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MW_BasePickup.generated.h"

class AMW_PlayerController;
class AMW_PlayerCharacter;
class AMW_GameState;
class UBoxComponent;

UCLASS()
class MIDNIGHTWORKS_API AMW_BasePickup : public AActor
{
	GENERATED_BODY()

public:	
	AMW_BasePickup();

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere)
	UBoxComponent* PickupBoxCollision;

	UPROPERTY()
	AMW_PlayerCharacter* PlayerCharacter;

	UPROPERTY()
	AMW_PlayerController* PC;

	UPROPERTY(EditAnywhere)
	float BoosterApplyTime = 5.f;

	bool bBoosterActivated = false;
};
