// Third Person Shooter Game, All Rights Reserved.

#include "TPSGameModeBase.h"
#include "Player/TPSBaseCharacter.h"
#include "Player/TPSPlayerController.h"
#include "UI/TPSGameHUD.h"
#include "AIController.h"

ATPSGameModeBase::ATPSGameModeBase()
{
    DefaultPawnClass = ATPSBaseCharacter::StaticClass();
    PlayerControllerClass = ATPSPlayerController::StaticClass();
    HUDClass = ATPSGameHUD::StaticClass();
}

void ATPSGameModeBase::StartPlay()
{
    Super::StartPlay();

    SpawnBots();
}

UClass* ATPSGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
    if (InController && InController->IsA<AAIController>())
    {
        return AIPawnClass;
    }
    return Super::GetDefaultPawnClassForController_Implementation(InController);
}

void ATPSGameModeBase::SpawnBots()
{
    if (!GetWorld()) return;

    for (int32 i = 0; i < GameData.PlayersNum - 1; ++i)
    {
        FActorSpawnParameters SpawnInfo;
        SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        const auto TPSAIController = GetWorld()->SpawnActor<AAIController>(AIControllerClass, SpawnInfo);

        RestartPlayer(TPSAIController);
    }
}
