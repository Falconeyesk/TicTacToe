// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/MyUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TicTacToeGameModeBase.h"

void UMyUserWidget::StartGame()
{
	ATicTacToeGameModeBase* TicTacToeGameModeBase = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	TicTacToeGameModeBase->StartGame();
}

void UMyUserWidget::ResetGame()
{
	ATicTacToeGameModeBase* TicTacToeGameModeBase = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	TicTacToeGameModeBase->Reset();
}