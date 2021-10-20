// Third Person Shooter Game, All Rights Reserved.

#include "Weapon/TPSLauncherWeapon.h"
#include "Weapon/TPSProjectile.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

void ATPSLauncherWeapon::StartFire()
{
    MakeShot();
}

void ATPSLauncherWeapon::MakeShot()
{
    if (!GetWorld()) return;

    if (IsAmmoEmpty())
    {
        UGameplayStatics::SpawnSoundAtLocation(GetWorld(), NoAmmoSound, GetActorLocation());
        return;
    }

    FVector TraceStart, TraceEnd;
    if (!GetTraceData(TraceStart, TraceEnd)) return;

    FHitResult HitResult;
    MakeHit(HitResult, TraceStart, TraceEnd);

    const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
    const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();

    const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
    ATPSProjectile* Projectile = GetWorld()->SpawnActorDeferred<ATPSProjectile>(ProjectileClass, SpawnTransform);
    if (Projectile)
    {
        Projectile->SetShotDirection(Direction);
        Projectile->SetOwner(GetOwner());
        Projectile->FinishSpawning(SpawnTransform);
    }

    DecreaseAmmo();
    SpawnMuzzleFX();
    UGameplayStatics::SpawnSoundAttached(FireSound, WeaponMesh, MuzzleSocketName);
}
