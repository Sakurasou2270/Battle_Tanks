// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // if (Cast<ATank>(GetPawn()))
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("%s"), *GetControlledTank()->GetName());
    // }
}

ATank *ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}