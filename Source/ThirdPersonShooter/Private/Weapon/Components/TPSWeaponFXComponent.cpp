// Third Person Shooter Game, All Rights Reserved.

#include "Weapon/Components/TPSWeaponFXComponent.h"
#include "NiagaraFunctionLibrary.h"

UTPSWeaponFXComponent::UTPSWeaponFXComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTPSWeaponFXComponent::PlayImpactFX(const FHitResult& Hit)
{
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
}
