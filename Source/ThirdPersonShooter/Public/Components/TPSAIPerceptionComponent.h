// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "TPSAIPerceptionComponent.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API UTPSAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()
public:
    AActor* GetClosestEnemy() const;
};
