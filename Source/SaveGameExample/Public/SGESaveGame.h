// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGEPlayerStatusEnum.h"
#include "GameFramework/SaveGame.h"
#include "UObject/ObjectMacros.h"

#include "SGESaveGame.generated.h"

/**
 * 
 */
UCLASS()
class SAVEGAMEEXAMPLE_API USGESaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	USGESaveGame();
	
	UPROPERTY(BlueprintReadWrite, Category="Player Info")
	FString PlayerName;

	UPROPERTY(BlueprintReadWrite, Category="Player Info")
	int32 PlayerAge;

	UPROPERTY(BlueprintReadWrite, Category="Player Info")
	EPlayerStatus PlayerStatus;
	
};
