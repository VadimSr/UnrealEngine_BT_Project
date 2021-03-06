// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float AcceptanceRadius = 3000.f;
};
