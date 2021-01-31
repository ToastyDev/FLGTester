// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaser.h"
#include "Perception/PawnSensingComponent.h" 
#include "GameFramework/CharacterMovementComponent.h"
#include "ChaseAIController.h"

// Sets default values
AChaser::AChaser()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	currentMode = Mode::WANDER;

}

// Called when the game starts or when spawned
void AChaser::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AChaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AChaser::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AChaser::SetChaseState()
{
	currentMode = Mode::CHASE;
	GetCharacterMovement()->MaxWalkSpeed = chaseSpeed;
}

void AChaser::SetRetreatState()
{
	currentMode = Mode::RETREAT;
	chaseAIController->SetNextLocation();
}

void AChaser::SetWanderState()
{
	currentMode = Mode::WANDER;
	GetCharacterMovement()->MaxWalkSpeed = wanderSpeed;
}
