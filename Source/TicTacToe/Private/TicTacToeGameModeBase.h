// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Pawn/MyPlayer.h"
#include "Widget/MyUserWidget.h"
#include "TicTacToeGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATicTacToeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AMyPlayer> AIClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMyUserWidget> BoardWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMyUserWidget> BGWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMyUserWidget> StartWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMyUserWidget> ResultWidgetClass;

public:
	virtual void BeginPlay() override;
	void NextTurn();
	void Init();
	void OnReceiveInput(int PlayerChoice);
	void StartGame();
	void Reset();

private:
	TArray<AMyPlayer*> AllPlayers;

	UPROPERTY()
	UMyUserWidget* BackgroundUI;

	UPROPERTY()
	UMyUserWidget* BoardUI;

	UPROPERTY()
	UMyUserWidget* StartUI;

	UPROPERTY()
	UMyUserWidget* ResultUI;

	int NextPlayer = 0;
	int PlayerNum = 2;
	int Board = 0;
	int AIMove = 0;
	int HumanMove = 0;
	
	void HighLight(int Line, int Winner);
};
