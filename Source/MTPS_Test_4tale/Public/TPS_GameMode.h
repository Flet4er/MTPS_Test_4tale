// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPS_GameMode.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MTPS_TEST_4TALE_API ATPS_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default"/*, Replicated*/)
	TArray<APlayerController*> AllPlayerController;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	bool Once;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	int32 Seconds;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	int32 Minutes;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	int32 MatchTime_Minutes = 5;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	int32 MatchTime_Seconds;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	FTimerHandle MatchTimerHandle;


	virtual void PostLogin(APlayerController* NewPlayer);

	void StartMatch();

	void TimerTick();

	UFUNCTION(BlueprintImplementableEvent)
	void SendTimeToPawn(const APlayerController* exController, const int32 exMinutes, const int32 exSeconds);

	UFUNCTION(BlueprintImplementableEvent)
	void SendEndMatch(const APlayerController* exController);
};
