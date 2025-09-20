// Pavel Penkov 2025 All Rights Reserved.

using UnrealBuildTool;

public class UHLBehaviorTreesEditor : ModuleRules
{
	public UHLBehaviorTreesEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"PropertyEditor",
				"Blutility",
				"UMG", 
				
				"BehaviorTreeEditor", 
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Projects",
				"InputCore",
				"EditorFramework",
				"UnrealEd",
				"ToolMenus",
				"Slate",
				"SlateCore",
				"UnrealEd",
				"DeveloperSettings", 
				
				"EditorWidgets", 
				
				"GameplayTagsEditor",
			}
			);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
