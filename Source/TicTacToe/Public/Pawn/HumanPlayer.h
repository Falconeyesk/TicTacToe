// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn/MyPlayer.h"

#include "HumanPlayer.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API AHumanPlayer : public AMyPlayer
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHumanPlayer();

	virtual void Move(int InBoard, int InAIState, int InPlayerState) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	APlayerController* PlayerController;
	
};
