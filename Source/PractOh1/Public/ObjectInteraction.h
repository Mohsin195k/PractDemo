// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ObjectInteraction.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UObjectInteraction : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PRACTOH1_API IObjectInteraction
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void OnInteract() {}
	virtual void ShowUI() {}
	virtual void HideUI() {}
	virtual void GetData() {}
};
