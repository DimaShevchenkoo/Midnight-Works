// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MW_MovingPlatform.generated.h"

class UInterpToMovementComponent;

UCLASS()
class MIDNIGHTWORKS_API AMW_MovingPlatform : public AActor
{
	GENERATED_BODY()

public:	
	AMW_MovingPlatform();

private:
	UPROPERTY(EditAnywhere)
	UInterpToMovementComponent* InterpToMovementComponent;
};
