// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameMode_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameMode_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MTPS_TEST_4TALE_API IGameMode_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GetAllPlayerControllerInGame(TArray<APlayerController*> &AllPlayerController);
};
