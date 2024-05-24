// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MW_MovingPlatform.h"

#include "Components/InterpToMovementComponent.h"

AMW_MovingPlatform::AMW_MovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	InterpToMovementComponent = CreateDefaultSubobject<UInterpToMovementComponent>("Interp To Movement Component");
}
