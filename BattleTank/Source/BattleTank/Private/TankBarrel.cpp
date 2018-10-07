// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RalativeSpeed)
{
	RalativeSpeed = FMath::Clamp<float>(RalativeSpeed, -1, +1);

	auto ElevationChange = RalativeSpeed * MaxDegeesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegees, MaxElevationDegees);

	SetRelativeRotation(FRotator(Elevation, 0.f, 0.f));
}