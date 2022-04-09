// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWidget(int Choice, int PlayerIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void HighLight(int Winner);

	UFUNCTION(BlueprintImplementableEvent)
	void DarkerGrid(int Index);

	UFUNCTION(BlueprintImplementableEvent)
	void SetResultText(int Index);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ResetWidget();
	
	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION(BlueprintCallable)
	void ResetGame();
};
