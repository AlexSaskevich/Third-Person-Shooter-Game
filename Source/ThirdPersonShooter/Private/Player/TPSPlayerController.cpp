// Third Person Shooter Game, All Rights Reserved.

#include "Player/TPSPlayerController.h"
#include "Components/TPSRespawnComponent.h"

ATPSPlayerController::ATPSPlayerController()
{
    RespawnComponent = CreateDefaultSubobject<UTPSRespawnComponent>("RespawnComponent");
}
