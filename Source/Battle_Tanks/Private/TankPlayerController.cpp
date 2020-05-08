// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "DrawDebugHelpers.h"

ATankPlayerController::ATankPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // AimTowardsCrossHair();
    FVector Location;
    GetSightRayHitLocation(Location);
    UE_LOG(LogTemp, Warning, TEXT("%s"), *Location.ToString());
}

ATank *ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
    if (!GetControlledTank())
    {
        return;
    }

    FVector HitLocation;

    if (GetSightRayHitLocation(HitLocation))
    {
        GetControlledTank()->AimAt(HitLocation);
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);

    const FVector2D ViewportCenter = FVector2D(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);

    FVector WorldLocation, WorldDirection;
    bool GetLookDirection = DeprojectScreenPositionToWorld(ViewportCenter.X, ViewportCenter.Y, WorldLocation, WorldDirection);

    //* Line Tracing Out
    FHitResult Hit;
    FVector Start = PlayerCameraManager->GetCameraLocation();
    // Begin at start location and figure out what the range is
    FVector End = Start + (WorldDirection * LineTraceRange);
    FCollisionQueryParams Params;
    DrawDebugLine(GetWorld(), Start, End, FColor::Purple, true, 0, 0, 5.f);

    // if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
    // {
    //     OutHitLocation = Hit.Location;
    //     return true;
    // }
    // OutHitLocation = FVector(0.f);
    // return false;
    OutHitLocation = WorldDirection;
    return true;
}