// Third Person Shooter Game, All Rights Reserved.

#include "AI/Decorators/TPSHEalthPercentDecorator.h"
#include "AIController.h"
#include "TPSUtils.h"
#include "Components/TPSHealthComponent.h"

UTPSHEalthPercentDecorator::UTPSHEalthPercentDecorator()
{
    NodeName = "Health Percent";
}

bool UTPSHEalthPercentDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;

    const auto HealthComponent = TPSUtils::GetTPSPlayerComponent<UTPSHealthComponent>(Controller->GetPawn());
    if (!HealthComponent || HealthComponent->IsDead()) return false;
    
    return HealthComponent->GetHealthPercent() <= HealthPercent;
}