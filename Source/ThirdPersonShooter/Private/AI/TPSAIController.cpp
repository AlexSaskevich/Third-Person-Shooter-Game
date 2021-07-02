// Third Person Shooter Game, All Rights Reserved.

#include "AI/TPSAIController.h"
#include "AI/TPSAICharacter.h"

void ATPSAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto TPSCharacter = Cast<ATPSAICharacter>(InPawn);

    if (TPSCharacter)
    {
        RunBehaviorTree(TPSCharacter->BehaviorTreeAsset);
    }
}
