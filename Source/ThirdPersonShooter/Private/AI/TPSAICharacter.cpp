// Third Person Shooter Game, All Rights Reserved.

#include "AI/TPSAICharacter.h"
#include "AI/TPSAIController.h"

ATPSAICharacter::ATPSAICharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorld;
    AIControllerClass = ATPSAIController::StaticClass();
}