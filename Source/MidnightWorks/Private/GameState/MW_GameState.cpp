// Fill out your copyright notice in the Description page of Project Settings.

#include "GameState/MW_GameState.h"

void AMW_GameState::AddCoinToArray(AMW_CoinPickup* CoinToAdd)
{
	if (CoinToAdd)
	{
		CoinsArray.AddUnique(CoinToAdd);
	}
}

void AMW_GameState::RemoveCoinFromArray(AMW_CoinPickup* CoinToRemove)
{
	if (CoinToRemove)
	{
		CoinsArray.Remove(CoinToRemove);
	}
}
