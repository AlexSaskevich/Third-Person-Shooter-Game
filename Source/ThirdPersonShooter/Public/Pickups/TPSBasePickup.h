// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TPSBasePickup.generated.h"

class USphereComponent;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSBasePickup : public AActor
{
    GENERATED_BODY()

public:
    ATPSBasePickup();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Pickup")
    USphereComponent* CollisionComponent;

    virtual void BeginPlay() override;
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
    virtual void Tick(float DeltaTime) override;
};
