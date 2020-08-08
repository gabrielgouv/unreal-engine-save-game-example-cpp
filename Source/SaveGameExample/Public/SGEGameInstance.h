// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGESaveGame.h"
#include "Engine/GameInstance.h"
#include "SGEGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SAVEGAMEEXAMPLE_API USGEGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	USGEGameInstance();

	UPROPERTY(BlueprintReadOnly)
	FString SaveGameSlotName;
	
	UPROPERTY(BlueprintReadWrite, Category = "Settings")
	USGESaveGame* SaveGameObject;

	UFUNCTION(BlueprintCallable, Category = "Game Manager")
	void LoadGame();

	UFUNCTION(BlueprintCallable, Category = "Game Manager")
	void SaveGame();

private:
	void LogIfGameWasSavedOrNot(const bool IsSaved);
};
