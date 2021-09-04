// Third Person Shooter Game, All Rights Reserved.

#include "UI/TPSGameHUD.h"
#include "Engine/Canvas.h"
#include "Blueprint/UserWidget.h"
#include "TPSGameModeBase.h"

DEFINE_LOG_CATEGORY_STATIC(LogTPSGameHUD, All, All);

void ATPSGameHUD::DrawHUD()
{

    Super::DrawHUD();

    //DrawCrossHair();
}

void ATPSGameHUD::BeginPlay() 
{
    Super::BeginPlay();
    auto PlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass);
    if (PlayerHUDWidget)
    {
        PlayerHUDWidget->AddToViewport();
    }

    if (GetWorld())
    {
        const auto GameMode = Cast<ATPSGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &ATPSGameHUD::OnMatchStateChanged);
        }
    }
}

void ATPSGameHUD::OnMatchStateChanged(ETPSMatchState State) 
{
 
    UE_LOG(LogTPSGameHUD, Display, TEXT("Match State Changed: %s"), *UEnum::GetValueAsString(State)); 

}


void ATPSGameHUD::DrawCrossHair()
{
    const TInterval<float> Center(Canvas->SizeX * 0.5f, Canvas->SizeY * 0.5f);

    const float HalfLineSize = 10.0f;
    const float LineThickness = 2.0f;
    const FLinearColor LineColor = FLinearColor::Green;

    DrawLine(Center.Min-HalfLineSize, Center.Max, Center.Min + HalfLineSize, Center.Max, LineColor, LineThickness);
    DrawLine(Center.Min, Center.Max - HalfLineSize, Center.Min, Center.Max + HalfLineSize, LineColor, LineThickness);
}

