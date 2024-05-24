// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/Game/MW_CharacterOverlayWidget.h"
#include "Components/TextBlock.h"

void UMW_CharacterOverlayWidget::DecreaseCoinsCountTextBlockValue(int32 NewValue)
{
	int32 OldCoinsCount;
	ConvertTextBlockToString(OldCoinsCount);

	int32 NewCoinsCount = OldCoinsCount - NewValue;

	FString CoinsLeftText = FString::FromInt(NewCoinsCount) + " Coins Left!";

	CoinsCountTextBlock->SetText(FText::FromString(CoinsLeftText));
}

int32 UMW_CharacterOverlayWidget::GetCoinCountValue()
{
	int32 CoinsCount;
	ConvertTextBlockToString(CoinsCount);

	return CoinsCount;
}

void UMW_CharacterOverlayWidget::ConvertTextBlockToString(int32& OutValue)
{
	auto CoinsCountText = CoinsCountTextBlock->GetText().ToString();
	OutValue = FCString::Atoi(*CoinsCountText);
}