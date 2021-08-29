// Third Person Shooter Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/TPSBaseCharacter.h"
#include "TPSPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSPlayerCharacter : public ATPSBaseCharacter
{
    GENERATED_BODY()

public:
    ATPSPlayerCharacter(const FObjectInitializer& ObjInit);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    virtual void OnDeath() override;

public:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual bool IsRunning() const override;

private:
    bool WantsToRun = false;
    bool IsMovingForward = false;

    void MoveForward(float Amount);
    void MoveRight(float Amount);

    void OnStartRunning();
    void OnStopRunning();
};
