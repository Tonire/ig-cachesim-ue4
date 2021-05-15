// Fill out your copyright notice in the Description page of Project Settings.


#include "IGCacheSimBlueprintLibrary.h"

#include "IGCacheSim.h"


void UIGCacheSimBlueprintLibrary::StartCacheSimulation()
{
#if PLATFORM_WINDOWS
	FIGCacheSimModule::Get().StartCacheSim();
#endif
}

void UIGCacheSimBlueprintLibrary::StopCacheSimulation()
{
#if PLATFORM_WINDOWS
	FIGCacheSimModule::Get().StopCacheSim();
#endif
}
