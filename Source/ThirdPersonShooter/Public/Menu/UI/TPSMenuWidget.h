// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/TPSBaseWidget.h"
#include "TPSCoreTypes.h"
#include "TPSMenuWidget.generated.h"

class UButton;
class UHorizontalBox;
class UTPSGameInstance;
class UTPSLevelItemWidget;

UCLASS()
class THIRDPERSONSHOOTER_API UTPSMenuWidget : public UTPSBaseWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* StartGameButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitGameButton;

    UPROPERTY(meta = (BindWidget))
    UHorizontalBox* LevelItemsBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> LevelItemWidgetClass;

    virtual void NativeOnInitialized() override;

private:
    UPROPERTY()
    TArray<UTPSLevelItemWidget*> LevelItemWidgets;

    UFUNCTION()
    void OnStartGame();

    UFUNCTION()
    void OnQuitGame();

    void InitLevelItems();
    void OnLevelSelected(const FLevelData& Data);
    UTPSGameInstance* GetTPSGameInstance() const;
};
