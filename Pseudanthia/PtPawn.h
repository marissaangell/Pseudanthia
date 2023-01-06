// Copyright 2023 Marissa Angell, all rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "PtPawn.generated.h"

UCLASS()
class PSEUDANTHIA_API APtPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APtPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



#pragma region Input

	/*
	* Enhanced Input setup tutorial - https://nightails.com/2022/10/16/unreal-engine-enhanced-input-system-in-c/
	*/

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputConfigData* InputConfig;

public: 
	// Handle move input
	void Move(const FInputActionValue& Value);

	// Handle look input
	void Look(const FInputActionValue& Value);

#pragma endregion 

#pragma region Components

protected:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraSpringArm;

	/** Main Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

#pragma endregion

};
