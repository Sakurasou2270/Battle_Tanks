// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBody"));
	RootComponent = TankBody;

	TankTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankTop"));
	TankTop->SetupAttachment(TankBody);

	TankBarrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBarrel"));
	TankBarrel->SetupAttachment(TankTop);

	LTankTrack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LTankTrack"));
	LTankTrack->SetupAttachment(TankBody);

	RTankTrack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RTankTrack"));
	RTankTrack->SetupAttachment(TankBody);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm->SetupAttachment(SpringArm);
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
}
