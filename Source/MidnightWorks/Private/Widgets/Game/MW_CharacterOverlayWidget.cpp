// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/Game/MW_CharacterOverlayWidget.h"
#include "Components/TextBlock.h"
#include "GameState/MW_GameState.h"
#include "Kismet/GameplayStatics.h"

void UMW_CharacterOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	auto GS = Cast<AMW_GameState>(UGameplayStatics::GetGameState(this));
	if (!GS) return;

	CoinsCountTextBlock->SetText(FText::FromString(FString::FromInt(GS->GetCoinsArraySize())));
}

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
