// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/MW_PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/MW_PlayerCharacter.h"
#include "HUD/MW_HUD.h"

void AMW_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		PlayerSubsystem->AddMappingContext(DefaultIMC, 0);
	}
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
		EIC->BindAction(CameraAction, ETriggerEvent::Triggered, this, &ThisClass::RotateCamera);
		EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::Jump);
		EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::StopJumping);
	}
}

void AMW_PlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (GetPawn())
	{
		GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
		GetPawn()->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AMW_PlayerController::RotateCamera(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void AMW_PlayerController::Jump(const FInputActionValue& Value)
{
	PlayerCharacter = PlayerCharacter ? PlayerCharacter : Cast<AMW_PlayerCharacter>(GetPawn());
	if (!PlayerCharacter) return;

	PlayerCharacter->Jump();
}

void AMW_PlayerController::StopJumping(const FInputActionValue& Value)
{
	PlayerCharacter = PlayerCharacter ? PlayerCharacter : Cast<AMW_PlayerCharacter>(GetPawn());
	if (!PlayerCharacter) return;

	PlayerCharacter->StopJumping();
}

void AMW_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetShowMouseCursor(false);

	FInputModeGameOnly GameOnly;
	SetInputMode(GameOnly);
}

void AMW_PlayerController::DecreaseCoinsCountTextBlockValue(int32 NumToDecrease)
{
	HUD = HUD ? HUD : GetHUD<AMW_HUD>();
	if (!HUD) return;

	HUD->DecreaseCoinsCountTextBlockValue(NumToDecrease);

	if (HUD->GetCoinCountValue() <= 0)
	{
		HUD->CreateVictoryWidget();

		SetShowMouseCursor(true);
		FInputModeUIOnly UIOnly;
		SetInputMode(UIOnly);
	}
}
