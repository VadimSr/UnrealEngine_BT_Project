// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RalativeSpeed)
{
	RalativeSpeed = FMath::Clamp<float>(RalativeSpeed, -1, +1);

	auto ElevationChange = RalativeSpeed * MaxDegeesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;

	SetRelativeRotation(FRotator(0.f, RawNewElevation, 0.f));
}

