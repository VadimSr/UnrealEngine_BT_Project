// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector OutHitLocation)
{
	TankAimingComponent->AimAt(OutHitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet); \
	LocalBarrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();

	if (!LocalBarrel) { return; }

	auto ProjectileSpawnLocation = LocalBarrel->GetSocketLocation(FName("Projectile"));
	auto ProjectileSpawnRotation = LocalBarrel->GetSocketRotation(FName("Projectile"));

	GetWorld()->SpawnActor<AProjectile>(ProjectileBP, ProjectileSpawnLocation, ProjectileSpawnRotation);
}