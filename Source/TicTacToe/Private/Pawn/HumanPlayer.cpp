// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/HumanPlayer.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHumanPlayer::AHumanPlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHumanPlayer::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//DisableInput(PlayerController);
}

// Called every frame
void AHumanPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHumanPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AHumanPlayer::Move(int InBoard, int InAIState, int InPlayerState)
{
	EnableInput(PlayerController);
}