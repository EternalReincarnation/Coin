// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components\StaticMeshComponent.h"
#include "GoldenCoin.generated.h"

UCLASS(Blueprintable)
class COIN_API AGoldenCoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoldenCoin();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* MyRootComponent = NULL;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* GoldenCoinComponent = NULL;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle MyInOutHandle;
	void DestroyCoin();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/*UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);*/
	UFUNCTION()
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
