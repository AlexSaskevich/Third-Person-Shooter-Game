// Third Person Shooter Game, All Rights Reserved.

#include "UI/TPSPlayerHUDWidget.h"
#include "Components/TPSHealthComponent.h"

float UTPSPlayerHUDWidget::GetHealthPercent() const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return 0.0f;

    const auto Component = Player->GetComponentByClass(UTPSHealthComponent::StaticClass());
    const auto HealthComponent = Cast<UTPSHealthComponent>(Component);
    if (!HealthComponent) return 0.0f;

    return HealthComponent->GetHealthPercent();
}
