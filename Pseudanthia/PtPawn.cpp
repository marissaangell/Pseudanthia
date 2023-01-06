// Copyright 2023 Marissa Angell, all rights reserved.


#include "PtPawn.h"

//Enhanced Input System
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputConfigData.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APtPawn::APtPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Set up camera spring arm
    CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

    // Set up camera component
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(CameraSpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void APtPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APtPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APtPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

    /*
    * Enhanced Input setup tutorial - https://nightails.com/2022/10/16/unreal-engine-enhanced-input-system-in-c/
    */

    // Get the player controller
    APlayerController* PC = Cast<APlayerController>(GetController());

    // Get the local player subsystem
    UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

    // Clear out existing mapping, and add our mapping
    InputSubsystem->ClearAllMappings();
    InputSubsystem->AddMappingContext(InputMapping, 0);

    // Get the EnhancedInputComponent
    UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

    // Bind the actions
    EnhancedInputComponent->BindAction(InputConfig->InputMove, ETriggerEvent::Triggered, this, &APtPawn::Move);
    EnhancedInputComponent->BindAction(InputConfig->InputLook, ETriggerEvent::Triggered, this, &APtPawn::Look);

}

void APtPawn::Move(const FInputActionValue& Value)
{
}

void APtPawn::Look(const FInputActionValue& Value)
{
}

