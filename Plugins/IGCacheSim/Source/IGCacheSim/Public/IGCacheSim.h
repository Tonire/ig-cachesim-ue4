// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

#include "IGCacheSimLibrary/CacheSim/CacheSim.h"

class FIGCacheSimModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FIGCacheSimModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FIGCacheSimModule>("IGCacheSim");
	}

	void SetThreadCoreMapping();
	void StartCacheSim();
	void StopCacheSim();

private:
	/** Handle to the test dll we will load */
	void* CacheSimHandle;

	CacheSim::DynamicLoader* cachesim;
};
