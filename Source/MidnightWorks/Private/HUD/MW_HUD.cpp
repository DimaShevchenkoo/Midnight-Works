// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MW_HUD.h"

#include "Blueprint/UserWidget.h"
#include "Widgets/Game/MW_CharacterOverlayWidget.h"
#include "Widgets/Game/MW_VictoryWidget.h"

void AMW_HUD::BeginPlay()
{
	Super::BeginPlay();

	if (!GetOwningPlayerController()) return;

	CharacterOverlayWidget = CreateWidget<UMW_CharacterOverlayWidget>(GetOwningPlayerController(), CharacterOverlayWidgetClass);
	if (!CharacterOverlayWidget) return;

	CharacterOverlayWidget->AddToViewport();
}

void AMW_HUD::DecreaseCoinsCountTextBlockValue(int32 NumToDecrease)
{
	if (!CharacterOverlayWidget) return;

	CharacterOverlayWidget->DecreaseCoinsCountTextBlockValue(NumToDecrease);
}

void AMW_HUD::CreateVictoryWidget()
{
	if (!GetOwningPlayerController()) return;

	VictoryWidget = CreateWidget<UMW_VictoryWidget>(GetOwningPlayerController(), VictoryWidgetClass);
	if (!VictoryWidget) return;

	VictoryWidget->AddToViewport();
}

int32 AMW_HUD::GetCoinCountValue()
{
	if (!CharacterOverlayWidget) return -999 /* should never happen, but in case it happens we handle it in player controller */;

	return CharacterOverlayWidget->GetCoinCountValue();
}
