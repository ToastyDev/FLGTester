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

	pawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing Component"));
	pawnSensingComponent->bHearNoises = false;

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

}

// Called when the game starts or when spawned
void AChaser::BeginPlay()
{
	Super::BeginPlay();

	pawnSensingComponent->SetPeripheralVisionAngle(peripheralVisionAngle);
	pawnSensingComponent->SightRadius = sightRange;
	
	pawnSensingComponent->OnSeePawn.AddDynamic(this, &AChaser::OnSeePlayer);

	SetWanderState();

	bIsAtDestination = false;
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

void AChaser::OnSeePlayer(APawn* pawn)
{
	SetChaseState();
}

void AChaser::WalkToPoint(FVector location)
{
	//go to given point
	chaseAIController->MoveToLocation(location);
	/*if (GetActorLocation() == location)
	{
		bIsAtDestination = true;
		FVector newLocation = FVector(FMath::VRand());
		bIsAtDestination = false;
		WalkToPoint(newLocation);
	}*/
}

void AChaser::SetChaseState()
{
	//set last location for save
	if (currentMode == Mode::WANDER)
	{
		savedLocation = GetActorLocation();
	}
	currentMode = Mode::CHASE;
	GetCharacterMovement()->MaxWalkSpeed = chaseSpeed;
	bIsAtDestination = false;
}

void AChaser::SetRetreatState()
{
	currentMode = Mode::RETREAT;
	//grab last chase location
}

void AChaser::SetWanderState()
{
	currentMode = Mode::WANDER;
	GetCharacterMovement()->MaxWalkSpeed = wanderSpeed;
}