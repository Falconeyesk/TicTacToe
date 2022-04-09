// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/MyPlayerController.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}