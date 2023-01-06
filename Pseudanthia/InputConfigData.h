// Copyright 2023 Marissa Angell, all rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "InputAction.h"

#include "InputConfigData.generated.h"

/**
 * Store pointers to Input Actions for native binding
 * Written with the help of this tutorial: https://nightails.com/2022/10/16/unreal-engine-enhanced-input-system-in-c/
*/
UCLASS()
class PSEUDANTHIA_API UInputConfigData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UInputAction* InputMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UInputAction* InputLook;
};