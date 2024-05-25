// Fill out your copyright notice in the Description page of Project Settings.

#include "..\..\Public\GameModes\MW_GameMode.h"
#include "EngineUtils.h"
#include "Actors/MW_VictoryTriggerBox.h"
#include "GameState/MW_GameState.h"

void ADW_GameMode::BeginPlay()
{
	Super::BeginPlay();

	auto GS = GetGameState<AMW_GameState>();
	if (!GS) return;

	GS->AllKeysAcquiredDelegate.AddDynamic(this, &ThisClass::OpenDoors);
}

void ADW_GameMode::OpenDoors()
{
	for (TActorIterator<AMW_VictoryTriggerBox> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{
		if (!*ActorIterator) continue;

		ActorIterator->OpenDoor();
	}
}
