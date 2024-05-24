// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MW_PlayerController.generated.h"

class AMW_HUD;
class AMW_PlayerCharacter;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS()
class MIDNIGHTWORKS_API AMW_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void DecreaseCoinsCountTextBlockValue(int32 NumToDecrease);

protected:
	void Move(const FInputActionValue& Value);
	void RotateCamera(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);
	void StopJumping(const FInputActionValue& Value);

	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	UInputMappingContext* DefaultIMC;

	UPROPERTY(EditAnywhere)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere)
	UInputAction* CameraAction;
	
	UPROPERTY(EditAnywhere)
	UInputAction* JumpAction;

	UPROPERTY()
	AMW_PlayerCharacter* PlayerCharacter;

	UPROPERTY()
	AMW_HUD* HUD;
};
