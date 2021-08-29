// Third Person Shooter Game, All Rights Reserved.

#include "Player/TPSBaseCharacter.h"
#include "Components/TPSCharacterMovementComponent.h"
#include "Components/TPSHealthComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/TPSWeaponComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseCharacter, Display, Display);

ATPSBaseCharacter::ATPSBaseCharacter(const FObjectInitializer& ObjInit)
    : Super(ObjInit.SetDefaultSubobjectClass<UTPSCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
    PrimaryActorTick.bCanEverTick = true;

    HealthComponent = CreateDefaultSubobject<UTPSHealthComponent>("HealthComponent");
    WeaponComponent = CreateDefaultSubobject<UTPSWeaponComponent>("WeaponComponent");
}

void ATPSBaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    check(HealthComponent);
    check(GetCharacterMovement());
    check(GetMesh());

    OnHealthChanged(HealthComponent->GetHealth(), 0.0f);
    HealthComponent->OnDeath.AddUObject(this, &ATPSBaseCharacter::OnDeath);
    HealthComponent->OnHealthChanged.AddUObject(this, &ATPSBaseCharacter::OnHealthChanged);

    LandedDelegate.AddDynamic(this, &ATPSBaseCharacter::OnGroundLanded);
}

void ATPSBaseCharacter::OnHealthChanged(float Health, float HealthDelta) {}

void ATPSBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

bool ATPSBaseCharacter::IsRunning() const
{
    return false;
}

float ATPSBaseCharacter::GetMovementDirection() const
{
    if (GetVelocity().IsZero()) return 0.0f;
    const auto VelocityNormal = GetVelocity().GetSafeNormal();
    const auto AngleBetween = FMath::Acos(FVector::DotProduct(GetActorForwardVector(), VelocityNormal));
    const auto CrossProduct = FVector::CrossProduct(GetActorForwardVector(), VelocityNormal);
    return FMath::RadiansToDegrees(AngleBetween) * FMath::Sign(CrossProduct.Z);
}

void ATPSBaseCharacter::OnDeath()
{
    // PlayAnimMontage(DeathAnimMontage);
    GetCharacterMovement()->DisableMovement();
    SetLifeSpan(LifeSpanOnDeath);

    GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    WeaponComponent->StopFire();

    GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    GetMesh()->SetSimulatePhysics(true);
}

void ATPSBaseCharacter::OnGroundLanded(const FHitResult& Hit)
{
    const auto FallVelocityZ = -GetVelocity().Z;

    if (FallVelocityZ < LandedDamageVelocity.X) return;

    const auto FinalDamage = FMath::GetMappedRangeValueClamped(LandedDamageVelocity, LandedDamage, FallVelocityZ);
    TakeDamage(FinalDamage, FDamageEvent{}, nullptr, nullptr);
}

void ATPSBaseCharacter::SetPlayerColor(const FLinearColor& Color)
{
    const auto MaterialInst = GetMesh()->CreateAndSetMaterialInstanceDynamic(0);
    if (!MaterialInst) return;

    MaterialInst->SetVectorParameterValue(MaterialColorName, Color);
}