// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "TPSHEalthPercentDecorator.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API UTPSHEalthPercentDecorator : public UBTDecorator
{
    GENERATED_BODY()

public:
    UTPSHEalthPercentDecorator();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float HealthPercent = 0.6f;

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
