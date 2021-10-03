// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TPSGameDataWidget.generated.h"

class ATPSGameModeBase;

class ATPSPlayerState;

UCLASS()
class THIRDPERSONSHOOTER_API UTPSGameDataWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetCurrentRoundNum() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetTotalRoundNum() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetRoundSecondsRemaining() const;

private:
    ATPSGameModeBase* GetTPSGameMode() const;

    ATPSPlayerState* GetTPSPlayerState() const;
};
