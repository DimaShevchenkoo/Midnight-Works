// Fill out your copyright notice in the Description page of Project Settings.

#include "HUD/MW_MainMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/MainMenu/MW_MainMenuOverlayWidget.h"

void AMW_MainMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (!GetOwningPlayerController() || !MainMenuOverlayWidgetClass) return;

	MainMenuOverlayWidget = CreateWidget<UMW_MainMenuOverlayWidget>(GetOwningPlayerController(), MainMenuOverlayWidgetClass);
	if (!MainMenuOverlayWidget) return;

	MainMenuOverlayWidget->AddToViewport();
}
