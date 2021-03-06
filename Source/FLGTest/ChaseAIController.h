// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ChaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class FLGTEST_API AChaseAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AChaseAIController();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* pawn) override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere)
	class UPawnSensingComponent* pawnSensingComponent;

	UPROPERTY(VisibleAnywhere)
	class AChaser* chaser;

	UPROPERTY(VisibleAnywhere)
	FVector nextLoc;

	UPROPERTY(VisibleAnywhere)
	FVector savedLocation;

	UFUNCTION()
	void OnSeePlayer(APawn* detectedPawn);

	UFUNCTION()
	void SetNextLocation();

	UFUNCTION()
	void ReturnToLastLocation();

	void OnMoveCompleted(FAIRequestID requestID, const FPathFollowingResult& result) override;

private:
	UPROPERTY(VisibleAnywhere)
	FTimerHandle timerHandle;
};
