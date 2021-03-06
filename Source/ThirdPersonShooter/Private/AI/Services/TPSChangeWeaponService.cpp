// Third Person Shooter Game, All Rights Reserved.

#include "AI/Services/TPSChangeWeaponService.h"
#include "AIController.h"
#include "TPSUtils.h"
#include "Components/TPSWeaponComponent.h"

UTPSChangeWeaponService::UTPSChangeWeaponService()
{
    NodeName = "Change Weapon";
}

void UTPSChangeWeaponService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    const auto Controller = OwnerComp.GetAIOwner();

    if (Controller)
    {
        const auto WeaponComponent = TPSUtils::GetTPSPlayerComponent<UTPSWeaponComponent>(Controller->GetPawn());
        if (WeaponComponent && Probability > 0 && FMath::FRand() <= Probability)
        {
            WeaponComponent->NextWeapon();
        }
    }

    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}