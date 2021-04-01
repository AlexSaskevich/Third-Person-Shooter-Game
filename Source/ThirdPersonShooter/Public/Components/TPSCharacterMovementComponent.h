// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TPSCharacterMovementComponent.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API UTPSCharacterMovementComponent : public UCharacterMovementComponent
{
    GENERATED_BODY()
public:
    virtual float GetMaxSpeed() const override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "1.5", ClampMax = "10.0"))
    float RunModifier = 2.0f;
   
};
