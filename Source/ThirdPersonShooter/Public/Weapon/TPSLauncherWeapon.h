// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/TPSBaseWeapon.h"
#include "TPSLauncherWeapon.generated.h"

class ATPSProjectile;
class USoundCue;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSLauncherWeapon : public ATPSBaseWeapon
{
    GENERATED_BODY()

public:
    virtual void StartFire() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<ATPSProjectile> ProjectileClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* NoAmmoSound;

    virtual void MakeShot() override;

};
