// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class IGCacheSimLibrary : ModuleRules
{
	public IGCacheSimLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			//PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("CacheSim.dll");
            PublicDelayLoadDLLs.Add("udis86.dll");

            // Ensure that the DLL is staged along with the executable
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/IGCacheSimLibrary/Win64/CacheSim.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/IGCacheSimLibrary/Win64/udis86.dll");
        }
	}
}
