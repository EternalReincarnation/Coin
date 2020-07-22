// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//根组件
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//创建球、弹簧臂、相机组件
	BallComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallComponent"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	
	//将球、弹簧臂、相机按层次挂好
	BallComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArmComponent);

	//开启小球物理模拟
	BallComponent->SetSimulatePhysics(true);
	//设置相机位置和选择角度
	CameraComponent->SetRelativeLocation(FVector(-350.0f, 0.0f, 350.0f));
	CameraComponent->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	force = FVector(0);
	//初始玩家控制
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
	//BallComponent->AddForce(force);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
	//BallComponent->SetRelativeLocation(BallComponent->GetRelativeTransform().GetLocation() + CurrentVelocity);
}

// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABall::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABall::MoveRight);
	
}

void ABall::MoveForward(float Value)
{
	//velocity.X = Value * 1000.0f;
	BallComponent->AddForce(FVector(Value*30000.f,0,0));
}

void ABall::MoveRight(float Value)
{
	//velocity.Y = Value * 1000.0f;
	BallComponent->AddForce(FVector(0, Value*30000.f,0));
}