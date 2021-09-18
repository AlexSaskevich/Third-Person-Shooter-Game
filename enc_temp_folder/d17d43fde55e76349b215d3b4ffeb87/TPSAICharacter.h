// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/TPSBaseCharacter.h"
#include "TPSAICharacter.generated.h"

class UBehaviorTree;
class UWidgetComponent;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSAICharacter : public ATPSBaseCharacter
{
    GENERATED_BODY()

public:
    ATPSAICharacter(const FObjectInitializer& ObjInit);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UWidgetComponent* HealthWidgetComponent;

    virtual void BeginPlay() override;

    virtual void OnDeath() override;
    virtual void OnHealthChanged(float Health, float HealthDelta) override;
};
