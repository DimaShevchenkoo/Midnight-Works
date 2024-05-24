// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MW_MainMenuHUD.generated.h"

class UMW_MainMenuOverlayWidget;

UCLASS()
class MIDNIGHTWORKS_API AMW_MainMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> MainMenuOverlayWidgetClass;

	UPROPERTY()
	UMW_MainMenuOverlayWidget* MainMenuOverlayWidget;
};
