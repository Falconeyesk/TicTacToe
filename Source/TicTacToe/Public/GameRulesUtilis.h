// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameRulesUtilis.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UGameRulesUtilis : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static int CheckWinner(int CheckBoard, int AIState, int PlayerState, int& WinLine);
	
private:
	static const int WinState[8];
};
