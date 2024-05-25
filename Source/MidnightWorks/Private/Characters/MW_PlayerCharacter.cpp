// Fill out your copyright notice in the Description page of Project Settings.

#include "MidnightWorks/Public/Characters/MW_PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMW_PlayerCharacter::AMW_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void AMW_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	StartPosition = GetActorLocation();
}
