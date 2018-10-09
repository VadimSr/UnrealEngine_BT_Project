// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RalativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegeesPerSecond = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegees = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegees = 40.f;
};
