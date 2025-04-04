using UnrealBuildTool;

public class ExampleEditor : ModuleRules
{
    public ExampleEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
            }
        );
				
		
        PrivateIncludePaths.AddRange(
            new string[] {
                "ExampleEditor",
                "ExampleRuntime"
            }
        );
			
		
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", 
                "ExampleRuntime", 
                "Blutility"
            }
        );
			
		
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "UnrealEd",
                "AssetDefinition"
            }
        );
		
		
        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
            }
        );
    }
}