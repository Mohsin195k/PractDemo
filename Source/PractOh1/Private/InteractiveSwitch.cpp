// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveSwitch.h"
#include "Components/WidgetComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AInteractiveSwitch::AInteractiveSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Switch Scene"));
	SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Switch Mesh"));
	SwitchMesh->SetupAttachment(GetRootComponent());


	InteractionPrompt = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction Prompt"));
	InteractionPrompt->SetupAttachment(GetRootComponent());
	InteractionPrompt->SetTwoSided(true);
	InteractionPrompt->SetVisibility(0);
}

// Called when the game starts or when spawned
void AInteractiveSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractiveSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AInteractiveSwitch::OnInteract()
{
}

void AInteractiveSwitch::ShowUI()
{
	InteractionPrompt->SetVisibility(1);
}

void AInteractiveSwitch::HideUI()
{
	InteractionPrompt->SetVisibility(0);
}

void AInteractiveSwitch::GetData()
{
}

