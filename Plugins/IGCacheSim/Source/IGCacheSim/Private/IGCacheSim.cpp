// Copyright Epic Games, Inc. All Rights Reserved.

#include "IGCacheSim.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FIGCacheSimModule"

void FIGCacheSimModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("IGCacheSim")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/IGCacheSimLibrary/Win64/CacheSim.dll"));
#endif // PLATFORM_WINDOWS
	const FString DllExtraPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/IGCacheSimLibrary/Win64"));
	FPlatformProcess::AddDllDirectory(*DllExtraPath);
	CacheSimHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (CacheSimHandle != nullptr)
	{
		cachesim = new CacheSim::DynamicLoader();
		if (!cachesim->Init())
		{
			delete cachesim;
			cachesim = nullptr;
			return;
		}
	}
}

void FIGCacheSimModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (cachesim != nullptr)
	{
		delete cachesim;
		cachesim = nullptr;
	}
	if (CacheSimHandle != nullptr)
	{
		// Free the dll handle
		FPlatformProcess::FreeDllHandle(CacheSimHandle);
		CacheSimHandle = nullptr;
	}
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FIGCacheSimModule, IGCacheSim)

void FIGCacheSimModule::SetThreadCoreMapping()
{
#if PLATFORM_WINDOWS
	cachesim->SetThreadCoreMapping(cachesim->GetCurrentThreadId(), 0);
#endif
}

void FIGCacheSimModule::StartCacheSim()
{
#if PLATFORM_WINDOWS
	SetThreadCoreMapping();
	cachesim->Start();
#endif
}

void FIGCacheSimModule::StopCacheSim()
{
#if PLATFORM_WINDOWS
	cachesim->End();
#endif
}