// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/Game/MW_CharacterOverlayWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Components/TextBlock.h"
#include "GameState/MW_GameState.h"
#include "Kismet/GameplayStatics.h"

void UMW_CharacterOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	auto GS = Cast<AMW_GameState>(UGameplayStatics::GetGameState(this));
	if (!GS) return;

	CoinsCountTextBlock->SetText(FText::FromString(FString::FromInt(GS->GetCoinsLeftCount()) + " Coins Left!"));
}

void UMW_CharacterOverlayWidget::DecreaseCoinsCountTextBlockValue(int32 NewValue)
{
	int32 OldCoinsCount;
	ConvertTextBlockToString(OldCoinsCount);

	int32 NewCoinsCount = OldCoinsCount - NewValue;

	FString CoinsLeftText = FString::FromInt(NewCoinsCount) + " Coins Left!";

	CoinsCountTextBlock->SetText(FText::FromString(CoinsLeftText));
}

void UMW_CharacterOverlayWidget::ShowDeathTransition()
{
	PlayAnimation(DeathTransition);

	FTimerHandle PlayAnimationBackwardsHandle;
	GetWorld()->GetTimerManager().SetTimer(PlayAnimationBackwardsHandle, FTimerDelegate::CreateWeakLambda(this, [this]()
	{
		PlayAnimation(DeathTransition, 0.f, 1, EUMGSequencePlayMode::Reverse);
	}), DeathTransition->GetEndTime(), false);
}

void UMW_CharacterOverlayWidget::ShowJumpBoosterVisibility(bool bVisible, float BoosterVisibilityTime)
{
	if (bVisible)
	{
		PlayAnimation(JumpBoosterAnimationAppear);

		JumpTimeLeftRemain->SetText(FText::FromString(FString::SanitizeFloat(BoosterVisibilityTime)));
		UpdateBoosterTimerText(JumpTimeLeftRemain);
	}
	else
	{
		PlayAnimation(JumpBoosterAnimationFinish);
	}
}

void UMW_CharacterOverlayWidget::ShowSpeedBoosterVisibility(bool bVisible, float BoosterVisibilityTime)
{
	if (bVisible)
	{
		PlayAnimation(SpeedBoosterAnimationAppear);

		SprintTimeLeftRemain->SetText(FText::FromString(FString::SanitizeFloat(BoosterVisibilityTime)));
		UpdateBoosterTimerText(SprintTimeLeftRemain);
	}
	else
	{
		PlayAnimation(SpeedBoosterAnimationFinish);
	}
}

void UMW_CharacterOverlayWidget::UpdateBoosterTimerText(UTextBlock* BoosterTextBlock)
{
	float TimeRemaining = FCString::Atof(*BoosterTextBlock->GetText().ToString());
	if (TimeRemaining <= 0.f)
	{
		BoosterTextBlock->SetVisibility(ESlateVisibility::Hidden);
		return;
	}
	TimeRemaining -= 0.1f;
	BoosterTextBlock->SetText(FText::FromString(FString::SanitizeFloat(TimeRemaining)));

	FTimerHandle UpdateBoosterTimerHandle;
	FTimerDelegate UpdateBoosterTimerDelegate = FTimerDelegate::CreateUObject(this, &ThisClass::UpdateBoosterTimerText, BoosterTextBlock);

	GetWorld()->GetTimerManager().SetTimer(UpdateBoosterTimerHandle, UpdateBoosterTimerDelegate, 0.1f, false);
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
