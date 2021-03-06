// Third Person Shooter Game, All Rights Reserved.

#include "Components/TPSRespawnComponent.h"
#include "TPSGameModeBase.h"

UTPSRespawnComponent::UTPSRespawnComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTPSRespawnComponent::Respawn(int32 RespawnTime)
{
    if (!GetWorld()) return;

    RespawnCountDown = RespawnTime;
    GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &UTPSRespawnComponent::RespawnTimerUpdate, 1.0f, true);
}

void UTPSRespawnComponent::RespawnTimerUpdate()
{
    if (--RespawnCountDown == 0)
    {
        if (!GetWorld()) return;
        GetWorld()->GetTimerManager().ClearTimer(RespawnTimerHandle);

        const auto GameMode = Cast<ATPSGameModeBase>(GetWorld()->GetAuthGameMode());
        if (!GameMode) return;

        GameMode->RespawnRequest(Cast<AController>(GetOwner()));
    }
}

bool UTPSRespawnComponent::IsRespawnInProgress() const
{
    return GetWorld() && GetWorld()->GetTimerManager().IsTimerActive(RespawnTimerHandle);
}
