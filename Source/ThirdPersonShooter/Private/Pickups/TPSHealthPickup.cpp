// Third Person Shooter Game, All Rights Reserved.

#include "Pickups/TPSHealthPickup.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, Display, Display);

bool ATPSHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
    UE_LOG(LogHealthPickup, Display, TEXT("Health was taken"));
    return true;
}
