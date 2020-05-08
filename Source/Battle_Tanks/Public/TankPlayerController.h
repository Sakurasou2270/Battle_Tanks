// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
class ATank;

UCLASS()
class BATTLE_TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATankPlayerController();

	// Override is forcing the compiler to check if BeginPlay function exists Within inheritance
	// Virtual is allowing the function when inherited to add more functionality to it
	// But virtual doesnt matter if it is there or not cause its already set in the offical file
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "UI")
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere, Category = "UI")
	float CrossHairYLocation = 0.35;

	// cm
	UPROPERTY(EditAnywhere, Category = "UI")
	float LineTraceRange = 1000000.f;

	ATank *GetControlledTank() const;
	// Moving barrel towards crosshair
	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
};
