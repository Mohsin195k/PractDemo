// Fill out your copyright notice in the Description page of Project Settings.


#include "PractCharact.h"
#include "Gameframework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Gameframework/CharacterMovementComponent.h"
#include "PractOh1/Public/ObjectInteraction.h"
#include "PractOh1/Public/InteractiveSwitch.h"

// Sets default values
APractCharact::APractCharact()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Main Arm"));
	MainArm->TargetArmLength = 350.f;
	MainArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	MainArm->SetupAttachment(GetRootComponent());
	MainArm->bUsePawnControlRotation = true;
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	MainCamera->SetupAttachment(MainArm, USpringArmComponent::SocketName);
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxComponent->SetupAttachment(GetRootComponent());
	BoxComponent->SetBoxExtent(FVector(30.0f,30.f,30.f));
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &APractCharact::OnBeginOverlap);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &APractCharact::OnEndOverlap);

	InteractionUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("Menu UI"));
	InteractionUI->SetupAttachment(GetRootComponent());
	InteractionUI->SetVisibility(false);
}

// Called when the game starts or when spawned
void APractCharact::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APractCharact::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APractCharact::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APractCharact::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APractCharact::MoveRight);
	PlayerInputComponent->BindAxis("LookVertical", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookHorizontal", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Interaction", IE_Pressed, this, &APractCharact::OnInteraction);
	PlayerInputComponent->BindAction("Escape", IE_Pressed, this, &APractCharact::OnInteractionEnd);
}

void APractCharact::MoveForward(float Axis)
{
	const FRotator CurrentYawRotation = Controller->GetControlRotation();
	const FRotator DesiredYawDirection = FRotator(0.0f, CurrentYawRotation.Yaw, 0.0f);
	const FVector DesiredDirection = FRotationMatrix(DesiredYawDirection).GetUnitAxis(EAxis::X);
	AddMovementInput(DesiredDirection,Axis);
}

void APractCharact::MoveRight(float Axis)
{
	const FRotator CurrentYawRotation = Controller->GetControlRotation();
	const FRotator DesireYawDirection = FRotator(0.0f, CurrentYawRotation.Yaw, 0.0f);
	const FVector DesiredDirection = FRotationMatrix(DesireYawDirection).GetUnitAxis(EAxis::Y);
	AddMovementInput(DesiredDirection, Axis);
}

void APractCharact::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	InteractionInterface = Cast<IObjectInteraction>(OtherActor);
	SwitchObj = Cast<AInteractiveSwitch>(OtherActor);

	if (InteractionInterface)
	{
		InteractionInterface->ShowUI();
	}
}

void APractCharact::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (InteractionInterface)
	{
		InteractionInterface->HideUI();
		InteractionUI->SetVisibility(false);
		InteractionInterface = nullptr;
		SwitchObj = nullptr;
	}
}

void APractCharact::OnInteraction()
{
	if (InteractionInterface)
	{
		InteractionUI->SetVisibility(true);
	}
	if (SwitchObj)
	{
		UE_LOG(LogTemp, Log, TEXT("ASD %s"), *SwitchObj->Data);
	}
}
void APractCharact::OnInteractionEnd()
{
	if (InteractionInterface)
	{
		InteractionUI->SetVisibility(false);
	}
	SwitchObj = nullptr;
}
