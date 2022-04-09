// Fill out your copyright notice in the Description page of Project Settings.


#include "GameRulesUtilis.h"

const int UGameRulesUtilis::WinState[8] = { 7,56,448,73,146,292,273,84 };

int UGameRulesUtilis::CheckWinner(int CheckBoard, int AIState, int PlayerState, int& WinLine)
{
	for (auto State : WinState)
	{
		if ((AIState & State) == State)
		{
			WinLine = State;
			return 1;
		}
		if ((PlayerState & State) == State)
		{
			WinLine = State;
			return 2;
		}
	}
	if (CheckBoard == 511)
	{
		return 3;
	}
	return 0;
}