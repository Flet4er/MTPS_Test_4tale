// Fill out your copyright notice in the Description page of Project Settings.


#include "TPS_GameMode.h"
#include "TimerManager.h"


void ATPS_GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	AllPlayerController.Add(NewPlayer);

	if(AllPlayerController.Num() >= 2)
	{
		if(!Once)
		{
			Once = true;
			StartMatch();
		}
	}
}

void ATPS_GameMode::StartMatch()
{

	Minutes = MatchTime_Minutes;
	Seconds = MatchTime_Seconds;

	GetWorld()->GetTimerManager().SetTimer(MatchTimerHandle, this, &ATPS_GameMode::TimerTick, 1, true);
	UE_LOG(LogTemp, Warning, TEXT("TimerStart"));
}

void ATPS_GameMode::TimerTick()
{
	UE_LOG(LogTemp, Warning, TEXT("TimerTick"));
	Seconds = Seconds - 1;

	if (Seconds < 0)
	{
		Minutes = Minutes - 1;
		Seconds = 59;
	}

	const int32 Num = AllPlayerController.Num();

	for (int32 i=0; i<Num; i++)
	{
		SendTimeToPawn(AllPlayerController[i], Minutes, Seconds);
		UE_LOG(LogTemp, Warning, TEXT("SendTimeToPawn"));
	}
	if (Seconds <= 0 && Minutes <= 0)
	{
		for (int32 i = 0; i < Num; i++)
		{
			GetWorld()->GetTimerManager().ClearTimer(MatchTimerHandle);
			MatchTimerHandle.Invalidate();

			SendEndMatch(AllPlayerController[i]);
			UE_LOG(LogTemp, Warning, TEXT("SendEndMatch"));
		}
	}
}
