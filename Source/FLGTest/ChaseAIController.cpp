// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseAIController.h"
#include "Chaser.h"
#include "Math/Vector.h"

AChaseAIController::AChaseAIController()
{

}

void AChaseAIController::BeginPlay()
{
	Super::BeginPlay();

	chaser = Cast<AChaser>(GetPawn());
	SetNextLocation();
}

void AChaseAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
}

void AChaseAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AChaseAIController::SetNextLocation()
{
	if (chaser->savedLocation != FVector::ZeroVector)
	{
		MoveToLocation(chaser->savedLocation);
		chaser->savedLocation = FVector::ZeroVector;
	}
	else
	{
		FVector nextLoc;
		nextLoc.X = FMath::FRandRange(-1500, 1500);
		nextLoc.Y = FMath::FRandRange(-1500, 1500);
		nextLoc.Z = FMath::FRandRange(0, 400);
		MoveToLocation(nextLoc);
		UE_LOG(LogTemp, Warning, TEXT("Moving to %s"), *nextLoc.ToString());
	}
}

void AChaseAIController::OnMoveCompleted(FAIRequestID requestID, const FPathFollowingResult & result)
{
	Super::OnMoveCompleted(requestID, result);

	GetWorldTimerManager().SetTimer(timerHandle, this, &AChaseAIController::SetNextLocation, chaser->nextMoveDelay, false);
}

