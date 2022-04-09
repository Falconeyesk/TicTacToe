// Copyright Epic Games, Inc. All Rights Reserved.


#include "TicTacToeGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameRulesUtilis.h"

void ATicTacToeGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// Create Background Menu
	BackgroundUI = CreateWidget<UMyUserWidget>(GetWorld(), BGWidgetClass);
	BackgroundUI->AddToViewport();

	// Create Startup Menu
	StartUI = CreateWidget<UMyUserWidget>(GetWorld(), StartWidgetClass);
	StartUI->AddToViewport();

	ResultUI = CreateWidget<UMyUserWidget>(GetWorld(), ResultWidgetClass);
}

void ATicTacToeGameModeBase::StartGame()
{
	// Init Board
	Init();

	// CreatePlayer
	AllPlayers.Emplace(Cast<AMyPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)));
	AllPlayers.Emplace(GetWorld()->SpawnActor<AMyPlayer>(AIClass, FVector(0), FRotator(0)));

	BoardUI = CreateWidget<UMyUserWidget>(GetWorld(), BoardWidgetClass);
	BoardUI->AddToViewport();

	//NextPlayer = UKismetMathLibrary::RandomInteger(PlayerNum);
	// Human Player First
	NextPlayer = 0;
	NextTurn();
}

void ATicTacToeGameModeBase::Reset()
{
	ResultUI->RemoveFromParent();
	Init();
	BoardUI->ResetWidget();
	NextPlayer = 0;
	NextTurn();
}

void ATicTacToeGameModeBase::NextTurn()
{
	AllPlayers[NextPlayer]->Move(Board, AIMove, HumanMove);
}

void ATicTacToeGameModeBase::OnReceiveInput(int PlayerChoice)
{
	// Make Move
	if (NextPlayer == 0)
	{
		HumanMove = HumanMove + (1 << PlayerChoice);
	}
	else
	{
		AIMove = AIMove + (1 << PlayerChoice);
	}

	Board = (1 << PlayerChoice) + Board;

	BoardUI->UpdateWidget(PlayerChoice, NextPlayer);
	
	int WinLine = -1;

	// Check Game State
	int Result = UGameRulesUtilis::CheckWinner(Board, AIMove, HumanMove, WinLine);
	switch (Result)
	{
	case 1:
		HighLight(WinLine, NextPlayer);
		ResultUI->SetResultText(1);
		ResultUI->AddToViewport();
		break;
	case 2:
		HighLight(WinLine, NextPlayer);
		ResultUI->SetResultText(2);
		ResultUI->AddToViewport();
		break;
	case 3:
		ResultUI->SetResultText(3);
		ResultUI->AddToViewport();
		break;
	default:
		// Switch to Next Player
		NextPlayer = (NextPlayer + 1) % PlayerNum;
		NextTurn();
	}
}

void ATicTacToeGameModeBase::Init()
{
	Board = 0;
	AIMove = 0;
	HumanMove = 0;
}

// High Win Grid
void ATicTacToeGameModeBase::HighLight(int Line, int Winner)
{
	for (int i = 0; i < 9; ++i)
	{
		if (((Line >> i) & 1) != 1)
		{
			BoardUI->DarkerGrid(i);
		}
	}
	BoardUI->HighLight(Winner);
}