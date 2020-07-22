// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldenCoin.h"
#include "Delegates\Delegate.h"
#include "Engine\Public\TimerManager.h"
#include "Ball.h"

// Sets default values
AGoldenCoin::AGoldenCoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//根组件
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	GoldenCoinComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GoldenCoinComponent"));
	GoldenCoinComponent->SetupAttachment(RootComponent);
	//GoldenCoinComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	//GoldenCoinComponent->OnComponentBeginOverlap.AddDynamic(this, &AGoldenCoin::BeginOverlap);
	OnActorBeginOverlap.AddDynamic(this, &AGoldenCoin::OnOverlap);
	
}

// Called when the game starts or when spawned
void AGoldenCoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoldenCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += 5.0f;
	//AddActorLocalRotation(NewRotation);
	SetActorRotation(NewRotation);*/

	AddActorLocalRotation(FRotator(0, 100.0f * DeltaTime, 0));

}

/*void AGoldenCoin::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	// Overlap
}*/

void AGoldenCoin::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//将OtherActor转化为球类实例
	if (Cast<ABall>(OtherActor) != nullptr)
	{
		GetWorldTimerManager().SetTimer(MyInOutHandle, this, &AGoldenCoin::DestroyCoin, 1.0f, false);
	}
}

void AGoldenCoin::DestroyCoin()
{
	Destroy();
}