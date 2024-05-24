// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/Game/MW_CharacterOverlayWidget.h"

#include "Components/TextBlock.h"

void UMW_CharacterOverlayWidget::DecreaseCoinsCountTextBlockValue(int32 NewValue)
{
	auto OldCoinsCountText = CoinsCountTextBlock->GetText().ToString();
	int32 OldCoinsCount = FCString::Atoi(*OldCoinsCountText);
	int32 NewCoinsCount = OldCoinsCount - NewValue;

	FString CoinsLeftText = FString::FromInt(NewCoinsCount) + " Coins Left!";

	CoinsCountTextBlock->SetText(FText::FromString(CoinsLeftText));
}
