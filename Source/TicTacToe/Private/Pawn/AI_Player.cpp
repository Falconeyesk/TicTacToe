// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/AI_Player.h"
#include "Kismet/KismetMathLibrary.h"
#include "TicTacToeGameModeBase.h"
#include "GameRulesUtilis.h"
#include <limits.h>
#include <algorithm>

// Sets default values
AAI_Player::AAI_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI_Player::Move(int InBoard, int InAIState, int InPlayerState)
{
	// Start AI Algorithm
	Board = InBoard;
	AIState = InAIState;
	HumanState = InPlayerState;
	int Choice = -1;
	if (Board == 0)
	{
		Choice = UKismetMathLibrary::RandomInteger(9);
	}
	else
	{
		Minimax(INT_MIN, INT_MAX, true, Choice, 10);
	}
	SendMessage(Choice);
}

int AAI_Player::Minimax(int Alpha, int Beta, bool AIPlayer, int& NextMove, int depth)
{
	// Return End Value
	int Temp = -1;
	int Result = UGameRulesUtilis::CheckWinner(Board, AIState, HumanState, Temp);
	switch (Result)
	{
	case 1:
		return 10 * depth;
	case 2:
		return -10 * depth;
	case 3:
		return 0;
	default:
		break;
	}

	if (AIPlayer)
	{
		// AI Step : Find Max Value
		int MaxEval = INT_MIN;
		int BestMove = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (((Board >> i) & 1) != 1)
			{
				// Make Move
				Board = Board + (1 << i);
				AIState = AIState + (1 << i);

				int Eval = Minimax(Alpha, Beta, false, NextMove, depth - 1);

				// Undo Move
				Board = Board - (1 << i);
				AIState = AIState - (1 << i);

				if (Eval > MaxEval)
				{
					MaxEval = Eval;
					BestMove = i;
				}
				Alpha = std::max(Alpha, Eval);
				if (Beta <= Alpha)
				{
					break;
				}
			}
		}
		NextMove = BestMove;
		return MaxEval;
	}
	else
	{
		// Human Step : Find Min Value
		int MinEval = INT_MAX;
		int BestMove = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (((Board >> i) & 1) != 1)
			{
				// Make Move
				Board = Board + (1 << i);
				HumanState = HumanState + (1 << i);

				int Eval = Minimax(Alpha, Beta, true, NextMove, depth - 1);

				// Undo Move
				Board = Board - (1 << i);
				HumanState = HumanState - (1 << i);

				if (Eval < MinEval)
				{
					MinEval = Eval;
					BestMove = i;
				}
				Beta = std::min(Beta, Eval);
				if (Beta <= Alpha)
				{
					break;
				}
			}
		}
		NextMove = BestMove;
		return MinEval;
	}
}

