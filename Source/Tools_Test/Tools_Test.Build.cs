// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tools_Test : ModuleRules
{
	public Tools_Test(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", "CoreUObject", "Engine", "InputCore", 
			"HeadMountedDisplay", "EnhancedInput", "UMG"
		});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...
				//"EditorFramework",
				"UnrealEd",
				//"Projects"
			}
			);
	}
}
