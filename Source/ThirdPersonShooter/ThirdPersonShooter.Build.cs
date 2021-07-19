// Third Person Shooter Game, All Rights Reserved.

using UnrealBuildTool;

public class ThirdPersonShooter : ModuleRules
{
    public ThirdPersonShooter(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        { "Core",
          "CoreUObject",
          "Engine",
          "InputCore",
          "Niagara",
          "PhysicsCore",
          "GameplayTasks",
          "NavigationSystem"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.AddRange(new string[]
        {
            "ThirdPersonShooter/Public/Player",
            "ThirdPersonShooter/Public/Components",
            "ThirdPersonShooter/Public/Dev",
            "ThirdPersonShooter/Public/Weapon",
            "ThirdPersonShooter/Public/UI",
            "ThirdPersonShooter/Public/Animations",
            "ThirdPersonShooter/Public/Pickups",
            "ThirdPersonShooter/Public/Weapon/Components",
            "ThirdPersonShooter/Public/AI",
            "ThirdPersonShooter/Public/AI/Tasks",
            "ThirdPersonShooter/Public/AI/Services",
            "ThirdPersonShooter/Public/AI/EQS",
            "ThirdPersonShooter/Public/AI/Decorators"
        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
