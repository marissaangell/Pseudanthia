// Fill out your copyright notice in the Description page of Project Settings.


#include "PtPawn.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
//#include "EnhancedInputComponent.h"

// Sets default values
APtPawn::APtPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    /*
    * Enhanced Input System setup - https://docs.unrealengine.com/4.26/en-US/InteractiveExperiences/Input/EnhancedInput/
    */
    // Make sure that we are using a UEnhancedInputComponent; if not, the project is not configured correctly.
    //if (UEnhancedInputComponent* PlayerEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    //{
    //    // There are ways to bind a UInputAction* to a handler function and multiple types of ETriggerEvent that may be of interest.

    //    // This calls the handler function on the tick when MyInputAction starts, such as when pressing an action button.
    //    //if (MyInputAction)
    //    //{
    //    //    PlayerEnhancedInputComponent->BindAction(MyInputAction, ETriggerEvent::Started, this, &AMyPawn::MyInputHandlerFunction);
    //    //}

    //    //// This calls the handler function (a UFUNCTION) by name on every tick while the input conditions are met, such as when holding a movement key down.
    //    //if (MyOtherInputAction)
    //    //{
    //    //    PlayerEnhancedInputComponent->BindAction(MyOtherInputAction, ETriggerEvent::Triggered, this, TEXT("MyOtherInputHandlerFunction"));
    //    //}
    //}

    // Get the player controller
    APlayerController* PC = Cast<APlayerController>(GetController());

    // Get the local player subsystem
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
    // Clear out existing mapping, and add our mapping
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(InputMapping, 0);

}

