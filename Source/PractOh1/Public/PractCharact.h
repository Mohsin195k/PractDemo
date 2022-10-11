// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PractCharact.generated.h"

UCLASS()
class PRACTOH1_API APractCharact : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APractCharact();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Character Visuals")
	UStaticMeshComponent* BoxMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Visuals")
	class UBoxComponent* BoxCollision;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Visuals")
	class UCameraComponent* MainCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Visuals")
	class USpringArmComponent* MainArm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Visuals")
		class UBoxComponent* BoxComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widget Visuals")
	class UWidgetComponent* InteractionUI;

	class  AInteractiveSwitch* SwitchObj = nullptr;
	class IObjectInteraction* InteractionInterface=nullptr;

	UFUNCTION(BlueprintCallable)
		void MoveForward(float Axis);

	UFUNCTION(BlueprintCallable)
		void MoveRight(float Axis);

	UFUNCTION(BlueprintCallable)
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable)
		void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
		void OnInteraction();


	UFUNCTION(BlueprintCallable)
		void OnInteractionEnd();

};
