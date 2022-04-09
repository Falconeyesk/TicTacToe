// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn/MyPlayer.h"
#include "AI_Player.generated.h"

UCLASS()
class TICTACTOE_API AAI_Player : public AMyPlayer
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAI_Player();

	virtual void Move(int InBoard, int InAIState, int InPlayerState) override;

	int Minimax(int Alpha, int Beta, bool AIPlayer, int& NextMove, int depth);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	int Board;
	int AIState;
	int HumanState;

};
