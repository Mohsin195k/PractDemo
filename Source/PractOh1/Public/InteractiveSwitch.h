// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PractOh1/Public/ObjectInteraction.h"
#include "InteractiveSwitch.generated.h"

UCLASS()
class PRACTOH1_API AInteractiveSwitch : public AActor, public IObjectInteraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractiveSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Switch Variables")
	UStaticMeshComponent* SwitchMesh;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Variables")
	class UWidgetComponent* InteractionPrompt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Variables")
	FString Data = "XYZ";
	void OnInteract() override;
	void ShowUI() override;
	void HideUI() override;
	void GetData() override;
};
