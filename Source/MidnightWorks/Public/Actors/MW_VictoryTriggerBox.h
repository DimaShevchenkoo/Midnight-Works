// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MW_VictoryTriggerBox.generated.h"

class UBoxComponent;

UCLASS()
class MIDNIGHTWORKS_API AMW_VictoryTriggerBox : public AActor
{
	GENERATED_BODY()
	
public:	
	AMW_VictoryTriggerBox();

	void OpenDoor();

protected:
	UFUNCTION()
	void EndGameTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* EndGameTriggerBox;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DoorMeshComponent;
};
