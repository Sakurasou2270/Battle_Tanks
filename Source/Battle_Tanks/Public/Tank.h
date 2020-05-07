// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UWidget;

UCLASS()
class BATTLE_TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent *TankBody;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent *TankTop;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent *TankBarrel;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent *LTankTrack;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent *RTankTrack;

	// Only going to be used for yaw rotation
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent *SceneComp;

	// Only going to be used for pitch rotation
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent *SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent *Camera;

	UPROPERTY(EditDefaultsOnly, Category = "RotationSpeed")
	float RotationSpeed;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

protected:
	void MoveFoward(float Value);
	void Turn(float Value);
	void LookUp(float Value);
};
