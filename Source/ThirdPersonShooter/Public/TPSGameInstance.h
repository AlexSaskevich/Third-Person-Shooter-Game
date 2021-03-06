// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TPSCoreTypes.h"
#include "TPSGameInstance.generated.h"

class USoundClass;

UCLASS()
class THIRDPERSONSHOOTER_API UTPSGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    FLevelData GetStartupLevel() const { return StartupLevel; }
    void SetStartupLevel(const FLevelData& Data) { StartupLevel = Data; }

    TArray<FLevelData> GetLevelsData() const { return LevelsData; }

    FName GetMenuLevelName() const { return MenuLevelName; }

    void ToggleVolume();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game", meta = (ToolTip = "Level names must be unique!"))
    TArray<FLevelData> LevelsData;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FName MenuLevelName = NAME_None;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    USoundClass* MasterSoundClass;

private:
    FLevelData StartupLevel;
};
