// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/TPSBasePickup.h"
#include "TPSHealthPickup.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API ATPSHealthPickup : public ATPSBasePickup
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "100.0"))
    int32 HealthAmount = 100.0f;

private:
    virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
