// Third Person Shooter Game, All Rights Reserved.

#include "UI/TPSPauseWidget.h"
#include "Gameframework/GameModeBase.h"
#include "Components/Button.h"

bool UTPSPauseWidget::Initialize()
{
    const auto InitStatus = Super::Initialize();
    if (ClearPauseButton)
    {
        ClearPauseButton->OnClicked.AddDynamic(this, &UTPSPauseWidget::OnClearPause);
    }

    return InitStatus;
}

void UTPSPauseWidget::OnClearPause()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->ClearPause();
}
