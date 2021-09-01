// Third Person Shooter Game, All Rights Reserved.

#include "Player/TPSPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/TPSWeaponComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATPSPlayerCharacter::ATPSPlayerCharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;
    SpringArmComponent->SocketOffset = FVector(0.0f, 100.0f, 80.0f);

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

    CameraCollisionComponent = CreateDefaultSubobject<USphereComponent>("CameraCollisionComponent");
    CameraCollisionComponent->SetupAttachment(CameraComponent);
    CameraCollisionComponent->SetSphereRadius(10.0f);
    CameraCollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

void ATPSPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    check(CameraCollisionComponent);

    CameraCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATPSPlayerCharacter::OnCameraCollisionBeginOverlap);
    CameraCollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ATPSPlayerCharacter::OnCameraCollisionEndOverlap);
}

void ATPSPlayerCharacter::OnCameraCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    CheckCameraOverlap();
}

void ATPSPlayerCharacter::OnCameraCollisionEndOverlap(
    UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    CheckCameraOverlap();
}

void ATPSPlayerCharacter::CheckCameraOverlap()
{
    const auto HideMesh = CameraCollisionComponent->IsOverlappingComponent(GetCapsuleComponent());
    GetMesh()->SetOwnerNoSee(HideMesh);

    TArray<USceneComponent*> MeshChildren;
    GetMesh()->GetChildrenComponents(true, MeshChildren);

    for (auto MeshChild : MeshChildren)
    {
        const auto MeshChildGeometry = Cast<UPrimitiveComponent>(MeshChild);
        if (MeshChildGeometry)
        {
            MeshChildGeometry->SetOwnerNoSee(HideMesh);
        }
    }
}

void ATPSPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);
    check(WeaponComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ATPSPlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ATPSPlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ATPSPlayerCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("TurnAround", this, &ATPSPlayerCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATPSPlayerCharacter::Jump);
    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ATPSPlayerCharacter::OnStartRunning);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &ATPSPlayerCharacter::OnStopRunning);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &UTPSWeaponComponent::StartFire);
    PlayerInputComponent->BindAction("Fire", IE_Released, WeaponComponent, &UTPSWeaponComponent::StopFire);
    PlayerInputComponent->BindAction("NextWeapon", IE_Pressed, WeaponComponent, &UTPSWeaponComponent::NextWeapon);
    PlayerInputComponent->BindAction("Reload", IE_Pressed, WeaponComponent, &UTPSWeaponComponent::Reload);
}

void ATPSPlayerCharacter::MoveForward(float Amount)
{
    IsMovingForward = Amount > 0.0f;
    if (Amount == 0.0f) return;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ATPSPlayerCharacter::MoveRight(float Amount)
{
    if (Amount == 0.0f) return;
    AddMovementInput(GetActorRightVector(), Amount);
}

void ATPSPlayerCharacter::OnStartRunning()
{
    WantsToRun = true;
}

void ATPSPlayerCharacter::OnStopRunning()
{
    WantsToRun = false;
}

bool ATPSPlayerCharacter::IsRunning() const
{
    return WantsToRun && IsMovingForward && !GetVelocity().IsZero();
}

void ATPSPlayerCharacter::OnDeath()
{
    Super::OnDeath();
    if (Controller)
    {
        Controller->ChangeState(NAME_Spectating);
    }
}
