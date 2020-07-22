// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components\StaticMeshComponent.h"
#include "GameFramework\SpringArmComponent.h"
#include "Camera\CameraComponent.h"
#include "Ball.generated.h"

UCLASS()
class COIN_API ABall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABall();
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* MyRootComponent = nullptr;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BallComponent = nullptr;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent = nullptr;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "MyVariables")
	FVector force;

	FVector velocity;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float Value);
	UFUNCTION()
	void MoveRight(float Value);
	
};
