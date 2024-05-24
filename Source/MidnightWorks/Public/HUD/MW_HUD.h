// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MW_HUD.generated.h"

class UMW_VictoryWidget;
class UMW_CharacterOverlayWidget;

UCLASS()
class MIDNIGHTWORKS_API AMW_HUD : public AHUD
{
	GENERATED_BODY()

public:
	void DecreaseCoinsCountTextBlockValue(int32 NumToDecrease);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> CharacterOverlayWidgetClass;

	UPROPERTY()
	UMW_CharacterOverlayWidget* CharacterOverlayWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> VictoryWidgetClass;

	UPROPERTY()
	UMW_VictoryWidget* VictoryWidget;
};
