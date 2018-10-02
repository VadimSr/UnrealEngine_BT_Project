// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PC = GetPlayerTank();

	if (PC)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI pointing at %s."), *PC->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI pointing at nothing."));
	}
}

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto APC = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!APC)
	{
		return nullptr;
	}

	return Cast<ATank>(APC);
}