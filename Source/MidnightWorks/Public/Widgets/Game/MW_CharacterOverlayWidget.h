// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MW_CharacterOverlayWidget.generated.h"

class UTextBlock;

UCLASS()
class MIDNIGHTWORKS_API UMW_CharacterOverlayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void ConvertTextBlockToString(int32& OutValue);
	void DecreaseCoinsCountTextBlockValue(int32 NewValue);

	int32 GetCoinCountValue();

private:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* CoinsCountTextBlock;
};
