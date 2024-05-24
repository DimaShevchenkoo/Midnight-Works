// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/MW_MainMenuPlayerController.h"

void AMW_MainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetShowMouseCursor(true);

	FInputModeUIOnly UIOnly;
	SetInputMode(UIOnly);
}
