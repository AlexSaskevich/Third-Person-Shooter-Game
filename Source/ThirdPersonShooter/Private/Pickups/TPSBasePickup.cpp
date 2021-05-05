// Third Person Shooter Game, All Rights Reserved.

#include "Pickups/TPSBasePickup.h"
#include "Components/SphereComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBasePickup, Display, Display);

ATPSBasePickup::ATPSBasePickup()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);
}

void ATPSBasePickup::BeginPlay()
{
    Super::BeginPlay();
}

void ATPSBasePickup::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATPSBasePickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    UE_LOG(LogBasePickup, Display, TEXT("Pickup was taken"));
    Destroy();
}