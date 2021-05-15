// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IGCacheSimBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class IGCACHESIM_API UIGCacheSimBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static void StartCacheSimulation();

	UFUNCTION(BlueprintCallable)
	static void StopCacheSimulation();
	
};
