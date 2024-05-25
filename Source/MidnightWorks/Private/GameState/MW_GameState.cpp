// Fill out your copyright notice in the Description page of Project Settings.

#include "GameState/MW_GameState.h"

void AMW_GameState::AddCoinToArray(int32 NumCoinsToAdd)
{
	CoinsLeft += NumCoinsToAdd;
}

void AMW_GameState::RemoveCoinFromArray(int32 NumCoinsToRemove)
{
	CoinsLeft -= NumCoinsToRemove;

	if (CoinsLeft <= 0)
	{
		AllKeysAcquiredDelegate.Broadcast();
	}
}
