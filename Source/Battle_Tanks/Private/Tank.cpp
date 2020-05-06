// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBody"));
	TankBody->SetSimulatePhysics(true);
	RootComponent = TankBody;

	TankTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankTop"));
	TankTop->SetupAttachment(TankBody, TEXT("Turret"));

	TankBarrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBarrel"));
	TankBarrel->SetupAttachment(TankTop, TEXT("Turret"));

	LTankTrack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LTankTrack"));
	LTankTrack->SetupAttachment(TankBody, TEXT("L_Track"));

	RTankTrack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RTankTrack"));
	RTankTrack->SetupAttachment(TankBody, TEXT("R_Track"));

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Gyroscope"));
	SceneComp->SetupAttachment(TankBody);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(SceneComp);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	RotationSpeed = 15.f;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &ATank::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ATank::LookUp);
	PlayerInputComponent->BindAxis("MoveFoward", this, &ATank::MoveFoward);
}

void ATank::MoveFoward(float Value)
{
	if (Value != 0.f)
	{
		TankBody->AddImpulse(FVector(250.f), NAME_None, true);
	}
}

void ATank::Turn(float Value)
{
	SceneComp->AddLocalRotation(FRotator(0.f, Value, 0.f) * RotationSpeed);
}

void ATank::LookUp(float Value)
{
	SpringArm->AddLocalRotation(FRotator(Value, 0.f, 0.f) * RotationSpeed);
}