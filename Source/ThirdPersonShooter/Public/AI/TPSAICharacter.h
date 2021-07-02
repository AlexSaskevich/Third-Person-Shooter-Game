// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/TPSBaseCharacter.h"
#include "TPSAICharacter.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API ATPSAICharacter : public ATPSBaseCharacter
{
    GENERATED_BODY()

public:
    ATPSAICharacter(const FObjectInitializer& ObjInit);
};
