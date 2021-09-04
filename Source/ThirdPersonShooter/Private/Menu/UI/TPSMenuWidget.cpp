// Third Person Shooter Game, All Rights Reserved.

#include "Menu/UI/TPSMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

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
    const FName StartupLevelName = "TestLevel";
    UGameplayStatics::OpenLevel(this, StartupLevelName);
}