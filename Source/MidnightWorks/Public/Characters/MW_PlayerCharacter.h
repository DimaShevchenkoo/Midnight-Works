// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MW_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class MIDNIGHTWORKS_API AMW_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMW_PlayerCharacter();

	FVector GetSpawnLocation() const { return StartPosition; }

	void SetJumpBoosterInUse(const bool bInUse) { bJumpBoosterInUse = bInUse; }
	void SetSpeedBoosterInUse(const bool bInUse) { bSpeedBoosterInUse = bInUse; }

	bool GetJumpBoosterInUse() const { return bJumpBoosterInUse; }
	bool GetSpeedBoosterInUse() const { return bSpeedBoosterInUse; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* CameraComponent;

	FVector StartPosition;

	bool bJumpBoosterInUse = false;
	bool bSpeedBoosterInUse = false;
};
