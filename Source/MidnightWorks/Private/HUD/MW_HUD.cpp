// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MW_HUD.h"

#include "Blueprint/UserWidget.h"
#include "Widgets/Game/MW_CharacterOverlayWidget.h"


void AMW_HUD::BeginPlay()
{
	Super::BeginPlay();

	if (!GetOwningPlayerController())
	{
		UE_LOG(LogTemp, Warning, TEXT("GetOwningPlayerController() - nullptr"))
		return;
	}

	CharacterOverlayWidget = CreateWidget<UMW_CharacterOverlayWidget>(GetOwningPlayerController(), CharacterOverlayWidgetClass);
	if (!CharacterOverlayWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("CharacterOverlayWidget - nullptr"))
		return;
	}

	CharacterOverlayWidget->AddToViewport();
}

void AMW_HUD::DecreaseCoinsCountTextBlockValue(int32 NumToDecrease)
{
	if (!CharacterOverlayWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("CharacterOverlayWidget - nullptr"))
		return;
	}
	CharacterOverlayWidget->DecreaseCoinsCountTextBlockValue(NumToDecrease);
}