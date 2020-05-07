// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"

ATankPlayerController::ATankPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // if (Cast<ATank>(GetPawn()))
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("%s"), *GetControlledTank()->GetName());
    // }
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AimTowardsCrossHair();
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
        UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString());
    }
    // get world location to crosshair
    // linetrace it maybe??
    // if hits the landscape
    // tell controlled tank to aim at that point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    // const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
    // const FVector2D ViewportCenter = FVector2D(ViewportSize.X / 2, ViewportSize.Y / 2);
    const FVector2D ViewportCenter = FVector2D(CrossHairXLocation, CrossHairYLocation);

    FVector WorldLocation, WorldDirection;
    bool GetLookDirection = DeprojectScreenPositionToWorld(ViewportCenter.X, ViewportCenter.Y, WorldLocation, WorldDirection);

    //* Line Tracing Out
    FHitResult Hit;
    FVector Start = PlayerCameraManager->GetCameraLocation();
    // Begin at start location and figure out what the range is
    FVector End = Start + (WorldDirection * LineTraceRange);
    FCollisionQueryParams Params;
    if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
    {
        if (Hit.bBlockingHit)
        {
            UE_LOG(LogTemp, Warning, TEXT("%s"), *Hit.Location.ToString());
            OutHitLocation = Hit.Location;
            return true;
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("Something Else"));
    OutHitLocation = FVector(0.f);
    return false;
}