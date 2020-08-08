// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SGEPlayerStatusEnum.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EPlayerStatus : uint8
{
    PS_Alive        UMETA(DisplayName = "Alive"),
    PS_Dead         UMETA(DisplayName = "Dead")
};
