// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TPSWeaponComponent.h"
#include "TPSAIWeaponComponent.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API UTPSAIWeaponComponent : public UTPSWeaponComponent
{
    GENERATED_BODY()
public:
    virtual void StartFire() override;
    virtual void NextWeapon() override;
};
