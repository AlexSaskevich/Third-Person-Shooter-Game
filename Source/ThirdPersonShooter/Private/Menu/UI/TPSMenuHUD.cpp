// Third Person Shooter Game, All Rights Reserved.

#include "Menu/UI/TPSMenuHUD.h"
#include "Blueprint/UserWidget.h"

void ATPSMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (MenuWidgetClass)
    {
        const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();
        }
    }
}
