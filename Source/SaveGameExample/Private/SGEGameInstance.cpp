// Fill out your copyright notice in the Description page of Project Settings.


#include "SGEGameInstance.h"

#include "Kismet/GameplayStatics.h"

USGEGameInstance::USGEGameInstance()
{
    SaveGameSlotName = "SaveGameExample";
}

void USGEGameInstance::LoadGame()
{
    USaveGame* LoadedGame = UGameplayStatics::LoadGameFromSlot(SaveGameSlotName, 0);
    SaveGameObject = Cast<USGESaveGame>(LoadedGame);

    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Trying to load a saved game."));
    
    if (!SaveGameObject)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("No saved games found. Trying to save a new one."));
        
        SaveGameObject = NewObject<USGESaveGame>();
        const bool IsSaved = UGameplayStatics::SaveGameToSlot(SaveGameObject, SaveGameSlotName, 0);

        LogIfGameWasSavedOrNot(IsSaved);
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Saved game found. Loaded."));
    }
    
}

void USGEGameInstance::SaveGame()
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Saving game..."));
    
    const bool IsSaved = UGameplayStatics::SaveGameToSlot(SaveGameObject, SaveGameSlotName, 0);

    LogIfGameWasSavedOrNot(IsSaved);
    
}

void USGEGameInstance::LogIfGameWasSavedOrNot(const bool IsSaved)
{
    if (IsSaved)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Game saved."));
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Cannot save the game."));
    }
}
