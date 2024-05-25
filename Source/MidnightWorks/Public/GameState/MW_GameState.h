// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MW_GameState.generated.h"

class AMW_CoinPickup;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllKeysAcquiredDelegate);

UCLASS()
class MIDNIGHTWORKS_API AMW_GameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	void AddCoinToArray(int32 NumCoinsToAdd);
	void RemoveCoinFromArray(int32 NumCoinsToRemove);

	int32 GetCoinsLeftCount() const { return CoinsLeft; }

	FOnAllKeysAcquiredDelegate AllKeysAcquiredDelegate;
private:
	int32 CoinsLeft;
};
