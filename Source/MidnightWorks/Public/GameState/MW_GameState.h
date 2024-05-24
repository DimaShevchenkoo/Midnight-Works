// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MW_GameState.generated.h"

class AMW_Coin;

UCLASS()
class MIDNIGHTWORKS_API AMW_GameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	void AddCoinToArray(AMW_Coin* CoinToAdd);
	void RemoveCoinFromArray(AMW_Coin* CoinToRemove);

	int32 GetCoinsArraySize() { return CoinsArray.Max(); }

private:
	TArray<AMW_Coin*> CoinsArray;
};
