// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLE_TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Override is forcing the compiler to check if BeginPlay function exists Within inheritance
	// Virtual is allowing the function when inherited to add more functionality to it
	// But virtual doesnt matter if it is there or not cause its already set in the offical file
	virtual void BeginPlay() override;
	ATank *GetControlledTank() const;
};
