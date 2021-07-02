// Third Person Shooter Game, All Rights Reserved.

#include "AI/TPSAIController.h"
#include "AI/TPSAICharacter.h"
#include "Components/TPSAIPerceptionComponent.h"

ATPSAIController::ATPSAIController()
{
    TPSAIPerceptionComponent = CreateDefaultSubobject<UTPSAIPerceptionComponent>("TPSPerceptionComponent");
    SetPerceptionComponent(*TPSAIPerceptionComponent);
}

void ATPSAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto TPSCharacter = Cast<ATPSAICharacter>(InPawn);

    if (TPSCharacter)
    {
        RunBehaviorTree(TPSCharacter->BehaviorTreeAsset);
    }
}

 void ATPSAIController::Tick(float DeltaTime) 
 {
     Super::Tick(DeltaTime);
     const auto AimActor = TPSAIPerceptionComponent->GetClosestEnemy();
     SetFocus(AimActor);
 }