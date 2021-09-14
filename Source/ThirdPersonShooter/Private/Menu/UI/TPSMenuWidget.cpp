// Third Person Shooter Game, All Rights Reserved.

#include "Menu/UI/TPSMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "TPSGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogTPSMenuWidget, All, All);

void UTPSMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UTPSMenuWidget::OnStartGame);
    }
}

void UTPSMenuWidget::OnStartGame()
{
    if (!GetWorld()) return;

    const auto TPSGameInstance = GetWorld()->GetGameInstance<UTPSGameInstance>();
    if (!TPSGameInstance) return;

    if (TPSGameInstance->GetStartupLevelName().IsNone())
    {
        UE_LOG(LogTPSMenuWidget, Error, TEXT("Level name is NONE"));
        return;
    }

    UGameplayStatics::OpenLevel(this, TPSGameInstance->GetStartupLevelName());
}