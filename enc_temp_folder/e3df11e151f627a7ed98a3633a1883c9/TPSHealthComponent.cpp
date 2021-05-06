// Third Person Shooter Game, All Rights Reserved.

#include "Components/TPSHealthComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, Display, Display);

UTPSHealthComponent::UTPSHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTPSHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    check(MaxHealth > 0);

    SetHealth(MaxHealth);

    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UTPSHealthComponent::OnTakeAnyDamage);
    }
}

void UTPSHealthComponent::OnTakeAnyDamage(
    AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || IsDead() || !GetWorld()) return;

    SetHealth(Health - Damage);

    GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);

    if (IsDead())
    {
        OnDeath.Broadcast();
    }
    else if (AutoHeal)
    {
        GetWorld()->GetTimerManager().SetTimer(HealTimerHandle, this, &UTPSHealthComponent::HealUpdate, HealUpdateTime, true, HealDelay);
    }
}

void UTPSHealthComponent::HealUpdate()
{
    SetHealth(Health + HealModifier);

    if (FMath::IsNearlyEqual(Health, MaxHealth) && GetWorld())
    {
        GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
    }
}

void UTPSHealthComponent::SetHealth(float NewHealth)
{
    Health = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(Health);
}

bool UTPSHealthComponent::IsHealthFull() const
{
    return MaxHealth == 100.0f;
}

bool UTPSHealthComponent::TryToAddHealth(int32 HealthAmount)
{
    if (IsHealthFull())
    {
        return false;
    }
    else
    {
        UE_LOG(LogHealthComponent, Display, TEXT("Health was taken!"));
        return true;
    }
}
