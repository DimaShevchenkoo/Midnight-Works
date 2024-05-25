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
	void ShowDeathTransition();
	void ShowJumpBoosterVisibility(bool bVisible, float BoosterVisibilityTime);
	void ShowSpeedBoosterVisibility(bool bVisible, float BoosterVisibilityTime);

	int32 GetCoinCountValue();

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* CoinsCountTextBlock;

	UPROPERTY(meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* DeathTransition;

	UPROPERTY(meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* SpeedBoosterAnimationAppear;

	UPROPERTY(meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* SpeedBoosterAnimationFinish;

	UPROPERTY(meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* JumpBoosterAnimationAppear;

	UPROPERTY(meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* JumpBoosterAnimationFinish;
};
