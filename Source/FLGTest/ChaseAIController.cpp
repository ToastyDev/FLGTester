// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseAIController.h"
#include "Chaser.h"
#include "FLGTestCharacter.h"
#include "Math/Vector.h"
#include "Perception/PawnSensingComponent.h" 

AChaseAIController::AChaseAIController()
{
	pawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing Component"));
	pawnSensingComponent->bHearNoises = false;
}

void AChaseAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AChaseAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	chaser = Cast<AChaser>(GetPawn());

	pawnSensingComponent->SetPeripheralVisionAngle(chaser->peripheralVisionAngle);
	pawnSensingComponent->SightRadius = chaser->sightRange;

	pawnSensingComponent->OnSeePawn.AddDynamic(this, &AChaseAIController::OnSeePlayer);

	SetNextLocation();
}

void AChaseAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AChaseAIController::OnSeePlayer(APawn* detectedPawn)
{
		AFLGTestCharacter* playerCharacter = Cast<AFLGTestCharacter>(detectedPawn);
		if (playerCharacter == nullptr)
		{
			return;
		}

		savedLocation = chaser->GetActorLocation();
		chaser->SetChaseState();
		MoveToActor(playerCharacter);
		UE_LOG(LogTemp, Warning, TEXT("PLAYER DETECTED!"));
	
}

void AChaseAIController::SetNextLocation()
{
		FVector nextLoc;
		nextLoc.X = FMath::FRandRange(-1500, 1500);
		nextLoc.Y = FMath::FRandRange(-1500, 1500);
		nextLoc.Z = FMath::FRandRange(0, 400);
		MoveToLocation(nextLoc);
		UE_LOG(LogTemp, Warning, TEXT("Moving to %s"), *nextLoc.ToString());	
}

void AChaseAIController::OnMoveCompleted(FAIRequestID requestID, const FPathFollowingResult & result)
{
	Super::OnMoveCompleted(requestID, result);

	GetWorldTimerManager().SetTimer(timerHandle, this, &AChaseAIController::SetNextLocation, chaser->nextMoveDelay, false);
}

void AChaseAIController::ReturnToLastLocation()
{
	MoveToLocation(savedLocation);
	savedLocation = FVector::ZeroVector;
}