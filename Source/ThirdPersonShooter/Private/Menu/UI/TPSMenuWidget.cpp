// Third Person Shooter Game, All Rights Reserved.

#include "Menu/UI/TPSMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "TPSGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/HorizontalBox.h"
#include "Menu/UI/TPSLevelItemWidget.h"
DEFINE_LOG_CATEGORY_STATIC(LogTPSMenuWidget, All, All);

void UTPSMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UTPSMenuWidget::OnStartGame);
    }

    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &UTPSMenuWidget::OnQuitGame);
    }

    InitLevelItems();
}

void UTPSMenuWidget::InitLevelItems()
{
    const auto TPSGameInstance = GetTPSGameInstance();
    if (!TPSGameInstance) return;

    checkf(TPSGameInstance->GetLevelsData().Num() != 0, TEXT("Levels data must not be empty!"));

    if (!LevelItemsBox) return;
    LevelItemsBox->ClearChildren();

    for (auto LevelData : TPSGameInstance->GetLevelsData())
    {
        const auto LevelItemWidget = CreateWidget<UTPSLevelItemWidget>(GetWorld(), LevelItemWidgetClass);
        if (!LevelItemWidget) continue;

        LevelItemWidget->SetLevelData(LevelData);
        LevelItemWidget->OnLevelSelected.AddUObject(this, &UTPSMenuWidget::OnLevelSelected);

        LevelItemsBox->AddChild(LevelItemWidget);
        LevelItemWidgets.Add(LevelItemWidget);
    }

    if (TPSGameInstance->GetStartupLevel().LevelName.IsNone())
    {
        OnLevelSelected(TPSGameInstance->GetLevelsData()[0]);
    }
    else
    {
        OnLevelSelected(TPSGameInstance->GetStartupLevel());
    }
}
void UTPSMenuWidget::OnLevelSelected(const FLevelData& Data)
{
    const auto TPSGameInstance = GetTPSGameInstance();
    if (!TPSGameInstance) return;

    TPSGameInstance->SetStartupLevel(Data);

    for (auto LevelItemWidget : LevelItemWidgets)
    {
        if (LevelItemWidget)
        {
            const auto IsSelected = Data.LevelName == LevelItemWidget->GetLevelData().LevelName;
            LevelItemWidget->SetSelected(IsSelected);
        }
    }
}

void UTPSMenuWidget::OnStartGame()
{
    PlayAnimation(HideAnimation);
}

void UTPSMenuWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
    if (Animation != HideAnimation) return;

    const auto TPSGameInstance = GetTPSGameInstance();
    if (!TPSGameInstance) return;

    UGameplayStatics::OpenLevel(this, TPSGameInstance->GetStartupLevel().LevelName);
}

void UTPSMenuWidget::OnQuitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

UTPSGameInstance* UTPSMenuWidget::GetTPSGameInstance() const
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->GetGameInstance<UTPSGameInstance>();
}