// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPSCoreTypes.h"
#include "TPSGameModeBase.generated.h"

class AAIController;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    ATPSGameModeBase();

    virtual void StartPlay() override;
    virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<AAIController> AIControllerClass;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<APawn> AIPawnClass;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FGameData GameData;

private:
    void SpawnBots();
};
