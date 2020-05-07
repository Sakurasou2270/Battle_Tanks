// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    // if (GetAIController())
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("AI Tank %s"), *GetAIController()->GetName())
    // }
    // else
    // {
    //     UE_LOG(LogTemp, Error, TEXT("Not Possessing"));
    // }

    // if (GetPlayerTank())
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("Player Tank %s"), *GetPlayerTank()->GetActorLocation().ToString());
    // }
    // else
    // {
    //     UE_LOG(LogTemp, Error, TEXT("Not Possessing"));
    // }
}

ATank *ATankAIController::GetAIController() const
{
    return Cast<ATank>(GetPawn());
}

ATank *ATankAIController::GetPlayerTank() const
{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}