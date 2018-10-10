// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"

#include "Engine/World.h"

void UTankTracks::SetThrottle(float Throttle)
{
	auto Time = GetWorld()->GetRealTimeSeconds();
	auto Name = GetName();

	UE_LOG(LogTemp, Warning, TEXT("%f: %s are moving %f"), Time, *Name, Throttle);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
