// Third Person Shooter Game, All Rights Reserved.

#include "UI/TPSPlayerHUDWidget.h"
#include "Components/TPSHealthComponent.h"
#include "Components/TPSWeaponComponent.h"

float UTPSPlayerHUDWidget::GetHealthPercent() const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return 0.0f;

    const auto Component = Player->GetComponentByClass(UTPSHealthComponent::StaticClass());
    const auto HealthComponent = Cast<UTPSHealthComponent>(Component);
    if (!HealthComponent) return 0.0f;

    return HealthComponent->GetHealthPercent();
}

bool UTPSPlayerHUDWidget::GetCurrentWeaponUIData(FWeaponUIData& UIData) const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return false;

    const auto Component = Player->GetComponentByClass(UTPSWeaponComponent::StaticClass());
    const auto WeaponComponent = Cast<UTPSWeaponComponent>(Component);
    if (!WeaponComponent) return false;

    return WeaponComponent->GetCurrentWeaponUIData(UIData);
}

bool UTPSPlayerHUDWidget::GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return false;

    const auto Component = Player->GetComponentByClass(UTPSWeaponComponent::StaticClass());
    const auto AmmoComponent = Cast<UTPSWeaponComponent>(Component);
    if (!AmmoComponent) return false;

    return AmmoComponent->GetCurrentWeaponAmmoData(AmmoData);
}
