// Third Person Shooter Game, All Rights Reserved.

#include "Menu/TPSMenuPlayerController.h"

void ATPSMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}