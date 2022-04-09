// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/MyPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "TicTacToeGameModeBase.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

}

void AMyPlayer::Move(int InBoard, int InAIState, int InPlayerState)
{

}

void AMyPlayer::SendMessage(int Choice)
{
	ATicTacToeGameModeBase* TicTacToeGameModeBase = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	TicTacToeGameModeBase->OnReceiveInput(Choice);
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

